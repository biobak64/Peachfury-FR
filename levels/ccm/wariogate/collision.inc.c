const Collision wariogate_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(213, 318, 60),
	COL_VERTEX(213, 1, 60),
	COL_VERTEX(-97, 1, -198),
	COL_VERTEX(-97, 318, -198),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};