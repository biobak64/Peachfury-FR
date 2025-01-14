#ifndef SCREEN_TRANSITION_H
#define SCREEN_TRANSITION_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "types.h"

enum TextureTransitionID
{
    TEX_TRANS_STAR,
    TEX_TRANS_CIRCLE,
    TEX_TRANS_MARIO,
    TEX_TRANS_BOWSER
};

enum TextureTransitionType
{
    TRANS_TYPE_MIRROR,
    TRANS_TYPE_CLAMP
};

int render_screen_transition(s8 fadeTimer, s8 transType, u8 transTime, struct WarpTransitionData *transData);
Gfx *geo_cannon_circle_base(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);
extern s32 transition_logic(s8 fadeTimer, s8 transType, u8 transTime, struct WarpTransitionData *transData);

#endif // SCREEN_TRANSITION_H
