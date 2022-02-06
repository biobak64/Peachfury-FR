#include <PR/ultratypes.h>

#include "sm64.h"
#include "level_update.h"
#include "memory.h"
#include "engine/math_util.h"
#include "area.h"
#include "save_file.h"
#include "sound_init.h"
#include "engine/surface_collision.h"
#include "interaction.h"
#include "mario.h"
#include "mario_step.h"
#include "camera.h"
#include "audio/external.h"
#include "behavior_data.h"
#include "level_table.h"
#include "thread6.h"
#include "OPT_FOR_SIZE.h"

#define MIN_SWIM_STRENGTH 160
#define MIN_SWIM_SPEED 16.0f

static s16 sWasAtSurface = FALSE;
static s16 sSwimStrength = MIN_SWIM_STRENGTH;
static s16 sWaterCurrentSpeeds[] = { 28, 12, 8, 4 };

static s16 D_80339FD0;
static s16 D_80339FD2;
static f32 D_80339FD4;

static void set_swimming_at_surface_particles(struct MarioState *m, u32 particleFlag) {
    s16 atSurface = m->pos[1] >= m->waterLevel - 130;

    if (atSurface) {
        m->particleFlags |= particleFlag;
        if (atSurface ^ sWasAtSurface) {
            play_sound(SOUND_ACTION_UNKNOWN431, m->marioObj->header.gfx.cameraToObject);
        }
    }

    sWasAtSurface = atSurface;
}

static s32 swimming_near_surface(struct MarioState *m) {

    return (m->waterLevel - 80) - m->pos[1] < 400.0f;
}

static f32 get_buoyancy(struct MarioState *m) {
    f32 buoyancy = 0.0f;
    if (swimming_near_surface(m)) {
        buoyancy = 1.25f;
    } else if (!(m->action & ACT_FLAG_MOVING)) {
        buoyancy = -2.0f;
    }

    return buoyancy;
}

static u32 perform_water_full_step(struct MarioState *m, Vec3f nextPos) {
    struct Surface *wall;
    struct Surface *ceil;
    struct Surface *floor;
    f32 ceilHeight;
    f32 floorHeight;

    wall = resolve_and_return_wall_collisions(nextPos, 10.0f, 110.0f);
    floorHeight = find_floor(nextPos[0], nextPos[1], nextPos[2], &floor);
    ceilHeight =
        vec3f_find_ceil(nextPos, nextPos[1], &ceil); // kazefix can this be buggy? maybe use nextpos[1]?

    if (floor == NULL) {
        return WATER_STEP_CANCELLED;
    }

    vec3f_copy(m->pos, nextPos);
    if (nextPos[1] >= floorHeight) {
        if (ceilHeight - nextPos[1] >= 160.0f) {
            m->floor = floor;
            m->floorHeight = floorHeight;

            if (wall != NULL) {
                return WATER_STEP_HIT_WALL;
            } else {
                return WATER_STEP_NONE;
            }
        }

        /*if (ceilHeight - floorHeight < 160.0f) {
            return WATER_STEP_CANCELLED;
        }*/

        //! Water ceiling downwarp
        // vec3f_set(m->pos, nextPos[0], ceilHeight - 160.0f, nextPos[2]);
        m->floor = floor;
        m->floorHeight = floorHeight;
        return WATER_STEP_HIT_CEILING;
    } else {
        /* if (ceilHeight - floorHeight < 160.0f) {
             return WATER_STEP_CANCELLED;
         }*/

        vec3f_set(m->pos, nextPos[0], floorHeight, nextPos[2]);
        m->floor = floor;
        m->floorHeight = floorHeight;
        return WATER_STEP_HIT_FLOOR;
    }
}

static void apply_water_current(struct MarioState *m, Vec3f step) {
    s32 i;
    f32 whirlpoolRadius = 2000.0f;

    if (SURFACETYPE(m->floor) == SURFACE_FLOWING_WATER) {
        s16 currentAngle = m->floor->force << 8;
        f32 currentSpeed = sWaterCurrentSpeeds[m->floor->force >> 8];

        step[0] += currentSpeed * sins(currentAngle);
        step[2] += currentSpeed * coss(currentAngle);
    }

    for (i = 0; i < 2; i++) {
        struct Whirlpool *whirlpool = gCurrentArea->whirlpools[i];
        if (whirlpool != NULL) {
            f32 strength = 0.0f;

            f32 dx = whirlpool->pos[0] - m->pos[0];
            f32 dy = whirlpool->pos[1] - m->pos[1];
            f32 dz = whirlpool->pos[2] - m->pos[2];

            f32 lateralDist = sqrtf(dx * dx + dz * dz);
            f32 distance = sqrtf(lateralDist * lateralDist + dy * dy);

            s16 pitchToWhirlpool = atan2s(lateralDist, dy);
            s16 yawToWhirlpool = atan2s(dz, dx);

            yawToWhirlpool -= (s16) (0x2000 * 1000.0f / (distance + 1000.0f));

            if (whirlpool->strength >= 0) {
                if (gCurrLevelNum == LEVEL_DDD && gCurrAreaIndex == 2) {
                    whirlpoolRadius = 4000.0f;
                }

                if (distance >= 26.0f && distance < whirlpoolRadius) {
                    strength = whirlpool->strength * (1.0f - distance / whirlpoolRadius);
                }
            } else if (distance < 2000.0f) {
                strength = whirlpool->strength * (1.0f - distance / 2000.0f);
            }

            step[0] += strength * coss(pitchToWhirlpool) * sins(yawToWhirlpool);
            step[1] += strength * sins(pitchToWhirlpool);
            step[2] += strength * coss(pitchToWhirlpool) * coss(yawToWhirlpool);
        }
    }
}

extern void clip_mario(Vec3f prev_pos, Vec3f new_pos, struct Surface **hit_surface,
                       struct MarioState *m);
static u32 perform_water_step(struct MarioState *m) {
    u32 stepResult;
    Vec3f nextPos;
    Vec3f step;
    struct Object *marioObj = m->marioObj;
    Vec3f priorPos;
    struct Surface *hit_surface;

    priorPos[0] = m->pos[0];
    priorPos[1] = m->pos[1];
    priorPos[2] = m->pos[2];

    vec3f_copy(step, m->vel);

    if (m->action & ACT_FLAG_SWIMMING) {
        apply_water_current(m, step);
    }

    nextPos[0] = m->pos[0] + step[0];
    nextPos[1] = m->pos[1] + step[1];
    nextPos[2] = m->pos[2] + step[2];

    if (nextPos[1] > m->waterLevel - 80) {
        nextPos[1] = m->waterLevel - 80;
        m->vel[1] = 0.0f;
    }

    stepResult = perform_water_full_step(m, nextPos);
    clip_mario(priorPos, m->pos, &hit_surface, m);

    vec3f_copy(marioObj->header.gfx.pos, m->pos);
    vec3s_set(marioObj->header.gfx.angle, -m->faceAngle[0], m->faceAngle[1], m->faceAngle[2]);

    return stepResult;
}

static BAD_RETURN(u32) update_water_pitch(struct MarioState *m) {
    struct Object *marioObj = m->marioObj;

    if (marioObj->header.gfx.angle[0] > 0) {
        marioObj->header.gfx.pos[1] +=
            60.0f * sins(marioObj->header.gfx.angle[0]) * sins(marioObj->header.gfx.angle[0]);
    }

    if (marioObj->header.gfx.angle[0] < 0) {
        marioObj->header.gfx.angle[0] = marioObj->header.gfx.angle[0] * 6 / 10;
    }

    if (marioObj->header.gfx.angle[0] > 0) {
        marioObj->header.gfx.angle[0] = marioObj->header.gfx.angle[0] * 10 / 8;
    }
}

static void stationary_slow_down(struct MarioState *m) {
    f32 buoyancy = get_buoyancy(m);

    m->angleVel[0] = 0;
    m->angleVel[1] = 0;

    m->forwardVel = approach_f32(m->forwardVel, 0.0f, 1.0f, 1.0f);
    m->vel[1] = approach_f32(m->vel[1], buoyancy, 2.0f, 1.0f);

    m->faceAngle[0] = approach_s32(m->faceAngle[0], 0, 0x200, 0x200);
    m->faceAngle[2] = approach_s32(m->faceAngle[2], 0, 0x100, 0x100);

    m->vel[0] = m->forwardVel * coss(m->faceAngle[0]) * sins(m->faceAngle[1]);
    m->vel[2] = m->forwardVel * coss(m->faceAngle[0]) * coss(m->faceAngle[1]);
}
#include "game/object_helpers.h"
#define SWIMSPEEDBOOST 0.9f
#define MAXSPEEDSWIM 30.f
s16 intendedPitch;
f32 targetSpeed;
f32 targetYspeed;
f32 curYspeed;
f32 targetTotalYspeed;
f32 animSwimspeed;
static void update_swimming_speed(struct MarioState *m, f32 decelThreshold) {
    f32 buoyancy = get_buoyancy(m);
    targetSpeed = m->intendedMag;
    if (targetSpeed > MAXSPEEDSWIM) {
        targetSpeed = MAXSPEEDSWIM;
    }
    targetSpeed *= coss(m->intendedYaw - m->faceAngle[1]);
    if (targetSpeed < 0.f) {
        targetSpeed = 0;
    }
    targetSpeed *= SWIMSPEEDBOOST;

    targetYspeed =
        (m->controller->buttonDown & A_BUTTON) * 32.f + (m->controller->buttonDown & B_BUTTON) * 32.f;
    if (targetYspeed > MAXSPEEDSWIM) {
        targetYspeed = MAXSPEEDSWIM;
    }
    targetYspeed *= coss(intendedPitch - m->faceAngle[0]);
    if (targetYspeed < 0.f) {
        targetYspeed = 0;
    }
    targetYspeed *= SWIMSPEEDBOOST;

    m->forwardVel = approach_f32_symmetric(m->forwardVel, targetSpeed, 0.25f);
    m->forwardVel = approach_f32_asymptotic(m->forwardVel, targetSpeed, 0.0125f);

    m->vel[0] = m->forwardVel * coss(m->faceAngle[0]) * sins(m->faceAngle[1]);
    m->vel[2] = m->forwardVel * coss(m->faceAngle[0]) * coss(m->faceAngle[1]);

    curYspeed = approach_f32_symmetric(curYspeed, targetYspeed, 0.25f);
    curYspeed = approach_f32_asymptotic(curYspeed, targetYspeed, 0.0125f);
    m->vel[1] = sins(m->faceAngle[0]) * curYspeed + buoyancy;
    animSwimspeed = sqrtf(targetSpeed * targetSpeed * coss(intendedPitch - m->faceAngle[0])
                              * coss(intendedPitch - m->faceAngle[0])
                          + m->vel[1] * m->vel[1]);
}

// dont allow the rotation updates to go BEYOND the target rotation!! but how?
// use asymptotic on speed + small sym on raw value?
#define ROTSPEED 0x60
static void update_swimming_yaw(struct MarioState *m) {
    s16 goalDir =
        m->intendedYaw * (m->intendedMag / 32.f) + m->faceAngle[1] * ((32.f - m->intendedMag) / 32.f);
    s16 dist = m->intendedYaw - m->faceAngle[1];
    m->angleVel[1] = approach_s16_symmetric(m->angleVel[1], 0, ROTSPEED / 2);
    if (abs_angle_diff(goalDir, m->faceAngle[1]) > (ROTSPEED * m->intendedMag / 32.f) * 2) {
        if (dist > 0) {
            m->angleVel[1] = approach_f32_symmetric(
                m->angleVel[1], abs_angle_diff(goalDir, m->faceAngle[1]) * (m->intendedMag / 32.f) / 4,
                (ROTSPEED * m->intendedMag / 32.f));
        } else {
            m->angleVel[1] = approach_f32_symmetric(
                m->angleVel[1], -abs_angle_diff(goalDir, m->faceAngle[1]) * (m->intendedMag / 32.f) / 4,
                (ROTSPEED * m->intendedMag / 32.f));
        }
    } else {
        m->faceAngle[1] = approach_s16_symmetric(m->faceAngle[1], goalDir, ROTSPEED / 2);
        m->angleVel[1] *= 0.8f;
    }
    if (m->angleVel[1] > 0x200) {
        m->angleVel[1] = 0x200;
    } else if (m->angleVel[1] < -0x200) {
        m->angleVel[1] = -0x200;
    }
    m->faceAngle[1] += m->angleVel[1];
    m->faceAngle[1] = approach_s16_symmetric(m->faceAngle[1], goalDir, ROTSPEED / 2);
    m->faceAngle[2] = -m->angleVel[1] * 8;
}

// a is straight up b is straight down, unless ceiling or floor is there
#define FULLUP 32.f // 32.f is usually full up but it looked buggy
#define MINFORWARD 8.f

static void update_swimming_pitch(struct MarioState *m) {
    s16 dist;
    f32 swimMag = m->intendedMag;

    if ((m->controller->buttonDown & (A_BUTTON | B_BUTTON)) == (A_BUTTON | B_BUTTON)) {
        intendedPitch = 0;
        swimMag = 32.f;
    } else if (m->controller->buttonDown & (B_BUTTON)) {
        intendedPitch = atan2s((m->intendedMag + MINFORWARD) / (32.f + MINFORWARD) * 32.f, -FULLUP);
        swimMag = 32.f;
    } else if (m->controller->buttonDown & (A_BUTTON)) {
        intendedPitch = atan2s((m->intendedMag + MINFORWARD) / (32.f + MINFORWARD) * 32.f, FULLUP);
        swimMag = 32.f;
    } else {
        intendedPitch = 0;
    }

    dist = intendedPitch - m->faceAngle[0];

    m->angleVel[0] = approach_s16_symmetric(m->angleVel[0], 0, ROTSPEED / 2);
    if (abs_angle_diff(intendedPitch, m->faceAngle[0]) > (ROTSPEED * swimMag / 32.f) * 2) {
        if (dist > 0) {
            m->angleVel[0] = approach_f32_symmetric(m->angleVel[0],
                                                    abs_angle_diff(intendedPitch, m->faceAngle[0]) / 4,
                                                    (ROTSPEED * swimMag / 32.f));
        } else {
            m->angleVel[0] = approach_f32_symmetric(m->angleVel[0],
                                                    -abs_angle_diff(intendedPitch, m->faceAngle[0]) / 4,
                                                    (ROTSPEED * swimMag / 32.f));
        }
    } else {
        m->faceAngle[0] = approach_s16_symmetric(m->faceAngle[0], intendedPitch, ROTSPEED / 2);
        m->angleVel[0] *= 0.8f;
    }
    if (m->angleVel[0] > 0x200) {
        m->angleVel[0] = 0x200;
    } else if (m->angleVel[1] < -0x200) {
        m->angleVel[0] = -0x200;
    }
    m->faceAngle[0] += m->angleVel[0];
    m->faceAngle[0] = approach_s16_symmetric(m->faceAngle[0], intendedPitch, ROTSPEED / 2);
}

static void common_idle_step(struct MarioState *m, s32 animation, s32 arg) {
    s16 *val = &m->marioBodyState->headAngle[0];

    update_swimming_yaw(m);
    update_swimming_pitch(m);
    update_swimming_speed(m, MIN_SWIM_SPEED);
    perform_water_step(m);
    update_water_pitch(m);

    if (m->faceAngle[0] > 0) {
        *val = approach_s32(*val, m->faceAngle[0] / 2, 0x80, 0x200);
    } else {
        *val = approach_s32(*val, 0, 0x200, 0x200);
    }

    if (arg == 0) {
        set_mario_animation(m, animation);
    } else {
        set_mario_anim_with_accel(m, animation, arg);
    }

    set_swimming_at_surface_particles(m, PARTICLE_IDLE_WATER_WAVE);
}

static void reset_float_globals(struct MarioState *m) {
    D_80339FD0 = 0;
    D_80339FD2 = 0x800;
    D_80339FD4 = m->faceAngle[0] / 256.0f + 20.0f;
}

static void play_swimming_noise(struct MarioState *m) {
    s16 animFrame = m->marioObj->header.gfx.unk38.animFrame;

    // (this need to be on one line to match on PAL)
    if (animFrame == 0 || animFrame == 12)
        play_sound(SOUND_ACTION_UNKNOWN434, m->marioObj->header.gfx.cameraToObject);
}

static s32 check_water_jump(struct MarioState *m) {
    s32 probe = (s32) (m->pos[1] + 1.5f);

    if (m->input & (INPUT_A_PRESSED | INPUT_A_LAST_FRAME)) {
        if (probe >= m->waterLevel - 80 && m->faceAngle[0] >= 0) {
            vec3s_set(m->angleVel, 0, 0, 0);

            m->vel[1] = 62.0f;

            if (m->heldObj == NULL) {
                return set_mario_action(m, ACT_JUMP, 0);
            } else {
                return set_mario_action(m, ACT_HOLD_WATER_JUMP, 0);
            }
        }
    }

    return FALSE;
}
static s32 act_water_idle(struct MarioState *m) {
    u32 val = 0x10000 + animSwimspeed * 0x800;
    if (!m->actionState) {
        m->actionState = MARIO_ANIM_WATER_IDLE;
        m->actionTimer = 0;
    }
#define IDLESPEED 8.f
#define FLUTTERKICKSPEED 20.f
    switch (m->actionState) {
        case MARIO_ANIM_WATER_IDLE:
            if (animSwimspeed > FLUTTERKICKSPEED) {
                m->actionState = MARIO_ANIM_SWIM_PART1;
                m->actionTimer = 0;
            } else if (animSwimspeed > IDLESPEED) {
                m->actionState = MARIO_ANIM_FLUTTERKICK;
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_FLUTTERKICK:
            play_swimming_noise(m);
            if (m->forwardVel > FLUTTERKICKSPEED) {
                m->actionState = MARIO_ANIM_SWIM_PART1;
                m->actionTimer = 0;
            } else if (m->forwardVel < IDLESPEED) {
                m->actionState = MARIO_ANIM_SWIM_PART2;
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_SWIM_PART2:
            if ((m->marioObj->header.gfx.unk38.animFrame + m->actionTimer) > 14) {
                if (animSwimspeed < IDLESPEED) {
                    m->actionState = MARIO_ANIM_WATER_IDLE;
                } else if (animSwimspeed < FLUTTERKICKSPEED) {
                    m->actionState = MARIO_ANIM_FLUTTERKICK;
                } else {
                    m->actionState = MARIO_ANIM_SWIM_PART1;
                }
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_SWIM_PART1:
            if (m->actionTimer == 1) {
                play_sound(sSwimStrength == MIN_SWIM_STRENGTH ? SOUND_ACTION_SWIM
                                                              : SOUND_ACTION_SWIM_FAST,
                           m->marioObj->header.gfx.cameraToObject);
                reset_float_globals(m);
            }
            if (animSwimspeed < FLUTTERKICKSPEED) {
                if (m->actionTimer > 25) {
                    if (animSwimspeed < IDLESPEED) {
                        m->actionState = MARIO_ANIM_SWIM_PART2;
                        m->actionTimer = 0;
                    } else {
                        m->actionState = MARIO_ANIM_FLUTTERKICK;
                        m->actionTimer = 0;
                    }
                }
            } else {
                if ((m->marioObj->header.gfx.unk38.animFrame + m->actionTimer) > 55.f - animSwimspeed) {
                    // set_anim_to_frame(m, 0);
                    m->actionState = MARIO_ANIM_SWIM_PART2;
                    m->actionTimer = 0;
                }
            }
            break;
    }

    if (check_water_jump(m)) {
        return TRUE;
    }
    if (m->input & INPUT_Z_PRESSED) {
        return set_mario_action(m, ACT_GROUND_POUND, 0);
    }
    m->actionTimer++;
    common_idle_step(m, m->actionState, val);
    return FALSE;
}

static s32 act_hold_water_idle(struct MarioState *m) {

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_WATER_IDLE, 0);
    }

    if (m->input & INPUT_Z_PRESSED) {
        return set_mario_action(m, ACT_WATER_THROW, 0);
    }

    if (!m->actionState) {
        m->actionState = MARIO_ANIM_WATER_IDLE_WITH_OBJ;
        m->actionTimer = 0;
    }
    switch (m->actionState) {
        case MARIO_ANIM_WATER_IDLE_WITH_OBJ:
            if (targetSpeed > FLUTTERKICKSPEED) {
                m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART1;
                m->actionTimer = 0;
            } else if (targetSpeed > IDLESPEED) {
                m->actionState = MARIO_ANIM_FLUTTERKICK_WITH_OBJ;
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_FLUTTERKICK_WITH_OBJ:
            play_swimming_noise(m);
            if (m->forwardVel > FLUTTERKICKSPEED) {
                m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART1;
                m->actionTimer = 0;
            } else if (m->forwardVel < IDLESPEED) {
                m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART2;
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_SWIM_WITH_OBJ_PART2:
            if (m->actionTimer > 9) {
                if (targetSpeed < IDLESPEED) {
                    m->actionState = MARIO_ANIM_WATER_IDLE_WITH_OBJ;
                } else if (targetSpeed < FLUTTERKICKSPEED) {
                    m->actionState = MARIO_ANIM_FLUTTERKICK_WITH_OBJ;
                } else {
                    m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART1;
                }
                m->actionTimer = 0;
            }
            break;
        case MARIO_ANIM_SWIM_WITH_OBJ_PART1:
            if (m->actionTimer == 1) {
                play_sound(sSwimStrength == MIN_SWIM_STRENGTH ? SOUND_ACTION_SWIM
                                                              : SOUND_ACTION_SWIM_FAST,
                           m->marioObj->header.gfx.cameraToObject);
                reset_float_globals(m);
            }
            if (targetSpeed < FLUTTERKICKSPEED) {
                if (m->actionTimer > 25) {
                    if (targetSpeed < IDLESPEED) {
                        m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART2;
                        m->actionTimer = 0;
                    } else {
                        m->actionState = MARIO_ANIM_FLUTTERKICK_WITH_OBJ;
                        m->actionTimer = 0;
                    }
                }
            } else {
                if (m->actionTimer > 55.f - targetSpeed) {
                    // set_anim_to_frame(m, 0);
                    m->actionState = MARIO_ANIM_SWIM_WITH_OBJ_PART2;
                    m->actionTimer = 0;
                }
            }
            break;
    }

    if (check_water_jump(m)) {
        return TRUE;
    }
    m->actionTimer++;
    common_idle_step(m, m->actionState, 0);
    return FALSE;
}

static s32 act_water_action_end(struct MarioState *m) {

    common_idle_step(m, MARIO_ANIM_WATER_ACTION_END, 0);
    if (is_anim_at_end(m)) {
        set_mario_action(m, ACT_WATER_IDLE, 0);
    }
    return FALSE;
}

static s32 act_hold_water_action_end(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_WATER_IDLE, 0);
    }
    common_idle_step(
        m, m->actionArg == 0 ? MARIO_ANIM_WATER_ACTION_END_WITH_OBJ : MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        0);
    if (is_anim_at_end(m)) {
        set_mario_action(m, ACT_HOLD_WATER_IDLE, 0);
    }
    return FALSE;
}

static void float_surface_gfx(struct MarioState *m) {
    if (D_80339FD2 != 0 && m->pos[1] > m->waterLevel - 85 && m->faceAngle[0] >= 0) {
        if ((D_80339FD0 += D_80339FD2) >= 0) {
            m->marioObj->header.gfx.pos[1] += D_80339FD4 * sins(D_80339FD0);
            return;
        }
    }

    D_80339FD2 = 0;
}

static void common_swimming_step(struct MarioState *m, s16 swimStrength) {
    s16 floorPitch;

    update_swimming_yaw(m);
    update_swimming_pitch(m);
    update_swimming_speed(m, swimStrength / 10.0f);

    switch (perform_water_step(m)) {
        case WATER_STEP_HIT_FLOOR:
            floorPitch = -find_floor_slope(m, -0x8000);
            if (m->faceAngle[0] < floorPitch) {
                m->faceAngle[0] = floorPitch;
            }
            break;

        case WATER_STEP_HIT_CEILING:
            if (m->faceAngle[0] > -0x3000) {
                m->faceAngle[0] -= 0x100;
            }
            break;

        case WATER_STEP_HIT_WALL:
            if (m->controller->stickY == 0.0f) {
                if (m->faceAngle[0] > 0.0f) {
                    m->faceAngle[0] += 0x200;
                    if (m->faceAngle[0] > 0x3F00) {
                        m->faceAngle[0] = 0x3F00;
                    }
                } else {
                    m->faceAngle[0] -= 0x200;
                    if (m->faceAngle[0] < -0x3F00) {
                        m->faceAngle[0] = -0x3F00;
                    }
                }
            }
            break;
    }

    update_water_pitch(m);
    m->marioBodyState->headAngle[0] = approach_s32(m->marioBodyState->headAngle[0], 0, 0x200, 0x200);

    float_surface_gfx(m);
    set_swimming_at_surface_particles(m, PARTICLE_WAVE_TRAIL);
}

static s32 act_breaststroke(struct MarioState *m) {
    return FALSE;
}

static s32 act_swimming_end(struct MarioState *m) {

    return FALSE;
}

static s32 act_flutter_kick(struct MarioState *m) {
    return FALSE;
}

static s32 act_hold_breaststroke(struct MarioState *m) {
    return FALSE;
}

static s32 act_hold_swimming_end(struct MarioState *m) {
    return FALSE;
}

static s32 act_hold_flutter_kick(struct MarioState *m) {
    return FALSE;
}
extern u16 breath;
static s32 act_water_shell_swimming(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_WATER_IDLE, 0);
    }
    if (m->input & INPUT_Z_DOWN) {
        return set_mario_action(m, ACT_WATER_THROW, 0);
    }
    if (targetSpeed < FLUTTERKICKSPEED) {
        if ((!(m->actionTimer & 7))) {
            m->particleFlags |= PARTICLE_PLUNGE_BUBBLE;
        }
        m->actionTimer++;
    }
    m->forwardVel = approach_f32(m->forwardVel, targetSpeed * 1.5f, 2.0f, 1.0f);
    if (m->actionState > 0) {
        m->forwardVel = approach_f32(m->forwardVel, 100.f, 10.0f, 1.0f);
        m->particleFlags |= PARTICLE_BUBBLE | PARTICLE_WAVE_TRAIL;
        if (m->actionState > 0xF100) {
            m->actionState = 0;
        } else {
            m->actionTimer++;
            m->actionState += 0x1700 - m->actionTimer * 0x18;
        }
    } else if (m->actionTimer > 40) {
        if (((m->controller->buttonDown & A_BUTTON) && (m->controller->buttonPressed & B_BUTTON))
            || ((m->controller->buttonDown & B_BUTTON) && (m->controller->buttonPressed & A_BUTTON))
            || ((m->controller->buttonDown & (B_BUTTON | A_BUTTON)) == (B_BUTTON | A_BUTTON))) {

            m->forwardVel = approach_f32(m->forwardVel, 64.f, 5.0f, 1.0f);
            m->actionState = 0x1700;
            m->actionTimer = 0;
            m->particleFlags |= PARTICLE_SPARKLES | PARTICLE_TRIANGLE;
            play_sound(SOUND_OBJ_UNKNOWN4, m->marioObj->header.gfx.cameraToObject);
        }
    } else {

        m->actionTimer++;
    }
    breath = approach_s16_symmetric(breath, MAXBREATH, 4);
    play_swimming_noise(m);
    set_mario_animation(m, MARIO_ANIM_FLUTTERKICK_WITH_OBJ);
    common_swimming_step(m, 0x01e0);
    vec3s_set(m->marioObj->header.gfx.angle, -m->faceAngle[0], m->faceAngle[1], m->actionState);
    m->marioObj->header.gfx.pos[1] += sins(m->actionState / 2) * 75.f * coss(m->faceAngle[0]);

    return FALSE;
}

static s32 check_water_grab(struct MarioState *m) {
    //! Heave hos have the grabbable interaction type but are not normally
    // grabbable. Since water grabbing doesn't check the appropriate input flag,
    // you can use water grab to pick up heave ho.
    if (m->marioObj->collidedObjInteractTypes & INTERACT_GRABBABLE) {
        struct Object *object = mario_get_collided_object(m, INTERACT_GRABBABLE);
        f32 dx = object->oPosX - m->pos[0];
        f32 dz = object->oPosZ - m->pos[2];
        s16 dAngleToObject = atan2s(dz, dx) - m->faceAngle[1];

        if (dAngleToObject >= -0x2AAA && dAngleToObject <= 0x2AAA) {
            m->usedObj = object;
            mario_grab_used_object(m);
            m->marioBodyState->grabPos = GRAB_POS_LIGHT_OBJ;
            return TRUE;
        }
    }

    return FALSE;
}

static s32 act_water_throw(struct MarioState *m) {
    update_swimming_yaw(m);
    update_swimming_pitch(m);
    update_swimming_speed(m, MIN_SWIM_SPEED);
    perform_water_step(m);
    update_water_pitch(m);

    set_mario_animation(m, MARIO_ANIM_WATER_THROW_OBJ);
    play_sound_if_no_flag(m, SOUND_ACTION_SWIM, MARIO_ACTION_SOUND_PLAYED);

    m->marioBodyState->headAngle[0] = approach_s32(m->marioBodyState->headAngle[0], 0, 0x200, 0x200);

    if (m->actionTimer++ == 5) {
        mario_throw_held_object(m);
#ifdef VERSION_SH
        queue_rumble_data(3, 50);
#endif
    }

    if (is_anim_at_end(m)) {
        set_mario_action(m, ACT_WATER_IDLE, 0);
    }

    return FALSE;
}

static s32 act_water_punch(struct MarioState *m) {
    if (m->forwardVel < 7.0f) {
        m->forwardVel += 1.0f;
    }
    update_swimming_yaw(m);
    update_swimming_pitch(m);
    update_swimming_speed(m, MIN_SWIM_SPEED);
    perform_water_step(m);
    update_water_pitch(m);

    m->marioBodyState->headAngle[0] = approach_s32(m->marioBodyState->headAngle[0], 0, 0x200, 0x200);

    play_sound_if_no_flag(m, SOUND_ACTION_SWIM, MARIO_ACTION_SOUND_PLAYED);

    switch (m->actionState) {
        case 0:
            set_mario_animation(m, MARIO_ANIM_WATER_GRAB_OBJ_PART1);
            if (is_anim_at_end(m)) {
                m->actionState = check_water_grab(m) + 1;
            }
            break;

        case 1:
            set_mario_animation(m, MARIO_ANIM_WATER_GRAB_OBJ_PART2);
            if (is_anim_at_end(m)) {
                set_mario_action(m, ACT_WATER_ACTION_END, 0);
            }
            break;

        case 2:
            set_mario_animation(m, MARIO_ANIM_WATER_PICK_UP_OBJ);
            if (is_anim_at_end(m)) {
                if (m->heldObj->behavior == segmented_to_virtual(bhvKoopaShellUnderwater)) {
                    set_mario_action(m, ACT_WATER_SHELL_SWIMMING, 0);
                } else {
                    set_mario_action(m, ACT_HOLD_WATER_ACTION_END, 1);
                }
            }
            break;
    }

    return FALSE;
}

static void common_water_knockback_step(struct MarioState *m, s32 animation, u32 endAction, s32 arg3) {
    stationary_slow_down(m);
    perform_water_step(m);
    set_mario_animation(m, animation);

    m->marioBodyState->headAngle[0] = 0;

    if (is_anim_at_end(m)) {
        if (arg3 > 0) {
            m->invincTimer = 30;
        }

        set_mario_action(m, m->health >= 0x100 ? endAction : ACT_WATER_DEATH, 0);
    }
}

static s32 act_backward_water_kb(struct MarioState *m) {
    common_water_knockback_step(m, MARIO_ANIM_BACKWARDS_WATER_KB, ACT_WATER_IDLE, m->actionArg);
    return FALSE;
}

static s32 act_forward_water_kb(struct MarioState *m) {
    common_water_knockback_step(m, MARIO_ANIM_WATER_FORWARD_KB, ACT_WATER_IDLE, m->actionArg);
    return FALSE;
}

static s32 act_water_shocked(struct MarioState *m) {
    play_sound_if_no_flag(m, SOUND_MARIO_WAAAOOOW, MARIO_ACTION_SOUND_PLAYED);
    play_sound(SOUND_MOVING_SHOCKED, m->marioObj->header.gfx.cameraToObject);
    set_camera_shake_from_hit(SHAKE_SHOCK);

    if (set_mario_animation(m, MARIO_ANIM_SHOCKED) == 0) {
        m->actionTimer++;
        m->flags |= MARIO_METAL_SHOCK;
    }

    if (m->actionTimer >= 6) {
        m->invincTimer = 30;
        set_mario_action(m, m->health < 0x100 ? ACT_WATER_DEATH : ACT_WATER_IDLE, 0);
    }

    stationary_slow_down(m);
    perform_water_step(m);
    m->marioBodyState->headAngle[0] = 0;
    return FALSE;
}

static s32 act_drowning(struct MarioState *m) {
    switch (m->actionState) {
        case 0:
            set_mario_animation(m, MARIO_ANIM_DROWNING_PART1);
            m->marioBodyState->eyeState = MARIO_EYES_HALF_CLOSED;
            if (is_anim_at_end(m)) {
                m->actionState = 1;
            }
            break;

        case 1:
            set_mario_animation(m, MARIO_ANIM_DROWNING_PART2);
            m->marioBodyState->eyeState = MARIO_EYES_DEAD;
            if (m->marioObj->header.gfx.unk38.animFrame == 30) {
                level_trigger_warp(m, WARP_OP_DEATH);
            }
            break;
    }

    play_sound_if_no_flag(m, SOUND_MARIO_DROWNING, MARIO_ACTION_SOUND_PLAYED);
    stationary_slow_down(m);
    perform_water_step(m);

    return FALSE;
}

static s32 act_water_death(struct MarioState *m) {
    stationary_slow_down(m);
    perform_water_step(m);

    m->marioBodyState->eyeState = MARIO_EYES_DEAD;

    set_mario_animation(m, MARIO_ANIM_WATER_DYING);
    if (set_mario_animation(m, MARIO_ANIM_WATER_DYING) == 35) {
        level_trigger_warp(m, WARP_OP_DEATH);
    }

    return FALSE;
}

static s32 act_water_plunge(struct MarioState *m) {
    u32 stepResult;
    s32 stateFlags = m->heldObj != NULL;
    f32 endVSpeed;
    if (swimming_near_surface(m)) {
        endVSpeed = 0.0f;
    } else {
        endVSpeed = -5.0f;
    }
    /*    if ((m->prevAction & ACT_FLAG_DIVING) || (m->input & INPUT_A_DOWN)) {
            stateFlags |= 2;
        }*/

    m->actionTimer++;

    stationary_slow_down(m);

    stepResult = perform_water_step(m);

    if (m->actionState == 0) {
        play_sound(SOUND_ACTION_UNKNOWN430, m->marioObj->header.gfx.cameraToObject);
        if (m->peakHeight - m->pos[1] > 1150.0f) {
            play_sound(SOUND_MARIO_HAHA_2, m->marioObj->header.gfx.cameraToObject);
        }
        m->particleFlags |= PARTICLE_WATER_SPLASH;
        m->actionState = 1;
#ifdef VERSION_SH
        if (m->prevAction & ACT_FLAG_AIR) {
            queue_rumble_data(5, 80);
        }
#endif
    }

    if (stepResult == WATER_STEP_HIT_FLOOR || m->vel[1] >= endVSpeed || m->actionTimer > 20) {
        switch (stateFlags) {
            case 0:
                set_mario_action(m, ACT_WATER_ACTION_END, 0);
                break;
            case 1:
                set_mario_action(m, ACT_HOLD_WATER_ACTION_END, 0);
                break;
            case 4:
                set_mario_action(m, ACT_METAL_WATER_FALLING, 0);
                break;
            case 5:
                set_mario_action(m, ACT_HOLD_METAL_WATER_FALLING, 0);
                break;
        }
        D_80339FD2 = 0;
    }

    switch (stateFlags) {
        case 0:
            set_mario_animation(m, MARIO_ANIM_WATER_ACTION_END);
            break;
        case 1:
            set_mario_animation(m, MARIO_ANIM_WATER_ACTION_END_WITH_OBJ);
            break;
        case 4:
            set_mario_animation(m, MARIO_ANIM_GENERAL_FALL);
            break;
        case 5:
            set_mario_animation(m, MARIO_ANIM_FALL_WITH_LIGHT_OBJ);
            break;
    }

    m->particleFlags |= PARTICLE_PLUNGE_BUBBLE;
    return FALSE;
}

static s32 act_caught_in_whirlpool(struct MarioState *m) {
    f32 sinAngleChange;
    f32 cosAngleChange;
    f32 newDistance;
    s16 angleChange;

    struct Object *marioObj = m->marioObj;
    struct Object *whirlpool = m->usedObj;

    f32 dx = m->pos[0] - whirlpool->oPosX;
    f32 dz = m->pos[2] - whirlpool->oPosZ;
    f32 distance = sqrtf(dx * dx + dz * dz);

    if ((marioObj->oMarioWhirlpoolPosY += m->vel[1]) < 0.0f) {
        marioObj->oMarioWhirlpoolPosY = 0.0f;
        if (distance < 16.1f && m->actionTimer++ == 16) {
            level_trigger_warp(m, WARP_OP_DEATH);
        }
    }

    if (distance <= 28.0f) {
        newDistance = 16.0f;
        angleChange = 0x1800;
    } else if (distance < 256.0f) {
        newDistance = distance - (12.0f - distance / 32.0f);
        angleChange = (s16) (0x1C00 - distance * 20.0f);
    } else {
        newDistance = distance - 8.0f;
        angleChange = 0x800;
    }

    m->vel[1] = -640.0f / (newDistance + 16.0f);

    sinAngleChange = sins(angleChange);
    cosAngleChange = coss(angleChange);

    if (distance < 1.0f) {
        dx = newDistance * sins(m->faceAngle[1]);
        dz = newDistance * coss(m->faceAngle[1]);
    } else {
        dx *= newDistance / distance;
        dz *= newDistance / distance;
    }

    m->pos[0] = whirlpool->oPosX + dx * cosAngleChange + dz * sinAngleChange;
    m->pos[2] = whirlpool->oPosZ - dx * sinAngleChange + dz * cosAngleChange;
    m->pos[1] = whirlpool->oPosY + marioObj->oMarioWhirlpoolPosY;

    m->faceAngle[1] = atan2s(dz, dx) + 0x8000;

    set_mario_animation(m, MARIO_ANIM_GENERAL_FALL);
    vec3f_copy(m->marioObj->header.gfx.pos, m->pos);
    vec3s_set(m->marioObj->header.gfx.angle, 0, m->faceAngle[1], 0);
#ifdef VERSION_SH
    reset_rumble_timers();
#endif

    return FALSE;
}

static void play_metal_water_jumping_sound(struct MarioState *m, u32 landing) {
    if (!(m->flags & MARIO_ACTION_SOUND_PLAYED)) {
        m->particleFlags |= PARTICLE_MIST_CIRCLE;
    }

    play_sound_if_no_flag(m, landing ? SOUND_ACTION_METAL_LAND_WATER : SOUND_ACTION_METAL_JUMP_WATER,
                          MARIO_ACTION_SOUND_PLAYED);
}

static void play_metal_water_walking_sound(struct MarioState *m) {
    if (is_anim_past_frame(m, 10) || is_anim_past_frame(m, 49)) {
        play_sound(SOUND_ACTION_METAL_STEP_WATER, m->marioObj->header.gfx.cameraToObject);
        m->particleFlags |= PARTICLE_DUST;
    }
}

static void update_metal_water_walking_speed(struct MarioState *m) {
    f32 val = m->intendedMag / 1.5f;

    if (m->forwardVel <= 0.0f) {
        m->forwardVel += 1.1f;
    } else if (m->forwardVel <= val) {
        m->forwardVel += 1.1f - m->forwardVel / 43.0f;
    } else if (m->floor->normal.y >= 0.95f) {
        m->forwardVel -= 1.0f;
    }

    if (m->forwardVel > 32.0f) {
        m->forwardVel = 32.0f;
    }

    m->faceAngle[1] =
        m->intendedYaw - approach_s32((s16) (m->intendedYaw - m->faceAngle[1]), 0, 0x800, 0x800);

    m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);

    m->vel[0] = m->slideVelX;
    m->vel[1] = 0.0f;
    m->vel[2] = m->slideVelZ;
}

static s32 update_metal_water_jump_speed(struct MarioState *m) {
    f32 waterSurface = m->waterLevel - 100;

    if (m->vel[1] > 0.0f && m->pos[1] > waterSurface) {
        return TRUE;
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        s16 intendedDYaw = m->intendedYaw - m->faceAngle[1];
        m->forwardVel += 0.8f * coss(intendedDYaw);
        m->faceAngle[1] += 0x200 * sins(intendedDYaw);
    } else {
        m->forwardVel = approach_f32(m->forwardVel, 0.0f, 0.25f, 0.25f);
    }

    if (m->forwardVel > 16.0f) {
        m->forwardVel -= 1.0f;
    }

    if (m->forwardVel < 0.0f) {
        m->forwardVel += 2.0f;
    }

    m->vel[0] = m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->vel[2] = m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);
    return FALSE;
}

static s32 act_metal_water_standing(struct MarioState *m) {

    if (m->input & (INPUT_A_PRESSED | INPUT_A_LAST_FRAME)) {
        return set_mario_action(m, ACT_METAL_WATER_JUMP, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_METAL_WATER_WALKING, 0);
    }

    switch (m->actionState) {
        case 0:
            set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_LEFT);
            break;
        case 1:
            set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_RIGHT);
            break;
        case 2:
            set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_CENTER);
            break;
    }

    if (is_anim_at_end(m) && ++m->actionState == 3) {
        m->actionState = 0;
    }

    stop_and_set_height_to_floor(m);
    if (m->pos[1] >= m->waterLevel - 150) {
        m->particleFlags |= PARTICLE_IDLE_WATER_WAVE;
    }

    return FALSE;
}

static s32 act_hold_metal_water_standing(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    if (m->input & (INPUT_A_PRESSED | INPUT_A_LAST_FRAME)) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_JUMP, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_WALKING, 0);
    }

    stop_and_set_height_to_floor(m);
    set_mario_animation(m, MARIO_ANIM_IDLE_WITH_LIGHT_OBJ);
    return FALSE;
}

static s32 act_metal_water_walking(struct MarioState *m) {
    s32 val04;

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    if (m->input & (INPUT_A_PRESSED | INPUT_A_LAST_FRAME)) {
        return set_mario_action(m, ACT_METAL_WATER_JUMP, 0);
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    if ((val04 = (s32) (m->forwardVel / 4.0f * 0x10000)) < 0x1000) {
        val04 = 0x1000;
    }

    set_mario_anim_with_accel(m, MARIO_ANIM_WALKING, val04);
    play_metal_water_walking_sound(m);
    update_metal_water_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_METAL_WATER_FALLING, 1);
            break;

        case GROUND_STEP_HIT_WALL:
            m->forwardVel = 0;
            break;
    }

    return FALSE;
}

static s32 act_hold_metal_water_walking(struct MarioState *m) {
    s32 val04;

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_WALKING, 0);
    }

    if (m->input & (INPUT_A_PRESSED | INPUT_A_LAST_FRAME)) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_JUMP, 0);
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_STANDING, 0);
    }

    m->intendedMag *= 0.4f;

    if ((val04 = (s32) (m->forwardVel / 2.0f * 0x10000)) < 0x1000) {
        val04 = 0x1000;
    }

    set_mario_anim_with_accel(m, MARIO_ANIM_RUN_WITH_LIGHT_OBJ, val04);
    play_metal_water_walking_sound(m);
    update_metal_water_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_HOLD_METAL_WATER_FALLING, 1);
            break;

        case GROUND_STEP_HIT_WALL:
            m->forwardVel = 0.0f;
            break;
    }

    return FALSE;
}

static s32 act_metal_water_jump(struct MarioState *m) {
    if (update_metal_water_jump_speed(m)) {
        return set_mario_action(m, ACT_JUMP, 1);
    }

    play_metal_water_jumping_sound(m, FALSE);
    set_mario_animation(m, MARIO_ANIM_SINGLE_JUMP);

    switch (perform_air_step(m, 0)) {
        case AIR_STEP_LANDED:
            set_mario_action(m, ACT_METAL_WATER_JUMP_LAND, 0);
            break;

        case AIR_STEP_HIT_WALL:
            m->forwardVel = 0.0f;
            break;
    }

    return FALSE;
}

static s32 act_hold_metal_water_jump(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_FALLING, 0);
    }

    if (update_metal_water_jump_speed(m)) {
        return set_mario_action(m, ACT_HOLD_WATER_JUMP, 1);
    }

    play_metal_water_jumping_sound(m, FALSE);
    set_mario_animation(m, MARIO_ANIM_JUMP_WITH_LIGHT_OBJ);

    switch (perform_air_step(m, 0)) {
        case AIR_STEP_LANDED:
            set_mario_action(m, ACT_HOLD_METAL_WATER_JUMP_LAND, 0);
            break;

        case AIR_STEP_HIT_WALL:
            m->forwardVel = 0.0f;
            break;
    }

    return FALSE;
}

static s32 act_metal_water_falling(struct MarioState *m) {

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] += 0x400 * sins(m->intendedYaw - m->faceAngle[1]);
    }

    set_mario_animation(m, m->actionArg == 0 ? MARIO_ANIM_GENERAL_FALL : MARIO_ANIM_FALL_FROM_WATER);
    stationary_slow_down(m);

    if (perform_water_step(m) & WATER_STEP_HIT_FLOOR) { // hit floor or cancelled
        set_mario_action(m, ACT_METAL_WATER_FALL_LAND, 0);
    }

    return FALSE;
}

static s32 act_hold_metal_water_falling(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_FALLING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] += 0x400 * sins(m->intendedYaw - m->faceAngle[1]);
    }

    set_mario_animation(m, MARIO_ANIM_FALL_WITH_LIGHT_OBJ);
    stationary_slow_down(m);

    if (perform_water_step(m) & WATER_STEP_HIT_FLOOR) { // hit floor or cancelled
        set_mario_action(m, ACT_HOLD_METAL_WATER_FALL_LAND, 0);
    }

    return FALSE;
}

static s32 act_metal_water_jump_land(struct MarioState *m) {
    play_metal_water_jumping_sound(m, TRUE);

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_METAL_WATER_WALKING, 0);
    }

    stop_and_set_height_to_floor(m);
    set_mario_animation(m, MARIO_ANIM_LAND_FROM_SINGLE_JUMP);

    if (is_anim_at_end(m)) {
        return set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    return FALSE;
}

static s32 act_hold_metal_water_jump_land(struct MarioState *m) {
    play_metal_water_jumping_sound(m, TRUE);

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_WALKING, 0);
    }

    stop_and_set_height_to_floor(m);
    set_mario_animation(m, MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ);

    if (is_anim_at_end(m)) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_STANDING, 0);
    }

    return FALSE;
}

static s32 act_metal_water_fall_land(struct MarioState *m) {
    play_metal_water_jumping_sound(m, TRUE);

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_METAL_WATER_WALKING, 0);
    }

    stop_and_set_height_to_floor(m);
    set_mario_animation(m, MARIO_ANIM_GENERAL_LAND);

    if (is_anim_at_end(m)) {
        return set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    return FALSE;
}

static s32 act_hold_metal_water_fall_land(struct MarioState *m) {
    play_metal_water_jumping_sound(m, TRUE);

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_METAL_WATER_STANDING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_WALKING, 0);
    }

    stop_and_set_height_to_floor(m);
    set_mario_animation(m, MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ);

    if (is_anim_at_end(m)) {
        return set_mario_action(m, ACT_HOLD_METAL_WATER_STANDING, 0);
    }

    return FALSE;
}

static s32 check_common_submerged_cancels(struct MarioState *m) {
    if ((m->pos[1] > m->waterLevel - 80) && m->action != ACT_DROWNING) {
        if (m->waterLevel - 80 > m->floorHeight) {
            m->pos[1] = m->waterLevel - 80;
        } else {
            //! If you press B to throw the shell, there is a ~5 frame window
            // where your held object is the shell, but you are not in the
            // water shell swimming action. This allows you to hold the water
            // shell on land (used for cloning in DDD).
            if (m->action == ACT_WATER_SHELL_SWIMMING && m->heldObj != NULL) {
                m->heldObj->oInteractStatus = INT_STATUS_STOP_RIDING;
                m->heldObj = NULL;
            }

            return transition_submerged_to_walking(m);
        }
    }

    if (m->health < 0x100 && !(m->action & (ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE))) {
        set_mario_action(m, ACT_DROWNING, 0);
    }

    return FALSE;
}

s32 mario_execute_submerged_action(struct MarioState *m) {
    s32 cancel;

    if (check_common_submerged_cancels(m)) {
        return TRUE;
    }

    m->quicksandDepth = 0.0f;

    m->marioBodyState->headAngle[1] = 0;
    m->marioBodyState->headAngle[2] = 0;

    /* clang-format off */
    switch (m->action) {
        case ACT_WATER_IDLE:                 cancel = act_water_idle(m);                 break;
        case ACT_HOLD_WATER_IDLE:            cancel = act_hold_water_idle(m);            break;
        case ACT_WATER_ACTION_END:           cancel = act_water_action_end(m);           break;
        case ACT_HOLD_WATER_ACTION_END:      cancel = act_hold_water_action_end(m);      break;
        case ACT_DROWNING:                   cancel = act_drowning(m);                   break;
        case ACT_BACKWARD_WATER_KB:          cancel = act_backward_water_kb(m);          break;
        case ACT_FORWARD_WATER_KB:           cancel = act_forward_water_kb(m);           break;
        case ACT_WATER_DEATH:                cancel = act_water_death(m);                break;
        case ACT_WATER_SHOCKED:              cancel = act_water_shocked(m);              break;
        case ACT_BREASTSTROKE:               cancel = act_breaststroke(m);               break;
        case ACT_SWIMMING_END:               cancel = act_swimming_end(m);               break;
        case ACT_FLUTTER_KICK:               cancel = act_flutter_kick(m);               break;
        case ACT_HOLD_BREASTSTROKE:          cancel = act_hold_breaststroke(m);          break;
        case ACT_HOLD_SWIMMING_END:          cancel = act_hold_swimming_end(m);          break;
        case ACT_HOLD_FLUTTER_KICK:          cancel = act_hold_flutter_kick(m);          break;
        case ACT_WATER_SHELL_SWIMMING:       cancel = act_water_shell_swimming(m);       break;
        case ACT_WATER_THROW:                cancel = act_water_throw(m);                break;
        case ACT_WATER_PUNCH:                cancel = act_water_punch(m);                break;
        case ACT_WATER_PLUNGE:               cancel = act_water_plunge(m);               break;
        case ACT_CAUGHT_IN_WHIRLPOOL:        cancel = act_caught_in_whirlpool(m);        break;
        case ACT_METAL_WATER_STANDING:       cancel = act_metal_water_standing(m);       break;
        case ACT_METAL_WATER_WALKING:        cancel = act_metal_water_walking(m);        break;
        case ACT_METAL_WATER_FALLING:        cancel = act_metal_water_falling(m);        break;
        case ACT_METAL_WATER_FALL_LAND:      cancel = act_metal_water_fall_land(m);      break;
        case ACT_METAL_WATER_JUMP:           cancel = act_metal_water_jump(m);           break;
        case ACT_METAL_WATER_JUMP_LAND:      cancel = act_metal_water_jump_land(m);      break;
        case ACT_HOLD_METAL_WATER_STANDING:  cancel = act_hold_metal_water_standing(m);  break;
        case ACT_HOLD_METAL_WATER_WALKING:   cancel = act_hold_metal_water_walking(m);   break;
        case ACT_HOLD_METAL_WATER_FALLING:   cancel = act_hold_metal_water_falling(m);   break;
        case ACT_HOLD_METAL_WATER_FALL_LAND: cancel = act_hold_metal_water_fall_land(m); break;
        case ACT_HOLD_METAL_WATER_JUMP:      cancel = act_hold_metal_water_jump(m);      break;
        case ACT_HOLD_METAL_WATER_JUMP_LAND: cancel = act_hold_metal_water_jump_land(m); break;
    }
    /* clang-format on */

    return cancel;
}