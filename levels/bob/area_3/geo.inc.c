#include "src/game/envfx_snow.h"

const GeoLayout bob_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_cavewalls_005_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Cube_006_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Cube_007_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Cube_011_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Cube_012_mesh),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Cube_014_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_grindspots_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_grindspots_002_mesh),
		GEO_DISPLAY_LIST(LAYER_FORCE, bob_dl_NurbsPath_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_NurbsPath_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_NurbsPath_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_NurbsPath_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_NurbsPath_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_NurbsPath_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_NurbsPath_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_3[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_FLAMING_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 133, 60000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, -47752, 165, 1098, -47752, 164, 1098, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_3_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
