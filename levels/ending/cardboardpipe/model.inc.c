Lights1 cardboardpipe_sm64_material_006_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 cardboardpipe_sm64_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx cardboardpipe_pipeside2_ci8_aligner[] = {gsSPEndDisplayList()};
u8 cardboardpipe_pipeside2_ci8[] = {
	0x0, 0x1, 0x2, 0x0, 0x3, 0x4, 0x5, 0x6, 0x7, 
	0x0, 0x8, 0x5, 0x1, 0x9, 0xA, 0x4, 0x5, 0x3, 
	0x3, 0xB, 0xC, 0x5, 0x4, 0x8, 0xC, 0xD, 0xD, 
	0x3, 0x8, 0xE, 0x0, 0x7, 0x0, 0xB, 0x9, 0x9, 
	0x9, 0x3, 0xF, 0x6, 0x1, 0xB, 0x10, 0x7, 0x1, 
	0xC, 0xA, 0x5, 0x3, 0x0, 0x0, 0x3, 0x11, 0x5, 
	0x5, 0x8, 0x0, 0x0, 0x12, 0x7, 0x0, 0xB, 0x0, 
	0x3, 0x0, 0x2, 0x2, 0x2, 0x9, 0xE, 0x9, 0x13, 
	0x10, 0xB, 0x11, 0x14, 0x7, 0x15, 0x4, 0xD, 0x3, 
	0x0, 0x8, 0x15, 0x16, 0x5, 0x9, 0x0, 0xB, 0xC, 
	0x7, 0x17, 0x1, 0x0, 0xC, 0x12, 0x1, 0x18, 0x19, 
	0x2, 0x7, 0x3, 0x0, 0x7, 0x3, 0x0, 0x0, 0x1A, 
	0x1B, 0x9, 0xB, 0x8, 0x1, 0x9, 0xA, 0x1C, 0x1D, 
	0x7, 0x1E, 0x0, 0x8, 0x4, 0x0, 0x1F, 0x1F, 0x0, 
	0x0, 0x2, 0x3, 0x6, 0x20, 0x21, 0x2, 0xF, 0x22, 
	0x1, 0x23, 0xE, 0xC, 0x24, 0x1, 0xE, 0x0, 0x0, 
	0x6, 0x25, 0xE, 0x15, 0x5, 0x6, 0x26, 0x9, 0x4, 
	0xD, 0x27, 0x28, 0x3, 0x3, 0x5, 0x1, 0x3, 0x1B, 
	0x29, 0x1, 0x10, 0x3, 0x22, 0x6, 0x9, 0x2A, 0x5, 
	0x22, 0x2, 0x2, 0xC, 0x4, 0x7, 0x17, 0x2B, 0xC, 
	0x11, 0x1B, 0x19, 0x1, 0x3, 0x14, 0x6, 0x1, 0xB, 
	0x3, 0xD, 0x2C, 0x16, 0x24, 0x2, 0x9, 0x2D, 0x11, 
	0x5, 0x0, 0x8, 0x2E, 0x4, 0x7, 0x7, 0x0, 0x3, 
	0x5, 0x7, 0x1, 0xB, 0x3, 0x2F, 0x7, 0x1, 0xC, 
	0x0, 0x3, 0x7, 0xF, 0x5, 0xC, 0x7, 0x2C, 0x30, 
	0xD, 0x1, 0x0, 0x0, 0x0, 0xD, 0x0, 0xE, 0xE, 
	0xA, 0x5, 0x1B, 0x3, 0x3, 0x22, 0xF, 0x1, 0x0, 
	0xB, 0x4, 0x1A, 0x1, 0xB, 0x8, 0x4, 0x8, 0x0, 
	0x0, 0x31, 0x9, 0x6, 0x32, 0x14, 0x6, 0x22, 0x4, 
	0x5, 0x5, 0x1, 0xE, 0x8, 0x16, 0x14, 0x33, 0x5, 
	0x2E, 0x8, 0x7, 0x6, 0x3, 0x8, 0x0, 0x25, 0x8, 
	0x8, 0x4, 0x11, 0x0, 0x9, 0x0, 0xE, 0xB, 0x19, 
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x37, 0x37, 0x3A, 
	0x38, 0x3B, 0x3C, 0x3D, 0x39, 0x3E, 0x38, 0x38, 0x3D, 
	0x3F, 0x3A, 0x3E, 0x38, 0x3A, 0x3A, 0x3E, 0x36, 0x37, 
	0x3A, 0x40, 0x41, 0x41, 0x3B, 0x6, 0x34, 0x42, 0x41, 
	0x35, 0x43, 0x44, 0x41, 0x42, 0x42, 0x45, 0x45, 0x3B, 
	0x3B, 0x45, 0x46, 0x47, 0x41, 0x48, 0x49, 0x43, 0x42, 
	0x42, 0x42, 0x48, 0x48, 0x42, 0x3B, 0x49, 0x44, 0x46, 
	0x4A, 0xF, 0x6, 0x4B, 0x46, 0x26, 0x26, 0x4C, 0x4A, 
	0x43, 0x43, 0x4C, 0x4A, 0x46, 0x43, 0x26, 0x26, 0x46, 
	0x4D, 0x1E, 0x1E, 0x2, 0x26, 0x43, 0x43, 0x1E, 0x26, 
	0x4A, 0x46, 0x1E, 0x43, 0x2, 0x46, 0x5, 0x1B, 0x20, 
	0x2, 0x9, 0x0, 0x1, 0x34, 0x46, 0x26, 0x19, 0x20, 
	0x34, 0x2, 0x26, 0x19, 0x4E, 0x26, 0x26, 0x4F, 0x17, 
	0x19, 0x50, 0x51, 0x52, 0x26, 0x4F, 0x19, 0x2, 0x2, 
	0x9, 0x26, 0x53, 0x5, 0x25, 0x1, 0x2D, 0x3, 0x22, 
	0x1, 0x1, 0x1, 0x3, 0x7, 0x4F, 0x1, 0x52, 0x1, 
	0x17, 0x2, 0x2B, 0x0, 0x0, 0x1, 0x26, 0x2, 0x54, 
	0x23, 0x4F, 0x1, 0x2, 0x2B, 0x12, 0x19, 0x55, 0x14, 
	0x7, 0x7, 0x8, 0x3, 0x3, 0x0, 0x1, 0x2B, 0x8, 
	0x7, 0x6, 0x0, 0x0, 0x56, 0x17, 0x0, 0xC, 0x0, 
	0x4, 0x23, 0x57, 0x54, 0x9, 0x3, 0x13, 0x0, 0x31, 
	0x9, 0x28, 0x19, 0x58, 0x55, 0x7, 0x2B, 0x8, 0x4, 
	0x56, 0x1F, 0x9, 0x9, 0x0, 0x7, 0x2, 0x9, 0x0, 
	0x56, 0x0, 0x2, 0xB, 0x0, 0x4, 0x0, 0x9, 0x2D, 
	0x0, 0x11, 0x3, 0x1, 0xE, 0x8, 0x5, 0x17, 0x32, 
	0x2F, 0x17, 0x2B, 0x15, 0xA, 0xD, 0x0, 0x2, 0x59, 
	0x2A, 0x3, 0x23, 0x2, 0x9, 0x15, 0xE, 0x9, 0x5A, 
	0xC, 0x4, 0x3, 0x9, 0x2D, 0x15, 0x11, 0x11, 0x0, 
	0xE, 0x15, 0x11, 0x19, 0x58, 0x16, 0x3, 0x8, 0x8, 
	0xA, 0x11, 0x0, 0x0, 0xA, 0x2A, 0x11, 0x0, 0x54, 
	0xE, 0x4, 0x3, 0x8, 0x8, 0x8, 0x11, 0x11, 0x9, 
	0xE, 0x2A, 0x4, 0x0, 0x9, 0xE, 0x15, 0x3, 0x1F, 
	0x32, 0x16, 0x0, 0x9, 0x3, 0xD, 0xD, 0x0, 0x8, 
	0xE, 0x4, 0x4, 0x8, 0x2A, 0x5B, 0x1D, 0x3, 0x3, 
	0x9, 0x5C, 0x8, 0x10, 0xE, 0x9, 0xE, 0x4, 0x7, 
	0x9, 0x9, 0x8, 0x5, 0x3, 0x5D, 0x11, 0x0, 0x0, 
	0x3, 0x53, 0x5, 0x3, 0x15, 0xE, 0x2A, 0x3, 0x9, 
	0x9, 0x2A, 0x11, 0x3, 0xC, 0x59, 0x5E, 0xA, 0x9, 
	0x31, 0x31, 0x59, 0x8, 0xC, 0x0, 0x9, 0x8, 0x3, 
	0x25, 0x32, 0x16, 0xD, 0x5, 0x4, 0x2E, 0x0, 0x3, 
	0x8, 0x0, 0x4, 0x4, 0x9, 0xB, 0xC, 0x11, 0x0, 
	0x9, 0x15, 0x15, 0xA, 0x21, 0x5F, 0x9, 0x8, 0x8, 
	0x9, 0x31, 0x31, 0xC, 0x11, 0x9, 0x58, 0x5, 0x3, 
	0x4, 0x11, 0x1D, 0x4, 0xC, 0xA, 0xA, 0x53, 0x0, 
	0xE, 0xB, 0x0, 0xC, 0x21, 0x9, 0x9, 0x5A, 0x15, 
	0x9, 0x31, 0xE, 0x59, 0xA, 0x0, 0x31, 0x9, 0x2A, 
	0x3, 0x1F, 0x60, 0x5, 0x8, 0xE, 0x2A, 0xA, 0xC, 
	0xC, 0x8, 0x2A, 0x1D, 0xF, 0x10, 0x4, 0xC, 0x8, 
	0x10, 0x0, 0x9, 0x5A, 0x4, 0x4, 0x9, 0x59, 0x5B, 
	0x53, 0x11, 0xA, 0x8, 0xA, 0x0, 0x9, 0x61, 0x62, 
	0x5, 0x2D, 0xE, 0xA, 0x3, 0x3, 0xC, 0x3, 0x5, 
	0x11, 0x8, 0x0, 0x8, 0x8, 0x7, 0x0, 0xE, 0xA, 
	0x11, 0x1, 0x9, 0x8, 0xA, 0xC, 0xC, 0x4, 0xB, 
	0x8, 0x11, 0x2, 0x16, 0x14, 0x12, 0x0, 0xC, 0x11, 
	0x8, 0x0, 0xC, 0x11, 0x53, 0x0, 0x9, 0x8, 0x8, 
	0x4, 0x0, 0xE, 0x63, 0xA, 0x11, 0xE, 0x9, 0xB, 
	0x2A, 0x3, 0x3, 0x9, 0x54, 0x15, 0xC, 0x1, 0x64, 
	0x2C, 0x4F, 0x8, 0x11, 0x4, 0x8, 0xE, 0x2A, 0x11, 
	0x64, 0x4, 0x0, 0xB, 0x0, 0x2A, 0x56, 0x0, 0xB, 
	0x15, 0x3, 0x22, 0x1F, 0x9, 0xE, 0x3, 0x9, 0x52, 
	0x9, 0x15, 0x0, 0x0, 0x61, 0x3, 0xB, 0xB, 0xB, 
	0x53, 0x3, 0x31, 0x8, 0x8, 0x5, 0x3, 0xE, 0x59, 
	0x8, 0xA, 0x0, 0x0, 0xB, 0x15, 0x3, 0x7, 0x9, 
	0xB, 0x0, 0x11, 0x8, 0x5C, 0x0, 0x7, 0x0, 0x9, 
	0x30, 0x65, 0x1, 0xE, 0x9, 0xA, 0x2C, 0x25, 0x0, 
	0x8, 0x2A, 0x17, 0x0, 0x0, 0x4, 0xF, 0x7, 0x0, 
	0x5A, 0xA, 0x3, 0x9, 0x0, 0x0, 0x0, 0x5, 0x17, 
	0x1, 0x10, 0x10, 0x28, 0x19, 0x32, 0x2C, 0x2, 0x2A, 
	0x4, 0x4, 0x14, 0x1, 0xE, 0x8, 0x11, 0x22, 0xC, 
	0xB, 0xA, 0x1A, 0x66, 0x1, 0x15, 0xA, 0x5, 0x6, 
	0x2, 0x9, 0xA, 0x5, 0x33, 0x13, 0x3, 0x3, 0x33, 
	0x18, 0xC, 0x4, 0x8, 0xB, 0x8, 0x5, 0x11, 0xC, 
	0x8, 0x8, 0x11, 0x5, 0x4, 0x2A, 0x8, 0x5, 0x1B, 
	0x3, 0xA, 0x4, 0xF, 0x7, 0x9, 0xE, 0x8, 0x5, 
	0x25, 0xC, 0x8, 0xF, 0x22, 0x19, 0x16, 0x22, 0xF, 
	0x8, 0x2A, 0x11, 0x7, 0x0, 0xB, 0x8, 0x3, 0x22, 
	0x9, 0x0, 0x0, 0x3, 0x25, 0x0, 0xE, 0xA, 0x3, 
	0x1, 0x0, 0x8, 0x0, 0x7, 0x7, 0x3, 0xC, 0x11, 
	0x7, 0x2, 0x32, 0x3, 0x0, 0x9, 0x2D, 0x4, 0x0, 
	0x54, 0xE, 0xE, 0x11, 0x11, 0x0, 0xC, 0xE, 0x10, 
	0x3, 0x4, 0xA, 0xC, 0x22, 0x19, 0x54, 0xB, 0x11, 
	0x3, 0x11, 0xB, 0x2B, 0x8, 0x3, 0x0, 
};

Gfx cardboardpipe_pipeside2_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 cardboardpipe_pipeside2_ci8_pal_rgba16[] = {
	0x4D, 0xD, 0x4C, 0xCD, 0x44, 0x8B, 0x55, 0x4F, 0x55, 
	0x8F, 0x5D, 0x91, 0x54, 0xCF, 0x55, 0xF, 0x4D, 0x4D, 
	0x44, 0xCB, 0x55, 0x8D, 0x4D, 0xB, 0x55, 0x4D, 0x65, 
	0x91, 0x45, 0xB, 0x5D, 0x4F, 0x55, 0xD, 0x5D, 0x8F, 
	0x5D, 0xF, 0x54, 0xCD, 0x65, 0x93, 0x4D, 0x4B, 0x65, 
	0xD1, 0x4C, 0xCF, 0x4C, 0x8F, 0x4C, 0x8D, 0x65, 0x51, 
	0x5D, 0x11, 0x45, 0x8B, 0x5D, 0xCF, 0x3C, 0x9, 0x44, 
	0xCD, 0x54, 0x8F, 0x44, 0x89, 0x5D, 0x51, 0x3C, 0x8B, 
	0x55, 0x51, 0x4D, 0xF, 0x44, 0x4B, 0x5C, 0xD1, 0x55, 
	0x11, 0x5C, 0x8F, 0x4D, 0x8D, 0x4C, 0xCB, 0x65, 0x53, 
	0x45, 0xD, 0x55, 0xCF, 0x65, 0xD3, 0x6E, 0x13, 0x3C, 
	0xC9, 0x66, 0x11, 0x54, 0xD1, 0x4C, 0x4D, 0x43, 0xCB, 
	0x3B, 0x9, 0x32, 0xC9, 0x33, 0x9, 0x32, 0xC7, 0x2A, 
	0xC7, 0x3B, 0x49, 0x3A, 0xC9, 0x2A, 0x87, 0x33, 0x7, 
	0x22, 0x85, 0x2B, 0x7, 0x33, 0x49, 0x3B, 0x89, 0x3B, 
	0xC9, 0x33, 0x89, 0x3B, 0x8B, 0x44, 0xB, 0x43, 0x8B, 
	0x33, 0x47, 0x33, 0x87, 0x43, 0xCD, 0x4C, 0xD, 0x3B, 
	0xCB, 0x3C, 0xB, 0x44, 0x4D, 0x44, 0x8D, 0x4C, 0x4B, 
	0x44, 0x49, 0x3C, 0x49, 0x5D, 0xD1, 0x3C, 0x89, 0x6E, 
	0x15, 0x4D, 0x4F, 0x34, 0x49, 0x6E, 0x53, 0x45, 0x4B, 
	0x45, 0x9, 0x55, 0xCD, 0x3C, 0xCB, 0x5E, 0x11, 0x44, 
	0xC9, 0x3C, 0x87, 0x76, 0x53, 0x76, 0x15, 0x6D, 0xD3, 
	0x3D, 0x9, 0x66, 0x13, 0x5D, 0x53, 0x65, 0x13, 
};

Gfx cardboardpipe_item_1680_heart_sokumen001__ci8_aligner[] = {gsSPEndDisplayList()};
u8 cardboardpipe_item_1680_heart_sokumen001__ci8[] = {
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 
	0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 
	0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 
	0x3, 0x3, 0x3, 0x3, 0x4, 0x4, 0x4, 0x4, 0x2, 
	0x2, 0x2, 0x2, 0x5, 0x5, 0x5, 0x5, 0x6, 0x6, 
	0x7, 0x8, 0x4, 0x9, 0xA, 0xA, 0x5, 0x5, 0x5, 
	0x5, 0xB, 0xB, 0xB, 0xB, 0x6, 0xC, 0xD, 0xD, 
	0xE, 0xE, 0xF, 0xF, 0xB, 0xB, 0xB, 0xB, 0x10, 
	0x10, 0x10, 0x10, 0xC, 0xD, 0xD, 0xD, 0xE, 0xE, 
	0x11, 0xF, 0x10, 0x10, 0x10, 0x10, 0x12, 0x12, 0x12, 
	0x12, 0xE, 0xE, 0xE, 0x13, 0x13, 0xE, 0x11, 0x14, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x15, 0xE, 
	0xE, 0x13, 0x13, 0x13, 0x13, 0x11, 0x11, 0x12, 0x12, 
	0x12, 0x12, 0x16, 0x16, 0x7, 0x17, 0x11, 0x18, 0x12, 
	0x12, 0x16, 0x16, 0x17, 0x3, 0x19, 0x19, 0x12, 0x12, 
	0x16, 0x16, 0x7, 0x3, 0x11, 0x14, 0x12, 0x12, 0x16, 
	0x16, 0x8, 0x3, 0x1A, 0x19, 0x12, 0x12, 0x16, 0x16, 
	0x17, 0x3, 0x11, 0xF, 0x12, 0x12, 0x16, 0x16, 0x7, 
	0x3, 0x1B, 0x19, 0x12, 0x12, 0x16, 0x1C, 0x3, 0x3, 
	0x18, 0xF, 0x12, 0x12, 0x16, 0x16, 0x7, 0x17, 0x1B, 
	0x1A, 0x12, 0x12, 0x1D, 0x17, 0x17, 0x1D, 0x1E, 0x1E, 
	0x1E, 0x1E, 0x1D, 0x1D, 0x1D, 0x1D, 0x17, 0x17, 0x1D, 
	0x1D, 0x1F, 0x1F, 0x1F, 0x1F, 0x20, 0x20, 0x20, 0x20, 
	0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1, 
	0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 
	0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 
};

Gfx cardboardpipe_item_1680_heart_sokumen001__ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 cardboardpipe_item_1680_heart_sokumen001__ci8_pal_rgba16[] = {
	0xED, 0x63, 0xBB, 0xD7, 0x7B, 0x57, 0x8B, 0x53, 0x73, 
	0x11, 0x28, 0xC3, 0x38, 0xC1, 0x51, 0x85, 0x6A, 0x4B, 
	0x52, 0x9, 0x28, 0xC1, 0x29, 0x9, 0x62, 0x7, 0x8B, 
	0x51, 0x83, 0x11, 0x49, 0x85, 0x39, 0x8B, 0x83, 0x53, 
	0x41, 0xCD, 0x59, 0xC7, 0x5A, 0x9, 0x4A, 0xF, 0x39, 
	0xCB, 0x7A, 0xCF, 0x6A, 0xCF, 0x51, 0xC9, 0x6A, 0x8F, 
	0x8B, 0x97, 0x52, 0x91, 0x6A, 0x9, 0x62, 0x9, 0xA3, 
	0xD7, 0xA4, 0x19, 
};

Vtx cardboardpipe_skinned_002_mesh_vtx_cull[8] = {
	{{{-153, 0, -153},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-153, 0, 154},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-153, 205, 154},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-153, 205, -153},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{154, 0, -153},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{154, 0, 154},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{154, 205, 154},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{154, 205, -153},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx cardboardpipe_skinned_002_mesh_vtx_0[42] = {
	{{{108, 205, 0},0, {-1495, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{108, 10, 0},0, {-1495, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 10, 76},0, {-1000, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 205, 76},0, {-1000, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{0, 10, 108},0, {-505, 1005},{0x1, 0x1, 0x1, 0xFF}}},
	{{{0, 205, 108},0, {-505, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-75, 10, 76},0, {-16, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-75, 205, 76},0, {-16, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-107, 10, 0},0, {479, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-107, 205, 0},0, {479, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-75, 10, -75},0, {968, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-75, 205, -75},0, {968, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{0, 10, -107},0, {1457, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{0, 205, -107},0, {1457, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{76, 10, -75},0, {1952, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 205, -75},0, {1952, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{108, 10, 0},0, {2441, 1005},{0x0, 0x0, 0x0, 0xFF}}},
	{{{108, 205, 0},0, {2441, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{109, 205, 109},0, {-3002, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{109, 0, 109},0, {-3002, 1005},{0x8F, 0x8E, 0x8E, 0xFF}}},
	{{{154, 0, 0},0, {-2004, 1005},{0x8F, 0x8E, 0x8E, 0xFF}}},
	{{{154, 205, 0},0, {-2004, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{109, 0, -108},0, {-1014, 1005},{0x8F, 0x8E, 0x8E, 0xFF}}},
	{{{109, 205, -108},0, {-1014, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{0, 0, -153},0, {-16, 1005},{0x8F, 0x86, 0x82, 0xFF}}},
	{{{0, 205, -153},0, {-16, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-108, 0, -108},0, {974, 1005},{0x8F, 0x89, 0x87, 0xFF}}},
	{{{-108, 205, -108},0, {974, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-153, 0, 0},0, {1964, 1005},{0x8F, 0x85, 0x82, 0xFF}}},
	{{{-153, 205, 0},0, {1964, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-108, 0, 109},0, {2962, 1005},{0x8F, 0x81, 0x79, 0xFF}}},
	{{{-108, 205, 109},0, {2962, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-108, 205, 109},0, {2962, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{-108, 0, 109},0, {2962, 1005},{0x8F, 0x81, 0x79, 0xFF}}},
	{{{0, 0, 154},0, {3952, 1005},{0x8F, 0x8E, 0x8E, 0xFF}}},
	{{{0, 205, 154},0, {3952, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{109, 0, 109},0, {4950, 1005},{0x8F, 0x8E, 0x8E, 0xFF}}},
	{{{109, 205, 109},0, {4950, -16},{0xC0, 0xBF, 0xBF, 0xFF}}},
	{{{1, 10, 153},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{153, 10, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{0, 10, -152},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-152, 10, 1},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Gfx cardboardpipe_skinned_002_mesh_tri_0[] = {
	gsSPVertex(cardboardpipe_skinned_002_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 13, 11, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 15, 13, 0),
	gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
	gsSP2Triangles(23, 22, 24, 0, 23, 24, 25, 0),
	gsSP2Triangles(26, 25, 24, 0, 26, 27, 25, 0),
	gsSP2Triangles(28, 27, 26, 0, 28, 29, 27, 0),
	gsSP2Triangles(29, 28, 30, 0, 29, 30, 31, 0),
	gsSPVertex(cardboardpipe_skinned_002_mesh_vtx_0 + 32, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSPEndDisplayList(),
};Vtx cardboardpipe_skinned_002_mesh_vtx_1[16] = {
	{{{109, 205, 109},0, {1079, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{76, 205, 76},0, {824, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{0, 205, 108},0, {-170, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{154, 205, 0},0, {-386, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{108, 205, 0},0, {-170, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{76, 205, -75},0, {824, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{109, 205, -108},0, {1079, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{0, 205, -107},0, {-170, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{0, 205, -153},0, {-386, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{-75, 205, -75},0, {824, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{-108, 205, -108},0, {1079, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{-107, 205, 0},0, {-170, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{-153, 205, 0},0, {-386, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{-75, 205, 76},0, {824, -16},{0xBA, 0xBB, 0xBA, 0xFF}}},
	{{{-108, 205, 109},0, {1079, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
	{{{0, 205, 154},0, {-386, 496},{0xFE, 0xFF, 0xFE, 0xFF}}},
};

Gfx cardboardpipe_skinned_002_mesh_tri_1[] = {
	gsSPVertex(cardboardpipe_skinned_002_mesh_vtx_1 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(1, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 3, 6, 0, 7, 5, 6, 0),
	gsSP2Triangles(7, 6, 8, 0, 9, 7, 8, 0),
	gsSP2Triangles(9, 8, 10, 0, 11, 9, 10, 0),
	gsSP2Triangles(11, 10, 12, 0, 13, 11, 12, 0),
	gsSP2Triangles(13, 12, 14, 0, 14, 2, 13, 0),
	gsSP2Triangles(14, 15, 2, 0, 0, 2, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_cardboardpipe_sm64_material_006[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cardboardpipe_pipeside2_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 102),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, cardboardpipe_pipeside2_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(cardboardpipe_sm64_material_006_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_cardboardpipe_sm64_material_006[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx mat_cardboardpipe_sm64_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cardboardpipe_item_1680_heart_sokumen001__ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 32),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 16, cardboardpipe_item_1680_heart_sokumen001__ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 60, 60),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPSetLights1(cardboardpipe_sm64_material_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_cardboardpipe_sm64_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx cardboardpipe_skinned_002_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(cardboardpipe_skinned_002_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_cardboardpipe_sm64_material_006),
	gsSPDisplayList(cardboardpipe_skinned_002_mesh_tri_0),
	gsSPDisplayList(mat_revert_cardboardpipe_sm64_material_006),
	gsSPDisplayList(mat_cardboardpipe_sm64_material),
	gsSPDisplayList(cardboardpipe_skinned_002_mesh_tri_1),
	gsSPDisplayList(mat_revert_cardboardpipe_sm64_material),
	gsSPEndDisplayList(),
};



Gfx cardboardpipe_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
