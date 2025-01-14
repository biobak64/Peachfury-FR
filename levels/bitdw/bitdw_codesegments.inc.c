// stuff to make programming easier
#include "sm64.h"
#include "types.h"
//#include "game/game.h"
#include "game/level_update.h"
#include "dialog_ids.h"
//#include "game/kaze_library.h"
#include "seq_ids.h"
#include "game/camera.h"
#include "engine/math_util.h"
#include "game/obj_behaviors_2.h"
#include "game/object_helpers.h"
#include "levels/wf/header.h"
#include "engine/behavior_script.h"
#include "game/spawn_sound.h"
#include "engine/surface_collision.h"
#include "game/interaction.h"
#include "engine/behavior_script.h"
#include "game/object_list_processor.h"
#include "behavior_data.h"
extern u8 talkToMario(int dialogID, int actionArg);
extern u8 askMario(int dialogID, u8 rotate, int actionArg);
extern f32 vec3f_dist(Vec3f a, Vec3f b);
#define m gMarioState
#define o gCurrentObject
#define objAnimID (o->header.gfx.unk38.animID)
#define objAnimFrame (o->header.gfx.unk38.animFrame)
#define marioObject gMarioState->marioObj
// stuff for segmented code

s16 bridgeUpFrames[120] = {
    0xFFFF, 0xFFFF, 0xFFFC, 0xFFF2, 0xFFE3, 0xFFCD, 0xFFB2, 0xFF90, 0xFF69, 0xFF3C, 0xFF09, 0xFED1,
    0xFE94, 0xFE51, 0xFE08, 0xFDBB, 0xFD68, 0xFD10, 0xFCB3, 0xFC51, 0xFBEA, 0xFB7F, 0xFB0E, 0xFA99,
    0xFA1F, 0xF9A1, 0xF91E, 0xF896, 0xF80A, 0xF77A, 0xF6E6, 0xF64E, 0xF5B1, 0xF511, 0xF46D, 0xF3C5,
    0xF319, 0xF26A, 0xF1B7, 0xF101, 0xF048, 0xEF8C, 0xEECC, 0xEE0A, 0xED45, 0xEC7E, 0xEBB4, 0xEAE8,
    0xEA1A, 0xE949, 0xE877, 0xE7A3, 0xE6CE, 0xE5F7, 0xE51F, 0xE446, 0xE36C, 0xE291, 0xE1B6, 0xE0DB,
    0xDFFF, 0xDF23, 0xDE48, 0xDD6D, 0xDC92, 0xDBB8, 0xDADF, 0xDA07, 0xD931, 0xD85B, 0xD787, 0xD6B5,
    0xD5E5, 0xD516, 0xD44A, 0xD380, 0xD2B9, 0xD1F4, 0xD132, 0xD073, 0xCFB6, 0xCEFD, 0xCE47, 0xCD94,
    0xCCE5, 0xCC3A, 0xCB92, 0xCAED, 0xCA4D, 0xC9B1, 0xC918, 0xC884, 0xC7F4, 0xC768, 0xC6E1, 0xC65E,
    0xC5DF, 0xC565, 0xC4F0, 0xC47F, 0xC414, 0xC3AD, 0xC34B, 0xC2EE, 0xC296, 0xC243, 0xC1F6, 0xC1AD,
    0xC16A, 0xC12D, 0xC0F5, 0xC0C2, 0xC095, 0xC06E, 0xC04D, 0xC031, 0xC01B, 0xC00C, 0xC002, 0xBFFF
};
s16 bridgeDownFrames[50] = { 0xBFFF, 0xC02C, 0xC0B2, 0xC194, 0xC2D3, 0xC473, 0xC677, 0xC8E4, 0xCBBE,
                             0xCF09, 0xD2C8, 0xD6FD, 0xDBA7, 0xE0C1, 0xE641, 0xEC1A, 0xF236, 0xF87E,
                             0xFED8, 0xFD7D, 0xFAAD, 0xF82C, 0xF600, 0xF42E, 0xF2B9, 0xF1A5, 0xF0F4,
                             0xF0A7, 0xF0BE, 0xF139, 0xF217, 0xF357, 0xF4F6, 0xF6F2, 0xF945, 0xFBEB,
                             0xFEDC, 0xFF0E, 0xFDD9, 0xFCFC, 0xFC7B, 0xFC55, 0xFC8B, 0xFD1E, 0xFE0B,
                             0xFF4F, 0xFF9D, 0xFF2F, 0xFF1B, 0x0000 };
s16 *animrots[2] = { &bridgeUpFrames, &bridgeDownFrames };
// __attribute__((long_call))
Gfx bowser1flag_Unbenannt_1_ia4_aligner[] = { gsSPEndDisplayList() };
u8 bowser1flag_Unbenannt_1_ia4[] = {
    0xdd, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x39, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x93, 0x31, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x95, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x99, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x93, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xf9, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xfd, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3d, 0xff, 0x51,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3d, 0xff, 0x51, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x5f, 0xff, 0xf5,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xdf, 0xff, 0xb1, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xdf, 0xff, 0xff,
    0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3b, 0xff, 0xff, 0xf5, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0xff, 0xff, 0xff,
    0xd3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x9f, 0xff, 0xff, 0xfb, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1b, 0xff, 0xff, 0xff,
    0xfb, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff, 0x51, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0x93, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xb1, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xf9, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x51, 0x11, 0x11, 0x11, 0x11, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x19, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf5, 0x11, 0x11, 0x11, 0x13, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x51, 0x11, 0x11, 0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x9f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd3, 0x11, 0x11, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfb, 0x31, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xb3, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf9, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x71,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91,
    0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x51, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51,
    0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x1d, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xb1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x13, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x31,
    0x13, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf5, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x15, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x11,
    0x11, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfb, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x11,
    0x11, 0x15, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x11, 0x11, 0x11, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x51, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x11,
    0x11, 0x11, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x11, 0x11, 0x11, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xb1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91, 0x11,
    0x11, 0x11, 0x1b, 0xff, 0xff, 0xff, 0xff, 0x31, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51, 0x11,
    0x11, 0x11, 0x13, 0xdf, 0xff, 0xff, 0xf5, 0x11, 0x11, 0x11, 0x11, 0x1b, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf9, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x31, 0x11,
    0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0x71, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x19, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x15, 0xff, 0xf9, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x7f, 0xd3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xdf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd1, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x17, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf7, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1d, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x71, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf7, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xdf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x13, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd1, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd5, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff, 0x91, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfb, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x5f, 0xff, 0xff, 0xff, 0xff, 0x51, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1d, 0xff, 0xff,
    0xff, 0xff, 0x93, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x13, 0xdf, 0xff, 0xff, 0xfd, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xff,
    0xff, 0xf7, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x3b, 0xff, 0xff, 0xf9, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0xff, 0xff,
    0xff, 0x51, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x13, 0x9f, 0xff, 0xf3, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xdf, 0xff,
    0xd3, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x17, 0xff, 0xd1, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x7f, 0xfb,
    0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x5f, 0x91, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0xb3,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0x31, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0x31,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x91, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x99, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00,
    0x35, 0x15, 0xfb, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x95, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x35, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x93, 0x31, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00,
    0x35, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x39, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xdd, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

};
Gfx mat_bowser1flag_MARIO_layer4[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, 0, 1, 0, COMBINED, SHADE, 0, 0, 0, TEXEL1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_AA_ZB_TEX_EDGE2),
    gsSPTexture(65535, 65535, 0, 0, 1),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, bowser1flag_Unbenannt_1_ia4),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0,
                G_TX_CLAMP | G_TX_NOMIRROR, 7, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 2047, 256),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_4b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0,
                G_TX_CLAMP | G_TX_NOMIRROR, 7, 0),
    gsDPSetTileSize(0, 0, 0, 508, 252),
    gsDPSetPrimColor(0, 0, 0, 254, 254, 255),
    gsSPEndDisplayList(),
};

Gfx mat_revert_bowser1flag_MARIO_layer4[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPEndDisplayList(),
};