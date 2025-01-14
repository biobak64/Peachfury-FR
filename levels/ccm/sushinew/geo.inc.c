#include "src/game/envfx_snow.h"

const GeoLayout sushinew_geo[] = {
		GEO_CULLING_RADIUS(800),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, sushinew_000_offset_001_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ASM(0, geo_update_body_rot_from_parent),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, sushinew_000_offset_002_skinned_mesh_layer_1),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 201, 0, 0, sushinew_000_offset_002_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_DISPLAY_LIST(LAYER_OPAQUE, sushinew_000_offset_003_skinned_mesh_layer_1),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 415, 0, 0, sushinew_000_offset_003_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_OPAQUE, sushinew_000_offset_004_skinned_mesh_layer_1),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 486, 0, 0, sushinew_000_offset_004_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, NULL),
					GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, sushinew_004_offset_mesh_layer_4),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sushinew_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sushinew_material_revert_render_settings),
	GEO_END(),
};
