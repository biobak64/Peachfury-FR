#include "src/game/envfx_snow.h"

const GeoLayout glowspot_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, glowspot_Plane_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, glowspot_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
