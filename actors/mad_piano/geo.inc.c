#include "src/game/envfx_snow.h"

const GeoLayout mad_piano_geo[] = {
	GEO_CULLING_RADIUS(1500),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 150, 400),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mad_piano_000_offset_001_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -141, -546, 218, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mad_piano_000_offset_003_mesh_layer_1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mad_piano_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
