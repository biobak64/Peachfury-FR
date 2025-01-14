const Collision lavarock4_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-338, -23, -32),
	COL_VERTEX(-189, 151, -29),
	COL_VERTEX(-1, 151, -358),
	COL_VERTEX(32, -23, -467),
	COL_VERTEX(23, 151, 306),
	COL_VERTEX(23, -23, 418),
	COL_VERTEX(344, -23, -16),
	COL_VERTEX(190, 151, -18),
	COL_TRI_INIT(TERRAIN(3,0,0,0,SPECFLAG_CLIMBABLE,0x0015), 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(2, 1, 4),
	COL_TRI(2, 4, 7),
	COL_TRI(7, 6, 3),
	COL_TRI(7, 3, 2),
	COL_TRI(1, 0, 5),
	COL_TRI(1, 5, 4),
	COL_TRI_STOP(),
	COL_END()
};
