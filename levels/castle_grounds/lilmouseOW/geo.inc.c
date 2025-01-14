#include "src/game/envfx_snow.h"

const GeoLayout lilmouseOW_option_000[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 20, 0, 90, -90, -90),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 15, 0, 0, 0, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lilmouseOW_option_001[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 20, 0, 90, -90, -90),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 15, 0, 0, 0, 0, lilmouseOW_Bone_option1_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lilmouseOW_option_002[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 20, 0, 90, -90, -90),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 15, 0, 0, 0, 0, lilmouseOW_Bone_option2_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lilmouseOW_option_003[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 20, 0, 90, -90, -90),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 15, 0, 0, 0, 0, lilmouseOW_Bone_option3_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lilmouseOW_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, 19, 3, 0, 0, 0, lilmouseOW_Bone_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_Bone_002_skinned_mesh_layer_1),
			GEO_BONE(LAYER_OPAQUE, 0, 23, 0, 11874, 0, 0, lilmouseOW_Bone_002_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_Bone_003_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 26, 0, 2768, 0, 0, lilmouseOW_Bone_003_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 13, 10, -28, -12490, -8756, 3962, lilmouseOW_ear2_l_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, -13, 10, -28, -12490, 8756, -3962, lilmouseOW_ear2_r_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, 0, 5, -27, -16384, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_Bone_006_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 23, 0, 0, 0, 0, lilmouseOW_Bone_006_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_Bone_007_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 20, 0, 1244, 0, 0, lilmouseOW_Bone_007_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, 22, 25, 0, 0, 0, -16384, lilmouseOW_arm2_l_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_arm3_l_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 11, 0, 0, 0, -967, lilmouseOW_arm3_l_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, -22, 25, 0, 0, 0, 16384, lilmouseOW_arm2_r_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_arm3_r_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 0, 11, 0, 0, 0, 967, lilmouseOW_arm3_r_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_SWITCH_CASE(5, geo_switch_anim_state),
					GEO_OPEN_NODE(),
						GEO_NODE_START(),
						GEO_OPEN_NODE(),
							GEO_BONE(LAYER_OPAQUE, 0, 20, 4, 16384, 0, -45, lilmouseOW_arm3_r_002_mesh_layer_1),
						GEO_CLOSE_NODE(),
						GEO_BRANCH(1, lilmouseOW_option_000),
						GEO_BRANCH(1, lilmouseOW_option_001),
						GEO_BRANCH(1, lilmouseOW_option_002),
						GEO_BRANCH(1, lilmouseOW_option_003),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_BONE(LAYER_OPAQUE, 17, -12, 0, 16362, -3, 31140, lilmouseOW_leg2_l_mesh_layer_1),
			GEO_BONE(LAYER_OPAQUE, -17, -12, 0, 16362, 3, -31141, lilmouseOW_leg2_r_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lilmouseOW_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
