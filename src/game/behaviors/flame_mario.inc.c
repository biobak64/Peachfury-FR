// flame_mario.c.inc

void bhv_black_smoke_upward_loop(void) {
    spawn_object_with_scale(o, MODEL_BURN_SMOKE, bhvBlackSmokeBowser, o->header.gfx.scale[0]);
}

void bhv_black_smoke_bowser_loop(void) {
    if (o->oTimer == 0) {
        o->oForwardVel = random_float() * 2 + 0.5;
        o->oMoveAngleYaw = random_u16();
        o->oVelY = 8;
        o->oBlackSmokeBowserUnkF4 = o->header.gfx.scale[0];
    }
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void bhv_black_smoke_mario_loop(void) {
    if (o->oTimer == 0) {
      //  o->oOpacity =255;
        o->header.gfx.scale[0] = random_float()*.5 + 0.75f;
        if (o->oBehParams2ndByte == 0) {
            cur_obj_set_pos_relative(gMarioObject, 0, 0, -30.0f);
        }
        if (o->oBehParams2ndByte == 2) {

        } else {
            o->oForwardVel = random_float() * 2 + 0.5f;
            o->oMoveAngleYaw = (gMarioObject->oMoveAngleYaw + 0x7000) + random_float() * 8192.0f;
            o->oVelY = 8.f;
        }
    }
    o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 11);
    o->header.gfx.scale[0] = o->header.gfx.scale[0] + .05f;
    o->header.gfx.scale[1] = o->header.gfx.scale[0];
    o->header.gfx.scale[2] = o->header.gfx.scale[0];
    o->oGraphYOffset = 50.f * o->header.gfx.scale[0];
    if (!o->oOpacity) {
        obj_mark_for_deletion(o);
    }
    o->oAnimState++;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
    o->oPosX += sins(o->oMoveAngleYaw) * o->oForwardVel;
    o->oPosZ += coss(o->oMoveAngleYaw) * o->oForwardVel;
}

void bhv_flame_mario_loop(void) {
    cur_obj_scale(2.0f);
    if (o->oTimer != 0)
        if (o->oTimer & 1)
            spawn_object(o, MODEL_BURN_SMOKE, bhvBlackSmokeMario);
    gMarioObject->prevObj = o; // weird?
    obj_set_parent_relative_pos(o, 40, -120, 0);
    if (!(gMarioObject->oMarioParticleFlags & 0x800)) {
        o->parentObj->oActiveParticleFlags &= ~0x800;
        obj_mark_for_deletion(o);
        gMarioObject->prevObj = NULL;
    }
}
