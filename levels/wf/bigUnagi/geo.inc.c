#include "src/game/envfx_snow.h"

const GeoLayout bigUnagi_geo[] = {
	GEO_CULLING_RADIUS(6000),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(8000),
		GEO_OPEN_NODE(),
			GEO_ASM(1, set_prim_to_opacity),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, -7389, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_000_offset_002_skinned_mesh_layer_1),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 1960, 0, 0, bigUnagi_000_offset_002_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_000_offset_003_skinned_mesh_layer_1),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 3952, 0, 0, bigUnagi_000_offset_003_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_000_offset_004_skinned_mesh_layer_1),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 3800, 0, 0, bigUnagi_000_offset_004_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(2, geo_switch_anim_state),
									GEO_OPEN_NODE(),
										GEO_NODE_START(),
										GEO_OPEN_NODE(),
											GEO_NODE_START(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_000_offset_005_skinned_mesh_layer_1),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -2032, 0, 0, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, bigUnagi_000_offset_005_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_ALPHA, 4216, 0, 0, NULL),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(LAYER_OPAQUE, 1808, 520, 0, NULL),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, NULL),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, bigUnagi_001_offset_mesh_layer_1),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
								GEO_ANIMATED_PART(LAYER_ALPHA, 4216, 0, 0, NULL),
								GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_003_offset_skinned_mesh_layer_1),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 4216, 0, 0, bigUnagi_003_offset_mesh_layer_1),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 4216, 0, 0, NULL),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bigUnagi_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
