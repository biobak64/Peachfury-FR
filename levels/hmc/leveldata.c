#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/hmc/texture.inc.c"
#include "levels/hmc/areas/1/1/model.inc.c"
#include "levels/hmc/areas/1/2/model.inc.c"
#include "levels/hmc/areas/1/3/model.inc.c"
#include "levels/hmc/areas/1/4/model.inc.c"
#include "levels/hmc/areas/1/5/model.inc.c"
#include "levels/hmc/areas/1/6/model.inc.c"
#include "levels/hmc/areas/1/7/model.inc.c"
#include "levels/hmc/areas/1/8/model.inc.c"
#include "levels/hmc/areas/1/9/model.inc.c"
#include "levels/hmc/areas/1/10/model.inc.c"
#include "levels/hmc/areas/1/11/model.inc.c"
#include "levels/hmc/areas/1/12/model.inc.c"
#include "levels/hmc/areas/1/13/model.inc.c"
#include "levels/hmc/areas/1/14/model.inc.c"
#include "levels/hmc/areas/1/15/model.inc.c"
#include "levels/hmc/areas/1/16/model.inc.c"
#include "levels/hmc/areas/1/17/model.inc.c"
#include "levels/hmc/areas/1/18/model.inc.c"
#include "levels/hmc/areas/1/19/model.inc.c"
#include "levels/hmc/areas/1/20/model.inc.c"
#include "levels/hmc/areas/1/21/model.inc.c"
#include "levels/hmc/areas/1/22/model.inc.c"
#include "levels/hmc/areas/1/23/model.inc.c"
#include "levels/hmc/areas/1/24/model.inc.c"
#include "levels/hmc/areas/1/25/model.inc.c"
#include "levels/hmc/areas/1/26/model.inc.c"
#include "levels/hmc/areas/1/27/model.inc.c"
#include "levels/hmc/areas/1/28/model.inc.c"
#include "levels/hmc/areas/1/grill_door/model.inc.c"
#include "levels/hmc/areas/1/29/model.inc.c"
#include "levels/hmc/areas/1/30/model.inc.c"
#include "levels/hmc/areas/1/31/model.inc.c"
#include "levels/hmc/areas/1/32/model.inc.c"
#include "levels/hmc/elevator_platform/model.inc.c"
#include "levels/hmc/arrow_platform/model.inc.c"
#include "levels/hmc/arrow_platform_button/model.inc.c"
#include "levels/hmc/rolling_rock/model.inc.c"
#include "levels/hmc/rolling_rock_fragment_1/model.inc.c"
#include "levels/hmc/rolling_rock_fragment_2/model.inc.c"
#include "levels/hmc/areas/1/painting.inc.c"
#include "levels/hmc/areas/1/collision.inc.c"
#include "levels/hmc/areas/1/macro.inc.c"
#include "levels/hmc/areas/1/room.inc.c"
#include "levels/hmc/elevator_platform/collision.inc.c"
#include "levels/hmc/areas/1/grill_door/collision.inc.c" // This is odd, but the model data for this is in the middle of area 1. I have to conclude it is an area local object, despite the fact it has collision. Let's hope this is the only oddity...
#include "levels/hmc/arrow_platform/collision.inc.c"
#include "levels/hmc/arrow_platform_button/collision.inc.c"
#include "levels/hmc/areas/1/trajectory.inc.c"
#include "levels/hmc/areas/1/movtext.inc.c"
#include "levels/hmc/leveldata.inc.c"

#include "levels/hmc/easterhead/model.inc.c"
#include "levels/hmc/easterhead/collision.inc.c"
#include "levels/hmc/boss1/model.inc.c"
#include "levels/hmc/boss2/model.inc.c"
#include "levels/hmc/boss3/model.inc.c"
#include "levels/hmc/lavarock1/model.inc.c"
#include "levels/hmc/lavarock1/collision.inc.c"
#include "levels/hmc/lavarock2/model.inc.c"
#include "levels/hmc/lavarock2/collision.inc.c"
#include "levels/hmc/lavarock3/collision.inc.c"
#include "levels/hmc/lavarock3/model.inc.c"
#include "levels/hmc/lavarock4/model.inc.c"
#include "levels/hmc/lavarock4/collision.inc.c"
#include "levels/hmc/seesawrock/model.inc.c"
#include "levels/hmc/seesawplatform/model.inc.c"
#include "levels/hmc/seesawplatform/collision.inc.c"
#include "levels/hmc/seesawrock/collision.inc.c"
#include "levels/hmc/diplosaurus/model.inc.c"
#include "levels/hmc/diplosaurus/anims/data.inc.c"
#include "levels/hmc/diplosaurus/anims/table.inc.c"
#include "levels/hmc/nessie/model.inc.c"
#include "levels/hmc/nessie/anims/data.inc.c"
#include "levels/hmc/nessie/anims/table.inc.c"
#include "levels/hmc/nessie/collision.inc.c"
#include "levels/hmc/dorrieeyes/model.inc.c"
#include "levels/hmc/bounceShroom/model.inc.c"
#include "levels/hmc/bounceShroom/collision.inc.c"
#include "levels/hmc/bounceShroom2/collision.inc.c"
#include "levels/hmc/bounceShroom2/model.inc.c"
#include "levels/hmc/bendleaf/model.inc.c"
#include "levels/hmc/bendleaf/collision.inc.c"
#include "levels/hmc/swingvine/model.inc.c"
#include "levels/hmc/swingVine/anims/data.inc.c"
#include "levels/hmc/swingVine/anims/table.inc.c"
#include "levels/hmc/reznor/model.inc.c"
#include "levels/hmc/reznor/anims/data.inc.c"
#include "levels/hmc/reznor/anims/table.inc.c"
#include "levels/hmc/yoshimama/model.inc.c"
#include "levels/hmc/yoshimama/anims/data.inc.c"
#include "levels/hmc/yoshimama/anims/table.inc.c"
#include "levels/hmc/babyegg/model.inc.c"
#include "levels/hmc/mamaeyes/model.inc.c"
#include "levels/hmc/fakebush/model.inc.c"
#include "levels/hmc/fakebush/collision.inc.c"
#include "levels/hmc/yoshiDipshit1/model.inc.c"
#include "levels/hmc/yoshiDipshit1/anims/data.inc.c"
#include "levels/hmc/yoshiDipshit1/anims/table.inc.c"
#include "levels/hmc/dipshit2/model.inc.c"
#include "levels/hmc/dipshit2/anims/data.inc.c"
#include "levels/hmc/dipshit2/anims/table.inc.c"
#include "levels/hmc/dipshit3/model.inc.c"
#include "levels/hmc/dipshit3/anims/data.inc.c"
#include "levels/hmc/dipshit3/anims/table.inc.c"
#include "levels/hmc/crackedEgg/model.inc.c"
#include "levels/hmc/bronchiosaurus/model.inc.c"
#include "levels/hmc/bronchiosaurus/anims/data.inc.c"
#include "levels/hmc/bronchiosaurus/anims/table.inc.c"
#include "levels/hmc/bronchiosaurus/collision.inc.c"
#include "levels/hmc/bronchioeyes/model.inc.c"
#include "levels/hmc/vulcanboulder/model.inc.c"
#include "levels/hmc/vulcanboulderpart/model.inc.c"
#include "levels/hmc/trex/model.inc.c"
#include "levels/hmc/trex/anims/data.inc.c"
#include "levels/hmc/trex/anims/table.inc.c"
#include "levels/hmc/trexEyes/model.inc.c"
#include "levels/hmc/goomflagg/model.inc.c"
#include "levels/hmc/goomflagg_geo/anims/data.inc.c"
#include "levels/hmc/goomflagg_geo/anims/table.inc.c"
#include "levels/hmc/peachflag/model.inc.c"
#include "levels/hmc/glowspot/model.inc.c"
#include "levels/hmc/chuckflag/model.inc.c"
#include "levels/hmc/silverstara/model.inc.c"
#include "levels/hmc/rotatething/model.inc.c"
#include "levels/hmc/rotatething/collision.inc.c"
#include "levels/hmc/shipwings/model.inc.c"
#include "levels/hmc/shipwings/anims/data.inc.c"
#include "levels/hmc/shipwings/anims/table.inc.c"
#include "levels/hmc/bbarrel/model.inc.c"
#include "levels/hmc/bbarrel/collision.inc.c"
#include "levels/hmc/windmill2/model.inc.c"
#include "levels/hmc/windmill2/collision.inc.c"
#include "levels/hmc/bowserflag/model.inc.c"
#include "levels/hmc/logo/model.inc.c"
#include "levels/hmc/peachy/model.inc.c"
#include "levels/hmc/peachy/anims/data.inc.c"
#include "levels/hmc/peachy/anims/table.inc.c"