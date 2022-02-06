const Collision lavarock1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(10),
	COL_VERTEX(200, 151, 200),
	COL_VERTEX(252, 151, -135),
	COL_VERTEX(-8, 151, -248),
	COL_VERTEX(-12, -23, -347),
	COL_VERTEX(-324, -23, -192),
	COL_VERTEX(-232, 151, -137),
	COL_VERTEX(-200, 151, 200),
	COL_VERTEX(-279, -23, 279),
	COL_VERTEX(279, -23, 279),
	COL_VERTEX(353, -23, -189),
	COL_TRI_INIT(TERRAIN(3,0,0,0,SPECFLAG_CLIMBABLE,0x0015), 13),
	COL_TRI(0, 1, 2),
	COL_TRI(2, 3, 4),
	COL_TRI(2, 4, 5),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 0),
	COL_TRI(1, 9, 3),
	COL_TRI(1, 3, 2),
	COL_TRI(0, 8, 9),
	COL_TRI(0, 9, 1),
	COL_TRI(5, 4, 7),
	COL_TRI(5, 7, 6),
	COL_TRI(5, 6, 2),
	COL_TRI(6, 0, 2),
	COL_TRI_STOP(),
	COL_END()
};