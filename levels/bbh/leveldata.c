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
#include "levels/bbh/texture.inc.c"
#include "levels/bbh/leveldata.inc.c"

#include "levels/bbh/lightning/model.inc.c"
#include "levels/bbh/ghostsail/anims/data.inc.c"
#include "levels/bbh/ghostsail/anims/table.inc.c"
#include "levels/bbh/cannonbarrelcoll/collision.inc.c"
#include "levels/bbh/ghostplatform/model.inc.c"
#include "levels/bbh/ghostlantern/model.inc.c"
#include "levels/bbh/ghostplatform/collision.inc.c"
#include "levels/bbh/destroybarrel/model.inc.c"
#include "levels/bbh/destroybarrel/collision.inc.c"
#include "levels/bbh/booguybarrell/model.inc.c"
#include "levels/bbh/booguybarrell/anims/data.inc.c"
#include "levels/bbh/booguybarrell/anims/table.inc.c"
#include "levels/bbh/floorbreak/model.inc.c"
#include "levels/bbh/floorbreak/collision.inc.c"
#include "levels/bbh/booguy/model.inc.c"
#include "levels/bbh/booguy/anims/data.inc.c"
#include "levels/bbh/booguy/anims/table.inc.c"
#include "levels/bbh/jokeUnagi/model.inc.c"
#include "levels/bbh/jokeUnagi/anims/data.inc.c"
#include "levels/bbh/jokeUnagi/anims/table.inc.c"
#include "levels/bbh/jellyblock/model.inc.c"
#include "levels/bbh/jellyblock/collision.inc.c"
#include "levels/bbh/paintguy/model.inc.c"
#include "levels/bbh/wallsword/model.inc.c"
#include "levels/bbh/tunnel/model.inc.c"
#include "levels/bbh/tunnel/collision.inc.c"
#include "levels/bbh/tunnel2/model.inc.c"
#include "levels/bbh/tunnel2/collision.inc.c"
#include "levels/bbh/chandelier/model.inc.c"
#include "levels/bbh/chandelier/collision.inc.c"
#include "levels/bbh/pushcargobox/model.inc.c"
#include "levels/bbh/pushcargobox/collision.inc.c"
#include "levels/bbh/pushshelf/model.inc.c"
#include "levels/bbh/pushshelf/collision.inc.c"
#include "levels/bbh/ropebridge/model.inc.c"
#include "levels/bbh/ropebridge/collision.inc.c"
#include "levels/bbh/crumblefloor/model.inc.c"
#include "levels/bbh/crumblefloor/collision.inc.c"
#include "levels/bbh/shyguyblock/model.inc.c"
#include "levels/bbh/shyguyblock/collision.inc.c"
#include "levels/bbh/Shyguysays/model.inc.c"
#include "levels/bbh/Shyguysays/anims/data.inc.c"
#include "levels/bbh/Shyguysays/anims/table.inc.c"
#include "levels/bbh/guybed/model.inc.c"
#include "levels/bbh/guybed/collision.inc.c"
#include "levels/bbh/movecrate/model.inc.c"
#include "levels/bbh/movecrate/collision.inc.c"
#include "levels/bbh/rumbottle/model.inc.c"
#include "levels/bbh/shyguycaptain/model.inc.c"
#include "levels/bbh/shyguycaptain/backupVerts.inc.c"
#include "levels/bbh/shyguycaptain/anims/data.inc.c"
#include "levels/bbh/shyguycaptain/anims/table.inc.c"
#include "levels/bbh/fallplatform1/model.inc.c"
#include "levels/bbh/fallplatform1/collision.inc.c"
#include "levels/bbh/fallplatform2/model.inc.c"
#include "levels/bbh/fallplatform2/collision.inc.c"
#include "levels/bbh/lineplatform/model.inc.c"
#include "levels/bbh/lineplatform/collision.inc.c"