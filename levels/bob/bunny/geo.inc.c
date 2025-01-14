#include "src/game/envfx_snow.h"

const GeoLayout bunny_geo[] = {
		GEO_SHADOW(0, 150, 100),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 0, -14, 0, 0, 0, bunny_Bone_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_BONE(LAYER_OPAQUE, 0, 21, -9, -26719, 0, 0, bunny_Bone_006_mesh_layer_1),
			GEO_BONE(LAYER_OPAQUE, 0, 46, 0, 0, 0, 0, bunny_head_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_BONE(LAYER_OPAQUE, 8, 13, -5, -3224, -5305, -3914, bunny_ear2_l_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_ear3_l_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 21, 0, 10167, 2939, -3596, bunny_ear3_l_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BONE(LAYER_OPAQUE, -8, 13, -5, -3224, 5305, 3914, bunny_ear2_r_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_ear3_r_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 21, 0, 10167, -2939, 3596, bunny_ear3_r_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, 10, 24, 2, 32569, -1983, 2021, bunny_leg_l_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_foot_l_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 21, 0, 16595, 27382, 2089, bunny_foot_l_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_tip_l_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 11, 0, -637, -3019, 908, bunny_tip_l_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, -10, 24, 2, 32569, 1983, -2021, bunny_leg_r_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_foot_r_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 21, 0, 16595, -27382, -2089, bunny_foot_r_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_tip_r_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 11, 0, -637, 3019, -908, bunny_tip_r_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	//	GEO_DISPLAY_LIST(LAYER_OPAQUE, bunny_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
