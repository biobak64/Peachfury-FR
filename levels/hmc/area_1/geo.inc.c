#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, hmc_dl_AAAAAAABackGround_003_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_AAAABShadows_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AAGeometry_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BGeometry_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_BGeometry_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_BGeometry_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_BGeometry_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BGeometry_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 40000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -1, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
