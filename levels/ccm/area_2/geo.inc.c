#include "src/game/envfx_snow.h"

const GeoLayout ccm_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5714, -725, 10792, ccm_dl_AnimtedMice_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Circle_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Cube_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Plane_004_mesh_layer_4),
		GEO_ASM(2, geo_render_mirror_mario),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Plane_009_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Plane_009_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_010_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Plane_010_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_dl_Plane_013_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_dl_Plane_024_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 281, 0, -2253, ccm_dl_Plane_026_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_dl_Plane_028_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Plane_029_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_031_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Plane_031_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccm_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 28192, 0, 0, 28192, -1, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ccm_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
