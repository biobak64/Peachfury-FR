#include "src/game/envfx_snow.h"

const GeoLayout swingvine_geo[] = {
	GEO_CULLING_RADIUS(4000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_005_skinned_mesh_layer_1),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, swingvine_Bone_005_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_001_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -200, 0, swingvine_Bone_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_002_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -200, 0, swingvine_Bone_002_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_003_skinned_mesh_layer_1),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -200, 0, swingvine_Bone_003_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_Bone_004_skinned_mesh_layer_1),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -200, 0, swingvine_Bone_004_mesh_layer_1),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, swingvine_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};