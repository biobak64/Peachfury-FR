Lights1 cloudcap_M_Logo_lights = gdSPDefLights1(
	0x72, 0x75, 0x72,
	0xE5, 0xEA, 0xE5, 0x28, 0x28, 0x28);

Lights1 cloudcap_CloudCap_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx cloudcap_ClouMS02_ci8_aligner[] = {gsSPEndDisplayList()};
u8 cloudcap_ClouMS02_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x05, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x04, 0x03, 0x07, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 
	0x07, 0x08, 0x09, 0x09, 0x0a, 0x0b, 0x0b, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x07, 0x09, 
	0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0c, 0x0c, 0x02, 0x0d, 0x0d, 
	0x0e, 0x0f, 0x0f, 0x0f, 0x0b, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x10, 0x04, 0x07, 0x0a, 0x11, 0x0d, 0x0d, 
	0x0e, 0x0f, 0x0f, 0x0f, 0x0b, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x12, 0x05, 0x02, 0x0a, 0x0d, 0x0d, 0x0d, 0x0b, 
	0x11, 0x0b, 0x0f, 0x0f, 0x0b, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x02, 0x0b, 0x13, 0x0d, 0x0b, 0x11, 0x0a, 
	0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
	0x07, 0x14, 0x0d, 0x11, 0x0b, 0x0a, 0x0a, 0x15, 
	0x16, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x17, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x03, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x19, 
	0x19, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x05, 0x14, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x1b, 0x19, 
	0x19, 0x1c, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x0a, 0x0b, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x1d, 0x19, 
	0x19, 0x19, 0x1e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x0d, 0x11, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x06, 0x18, 0x0b, 0x11, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x16, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x20, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x21, 0x03, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x22, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x23, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x1a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x09, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x24, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x25, 0x07, 0x14, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x26, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x27, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x28, 0x25, 0x09, 0x14, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x29, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x18, 0x04, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x2a, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x2b, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x25, 0x08, 0x0b, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x09, 0x24, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x2c, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1a, 0x09, 0x0b, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x09, 0x1f, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x18, 0x0a, 0x14, 0x0a, 0x0a, 0x0a, 0x2d, 
	0x09, 0x09, 0x2e, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x2f, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x28, 0x04, 0x0b, 0x0a, 0x0a, 0x0a, 0x2d, 0x09, 
	0x09, 0x09, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x09, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x30, 0x04, 0x0b, 0x0a, 0x0a, 0x0a, 0x09, 0x09, 
	0x09, 0x31, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x19, 0x09, 0x32, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x33, 0x0c, 0x0b, 0x0a, 0x0a, 0x09, 0x09, 0x09, 
	0x09, 0x2b, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x34, 0x1f, 0x02, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x33, 0x07, 0x0b, 0x0a, 0x0a, 0x09, 0x09, 0x1f, 
	0x09, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x2a, 0x02, 0x02, 0x32, 0x19, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x07, 0x0b, 0x0a, 0x14, 0x09, 0x02, 0x02, 
	0x35, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x02, 0x02, 0x02, 0x02, 0x36, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x07, 0x0b, 0x0a, 0x0a, 0x09, 0x02, 0x08, 
	0x36, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x36, 
	0x02, 0x02, 0x02, 0x02, 0x37, 0x19, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x07, 0x0b, 0x14, 0x02, 0x02, 0x08, 0x07, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x38, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x07, 0x0b, 0x14, 0x02, 0x08, 0x08, 0x1c, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x39, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x3a, 0x19, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x07, 0x0b, 0x14, 0x02, 0x3b, 0x07, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x08, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x3c, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x0c, 0x0b, 0x0b, 0x02, 0x03, 0x3d, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x24, 0x08, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x3e, 0x19, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x04, 0x0b, 0x14, 0x3f, 0x04, 0x3c, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x40, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x24, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x41, 0x01, 0x14, 0x0a, 0x0a, 0x42, 0x19, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x07, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x43, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x41, 0x18, 0x09, 0x0a, 0x11, 0x18, 0x36, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1a, 0x07, 0x14, 0x0b, 0x09, 0x44, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x45, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x21, 0x0c, 0x14, 0x14, 0x0b, 0x0c, 0x46, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x47, 0x07, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x21, 0x05, 0x09, 0x0a, 0x0b, 0x0a, 0x1a, 
	0x36, 0x19, 0x19, 0x19, 0x19, 0x04, 0x05, 0x07, 
	0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x48, 0x25, 0x07, 0x0a, 0x14, 0x14, 0x07, 
	0x49, 0x19, 0x19, 0x19, 0x19, 0x04, 0x04, 0x04, 
	0x04, 0x07, 0x07, 0x07, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x33, 0x05, 0x0a, 0x0a, 0x0b, 0x14, 
	0x18, 0x4a, 0x19, 0x19, 0x4b, 0x04, 0x04, 0x04, 
	0x04, 0x4c, 0x4c, 0x0c, 0x02, 0x08, 0x08, 0x08, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x33, 0x1a, 0x0a, 0x0a, 0x0b, 0x0a, 
	0x0a, 0x1a, 0x24, 0x19, 0x4d, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x4e, 0x21, 0x07, 0x0b, 0x0b, 0x14, 
	0x14, 0x03, 0x4f, 0x19, 0x50, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x33, 0x18, 0x0a, 0x14, 0x14, 
	0x0b, 0x0a, 0x25, 0x51, 0x33, 0x04, 0x04, 0x4c, 
	0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x33, 0x03, 0x2d, 0x14, 
	0x0b, 0x0a, 0x03, 0x33, 0x33, 0x1a, 0x04, 0x01, 
	0x01, 0x04, 0x4c, 0x4c, 0x04, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x33, 0x25, 0x02, 0x14, 
	0x0b, 0x0a, 0x0a, 0x05, 0x25, 0x1a, 0x33, 0x33, 
	0x33, 0x04, 0x04, 0x04, 0x04, 0x4c, 0x4c, 0x4c, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x04, 0x0a, 
	0x0b, 0x0a, 0x14, 0x0a, 0x02, 0x04, 0x1a, 0x33, 
	0x33, 0x1a, 0x1a, 0x1a, 0x18, 0x4c, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x33, 0x03, 
	0x0a, 0x14, 0x14, 0x0b, 0x0a, 0x09, 0x03, 0x04, 
	0x21, 0x33, 0x33, 0x33, 0x1a, 0x25, 0x25, 0x25, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x52, 
	0x4c, 0x09, 0x09, 0x0a, 0x0a, 0x14, 0x0a, 0x09, 
	0x05, 0x18, 0x18, 0x18, 0x1a, 0x21, 0x21, 0x33, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 
	0x21, 0x04, 0x02, 0x14, 0x17, 0x0a, 0x0b, 0x0b, 
	0x0a, 0x02, 0x3b, 0x0c, 0x04, 0x18, 0x01, 0x25, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1a, 0x33, 0x05, 0x09, 0x14, 0x14, 0x14, 0x0a, 
	0x0b, 0x0b, 0x0a, 0x02, 0x09, 0x09, 0x09, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x4e, 0x33, 0x33, 0x04, 0x09, 0x09, 0x0a, 0x14, 
	0x0a, 0x14, 0x14, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x33, 0x1a, 0x25, 0x05, 0x1f, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x14, 0x14, 0x14, 0x14, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x41, 0x21, 0x1a, 0x01, 0x07, 
	0x09, 0x14, 0x14, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x33, 0x18, 
	0x4c, 0x05, 0x0c, 0x09, 0x17, 0x14, 0x14, 0x14, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 
	0x25, 0x21, 0x33, 0x05, 0x03, 0x07, 0x07, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x12, 0x1a, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x41, 0x4e, 0x30, 0x1a, 0x1a, 0x1a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx cloudcap_ClouMS02_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 cloudcap_ClouMS02_ci8_pal_rgba16[] = {
	0xff, 0xfe, 0xc6, 0x2d, 0xd6, 0xf3, 0xce, 0xb1, 
	0xc6, 0x6d, 0xce, 0x6f, 0xc6, 0x6f, 0xd6, 0xb1, 
	0xd6, 0xb3, 0xde, 0xf5, 0xdf, 0x37, 0xe7, 0x39, 
	0xce, 0xaf, 0xe7, 0x79, 0xdf, 0x79, 0xef, 0x79, 
	0xc6, 0x6e, 0xdf, 0x39, 0xc6, 0x2c, 0xe7, 0x7b, 
	0xe7, 0x37, 0xe4, 0xe1, 0xe5, 0xa9, 0xdf, 0x35, 
	0xc6, 0x2b, 0xe9, 0xc7, 0xbd, 0xe9, 0xe6, 0xf3, 
	0xe3, 0x53, 0xe3, 0x11, 0xe6, 0x6f, 0xde, 0xf3, 
	0xe4, 0x5b, 0xb5, 0xe7, 0xe2, 0x07, 0xe6, 0xb3, 
	0xe2, 0x49, 0xbe, 0x29, 0xe3, 0xd7, 0xe5, 0x23, 
	0xbd, 0xe8, 0xe6, 0xf7, 0xde, 0x2d, 0xe2, 0xcd, 
	0xe5, 0xeb, 0xde, 0xf7, 0xe4, 0x9d, 0xe4, 0x1b, 
	0xb5, 0xa7, 0xde, 0x6f, 0xdd, 0xa7, 0xbd, 0xe7, 
	0xe3, 0x95, 0xdd, 0x23, 0xe1, 0xc7, 0xdd, 0xa9, 
	0xdc, 0x5b, 0xd6, 0x6f, 0xdd, 0xe9, 0xd6, 0xf1, 
	0xe2, 0x09, 0xd5, 0xa5, 0xde, 0x2b, 0xd6, 0xf5, 
	0xdc, 0xe1, 0xad, 0xa4, 0xcd, 0xe9, 0xd6, 0x2d, 
	0xc5, 0x21, 0xe2, 0x8d, 0xdb, 0x0f, 0xd5, 0x63, 
	0xb5, 0xa5, 0xc5, 0x63, 0xd3, 0xd5, 0xdb, 0x51, 
	0xce, 0x6d, 0xcd, 0xa7, 0xb5, 0xa6, 0xbd, 0xa7, 
	0xc6, 0x29, 0xcc, 0x9b, 0xbe, 0x2b, 
};

Gfx cloudcap_Cloud02_ci8_aligner[] = {gsSPEndDisplayList()};
u8 cloudcap_Cloud02_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x07, 0x07, 
	0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 0x08, 
	0x08, 0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x08, 0x08, 0x07, 0x07, 0x09, 
	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 
	0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0c, 0x0c, 0x0d, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 
	0x06, 0x06, 0x06, 0x08, 0x07, 0x07, 0x09, 0x09, 
	0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 
	0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x06, 0x08, 
	0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 0x0a, 0x0a, 
	0x0a, 0x0b, 0x0b, 0x0b, 0x0c, 0x0c, 0x0d, 0x0d, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 
	0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 
	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 
	0x0b, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 
	0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 
	0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x09, 
	0x09, 0x09, 0x0a, 0x0a, 0x0b, 0x0b, 0x0c, 0x0c, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 
	0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x08, 0x07, 0x07, 0x09, 
	0x09, 0x09, 0x0a, 0x0a, 0x0b, 0x0b, 0x0c, 0x0c, 
	0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0f, 0x12, 0x0f, 
	0x0f, 0x10, 0x10, 0x10, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x13, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x02, 0x02, 0x03, 0x04, 0x04, 0x04, 0x05, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x08, 0x07, 0x07, 0x07, 
	0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x14, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x05, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x07, 
	0x07, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0c, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 
	0x0e, 0x0e, 0x14, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0c, 0x0d, 0x0d, 
	0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x14, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x08, 0x07, 0x07, 0x07, 0x09, 
	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 
	0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 
	0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0c, 0x0d, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x08, 0x08, 0x07, 0x07, 0x07, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x08, 0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 
	0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 
	0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx cloudcap_Cloud02_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 cloudcap_Cloud02_ci8_pal_rgba16[] = {
	0xe7, 0x39, 0xe7, 0x37, 0xdf, 0x37, 0xdf, 0x35, 
	0xde, 0xf5, 0xd6, 0xf5, 0xd6, 0xf3, 0xd6, 0xb1, 
	0xd6, 0xb3, 0xce, 0xb1, 0xce, 0xaf, 0xce, 0x6f, 
	0xc6, 0x6f, 0xc6, 0x6d, 0xc6, 0x2d, 0xbe, 0x2b, 
	0xbd, 0xeb, 0xbd, 0xe9, 0xbe, 0x2d, 0xb5, 0xe9, 
	0xc6, 0x2b, 
};

Vtx cloudcap_cloud_mario_mesh_vtx_cull[8] = {
	{{{42, -268, -172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{42, -268, 172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{42, 143, 172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{42, 143, -172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{337, -268, -172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{337, -268, 172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{337, 143, 172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{337, 143, -172},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx cloudcap_cloud_mario_mesh_vtx_0[49] = {
	{{{268, -248, -43},0, {134, -183},{0x39, 0xBA, 0xA7, 0xFF}}},
	{{{298, -256, 0},0, {134, -183},{0x5E, 0xAA, 0x0, 0xFF}}},
	{{{233, -268, 0},0, {134, -183},{0xFB, 0x81, 0x0, 0xFF}}},
	{{{268, -248, 43},0, {134, -183},{0x39, 0xB9, 0x59, 0xFF}}},
	{{{211, 73, -83},0, {123, 2340},{0x3E, 0x44, 0xA9, 0xFF}}},
	{{{242, 81, 0},0, {1007, 1975},{0x66, 0x4C, 0x0, 0xFF}}},
	{{{297, 36, -66},0, {144, 397},{0x49, 0x56, 0xC5, 0xFF}}},
	{{{321, 37, 0},0, {1008, -42},{0x74, 0x34, 0x0, 0xFF}}},
	{{{297, 36, 66},0, {144, 397},{0x49, 0x56, 0x3B, 0xFF}}},
	{{{211, 73, 83},0, {123, 2340},{0x3E, 0x44, 0x58, 0xFF}}},
	{{{321, 37, 0},0, {134, -183},{0x74, 0x34, 0x0, 0xFF}}},
	{{{334, -16, 64},0, {134, -183},{0x74, 0x7, 0x33, 0xFF}}},
	{{{334, -16, -64},0, {134, -183},{0x74, 0x6, 0xCD, 0xFF}}},
	{{{297, 36, 66},0, {134, -183},{0x49, 0x56, 0x3B, 0xFF}}},
	{{{252, -26, 146},0, {134, -183},{0x45, 0x16, 0x69, 0xFF}}},
	{{{178, 34, 148},0, {134, -183},{0xE1, 0x3F, 0x6A, 0xFF}}},
	{{{211, 73, 83},0, {134, -183},{0x3E, 0x44, 0x58, 0xFF}}},
	{{{173, 78, 89},0, {134, -183},{0xD3, 0x59, 0x4F, 0xFF}}},
	{{{228, 143, 42},0, {134, -183},{0x1C, 0x70, 0x36, 0xFF}}},
	{{{242, 81, 0},0, {134, -183},{0x66, 0x4C, 0x0, 0xFF}}},
	{{{228, 143, -42},0, {134, -183},{0x1C, 0x6F, 0xC9, 0xFF}}},
	{{{211, 73, -83},0, {134, -183},{0x3E, 0x44, 0xA9, 0xFF}}},
	{{{173, 78, -89},0, {134, -183},{0xD3, 0x59, 0xB2, 0xFF}}},
	{{{178, 34, -148},0, {134, -183},{0xE1, 0x3F, 0x96, 0xFF}}},
	{{{297, 36, -66},0, {134, -183},{0x49, 0x56, 0xC5, 0xFF}}},
	{{{252, -26, -146},0, {134, -183},{0x45, 0x16, 0x97, 0xFF}}},
	{{{234, -98, -158},0, {134, -183},{0x34, 0xC9, 0x9A, 0xFF}}},
	{{{164, -60, -172},0, {134, -183},{0xEC, 0x1, 0x83, 0xFF}}},
	{{{117, -162, -132},0, {134, -183},{0xEA, 0xB9, 0x99, 0xFF}}},
	{{{63, -85, -104},0, {134, -183},{0x94, 0xB, 0xBD, 0xFF}}},
	{{{42, -140, 0},0, {134, -183},{0x88, 0xD5, 0x3, 0xFF}}},
	{{{78, -190, 0},0, {134, -183},{0xC0, 0xA7, 0x41, 0xFF}}},
	{{{78, -190, 0},0, {134, -183},{0xC0, 0xA7, 0x41, 0xFF}}},
	{{{117, -162, 132},0, {134, -183},{0xE8, 0xBB, 0x68, 0xFF}}},
	{{{42, -140, 0},0, {134, -183},{0x88, 0xD5, 0x3, 0xFF}}},
	{{{63, -85, 104},0, {134, -183},{0x95, 0xD, 0x43, 0xFF}}},
	{{{164, -60, 172},0, {134, -183},{0xED, 0x2, 0x7E, 0xFF}}},
	{{{234, -98, 158},0, {134, -183},{0x33, 0xCA, 0x67, 0xFF}}},
	{{{252, -26, 146},0, {134, -183},{0x45, 0x16, 0x69, 0xFF}}},
	{{{334, -16, 64},0, {134, -183},{0x74, 0x7, 0x33, 0xFF}}},
	{{{178, 34, 148},0, {134, -183},{0xE1, 0x3F, 0x6A, 0xFF}}},
	{{{173, 78, 89},0, {134, -183},{0xD3, 0x59, 0x4F, 0xFF}}},
	{{{173, 78, -89},0, {134, -183},{0xD3, 0x59, 0xB2, 0xFF}}},
	{{{228, 143, -42},0, {134, -183},{0x1C, 0x6F, 0xC9, 0xFF}}},
	{{{228, 143, 42},0, {134, -183},{0x1C, 0x70, 0x36, 0xFF}}},
	{{{63, -85, -104},0, {134, -183},{0x94, 0xB, 0xBD, 0xFF}}},
	{{{178, 34, -148},0, {134, -183},{0xE1, 0x3F, 0x96, 0xFF}}},
	{{{164, -60, -172},0, {134, -183},{0xEC, 0x1, 0x83, 0xFF}}},
	{{{252, -26, -146},0, {134, -183},{0x45, 0x16, 0x97, 0xFF}}},
};

Gfx cloudcap_cloud_mario_mesh_tri_0[] = {
	gsSPVertex(cloudcap_cloud_mario_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
	gsSP2Triangles(5, 8, 7, 0, 9, 8, 5, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 13, 11, 0),
	gsSP2Triangles(14, 11, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(13, 16, 15, 0, 15, 16, 17, 0),
	gsSP2Triangles(16, 18, 17, 0, 18, 16, 19, 0),
	gsSP2Triangles(19, 20, 18, 0, 20, 19, 21, 0),
	gsSP2Triangles(21, 22, 20, 0, 23, 22, 21, 0),
	gsSP2Triangles(24, 23, 21, 0, 25, 23, 24, 0),
	gsSP2Triangles(25, 24, 12, 0, 10, 12, 24, 0),
	gsSP2Triangles(25, 12, 26, 0, 25, 26, 27, 0),
	gsSP2Triangles(27, 26, 28, 0, 28, 29, 27, 0),
	gsSP2Triangles(29, 28, 30, 0, 30, 28, 31, 0),
	gsSPVertex(cloudcap_cloud_mario_mesh_vtx_0 + 32, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 1, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(4, 6, 8, 0, 8, 3, 4, 0),
	gsSP2Triangles(8, 9, 3, 0, 9, 2, 3, 0),
	gsSP2Triangles(2, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 9, 12, 0, 10, 13, 2, 0),
	gsSP2Triangles(14, 13, 10, 0, 14, 15, 13, 0),
	gsSP1Triangle(15, 14, 16, 0),
	gsSPEndDisplayList(),
};

Vtx cloudcap_cloud_mario_mesh_vtx_1[44] = {
	{{{201, -214, -82},0, {2000, 1002},{0xD4, 0xAF, 0xA9, 0xFF}}},
	{{{165, -238, 0},0, {55, 1105},{0xB3, 0x9B, 0x0, 0xFF}}},
	{{{187, -165, -106},0, {1972, 465},{0x1, 0xAF, 0x9E, 0xFF}}},
	{{{133, -197, 0},0, {461, 484},{0xC0, 0x92, 0x0, 0xFF}}},
	{{{187, -165, 106},0, {1972, 465},{0x0, 0xAF, 0x62, 0xFF}}},
	{{{201, -214, 82},0, {2000, 1002},{0xD4, 0xAF, 0x58, 0xFF}}},
	{{{291, -163, 91},0, {1841, 1010},{0x43, 0xE2, 0x68, 0xFF}}},
	{{{282, -102, 91},0, {1652, 455},{0x56, 0xF0, 0x5D, 0xFF}}},
	{{{337, -150, 49},0, {188, 1099},{0x70, 0x14, 0x38, 0xFF}}},
	{{{321, -74, 0},0, {504, 447},{0x7F, 0xB, 0xFF, 0xFF}}},
	{{{337, -150, -49},0, {188, 1099},{0x6E, 0x17, 0xC5, 0xFF}}},
	{{{282, -102, -91},0, {1652, 455},{0x55, 0xF8, 0xA2, 0xFF}}},
	{{{291, -163, -91},0, {1841, 1010},{0x42, 0xE9, 0x96, 0xFF}}},
	{{{234, -98, -158},0, {1831, -34},{0x34, 0xC9, 0x9A, 0xFF}}},
	{{{334, -16, -64},0, {112, 43},{0x74, 0x6, 0xCD, 0xFF}}},
	{{{334, -16, 64},0, {112, 43},{0x74, 0x7, 0x33, 0xFF}}},
	{{{234, -98, 158},0, {1831, -34},{0x33, 0xCA, 0x67, 0xFF}}},
	{{{117, -162, 132},0, {1936, -59},{0xE8, 0xBB, 0x68, 0xFF}}},
	{{{78, -190, 0},0, {94, -28},{0xC0, 0xA7, 0x41, 0xFF}}},
	{{{117, -162, -132},0, {1936, -59},{0xEA, 0xB9, 0x99, 0xFF}}},
	{{{240, -224, -53},0, {1901, 474},{0x5, 0xA2, 0xAB, 0xFF}}},
	{{{268, -248, -43},0, {1464, 1003},{0x39, 0xBA, 0xA7, 0xFF}}},
	{{{233, -268, 0},0, {-128, 1044},{0xFB, 0x81, 0x0, 0xFF}}},
	{{{282, -201, -44},0, {1710, 481},{0x64, 0xD5, 0xBE, 0xFF}}},
	{{{291, -163, -91},0, {1971, -14},{0x42, 0xE9, 0x96, 0xFF}}},
	{{{201, -214, -82},0, {1877, -5},{0xD4, 0xAF, 0xA9, 0xFF}}},
	{{{207, -240, 0},0, {440, 470},{0xC5, 0x8F, 0x0, 0xFF}}},
	{{{240, -224, 53},0, {1901, 474},{0x5, 0xA2, 0x55, 0xFF}}},
	{{{268, -248, 43},0, {1464, 1003},{0x39, 0xB9, 0x59, 0xFF}}},
	{{{282, -201, 44},0, {1710, 481},{0x64, 0xD6, 0x43, 0xFF}}},
	{{{298, -256, 0},0, {268, 1043},{0x5E, 0xAA, 0x0, 0xFF}}},
	{{{306, -201, 0},0, {149, 765},{0x73, 0xCA, 0x0, 0xFF}}},
	{{{306, -201, 0},0, {149, 765},{0x73, 0xCA, 0x0, 0xFF}}},
	{{{282, -201, -44},0, {1710, 481},{0x64, 0xD5, 0xBE, 0xFF}}},
	{{{337, -150, -49},0, {555, 88},{0x6E, 0x17, 0xC5, 0xFF}}},
	{{{291, -163, -91},0, {1971, -14},{0x42, 0xE9, 0x96, 0xFF}}},
	{{{337, -150, 49},0, {555, 88},{0x70, 0x14, 0x38, 0xFF}}},
	{{{282, -201, 44},0, {1710, 481},{0x64, 0xD6, 0x43, 0xFF}}},
	{{{291, -163, 91},0, {1971, -14},{0x43, 0xE2, 0x68, 0xFF}}},
	{{{240, -224, 53},0, {1901, 474},{0x5, 0xA2, 0x55, 0xFF}}},
	{{{201, -214, 82},0, {1877, -5},{0xD4, 0xAF, 0x58, 0xFF}}},
	{{{207, -240, 0},0, {440, 470},{0xC5, 0x8F, 0x0, 0xFF}}},
	{{{165, -238, 0},0, {-55, -20},{0xB3, 0x9B, 0x0, 0xFF}}},
	{{{201, -214, -82},0, {1877, -5},{0xD4, 0xAF, 0xA9, 0xFF}}},
};

Gfx cloudcap_cloud_mario_mesh_tri_1[] = {
	gsSPVertex(cloudcap_cloud_mario_mesh_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(3, 1, 4, 0, 4, 1, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 4, 6, 7, 0),
	gsSP2Triangles(6, 8, 7, 0, 9, 7, 8, 0),
	gsSP2Triangles(10, 9, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 11, 10, 0, 2, 11, 12, 0),
	gsSP2Triangles(12, 0, 2, 0, 13, 11, 2, 0),
	gsSP2Triangles(14, 11, 13, 0, 11, 14, 9, 0),
	gsSP2Triangles(14, 15, 9, 0, 7, 9, 15, 0),
	gsSP2Triangles(15, 16, 7, 0, 16, 4, 7, 0),
	gsSP2Triangles(16, 17, 4, 0, 17, 3, 4, 0),
	gsSP2Triangles(18, 3, 17, 0, 19, 3, 18, 0),
	gsSP2Triangles(2, 3, 19, 0, 13, 2, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(20, 24, 23, 0, 25, 24, 20, 0),
	gsSP2Triangles(25, 20, 26, 0, 22, 26, 20, 0),
	gsSP2Triangles(22, 27, 26, 0, 27, 22, 28, 0),
	gsSP2Triangles(27, 28, 29, 0, 28, 30, 29, 0),
	gsSP2Triangles(29, 30, 31, 0, 31, 30, 23, 0),
	gsSP1Triangle(23, 30, 21, 0),
	gsSPVertex(cloudcap_cloud_mario_mesh_vtx_1 + 32, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(4, 0, 2, 0, 4, 5, 0, 0),
	gsSP2Triangles(6, 5, 4, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
	gsSPEndDisplayList(),
};

Gfx mat_cloudcap_M_Logo[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, ENVIRONMENT, TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cloudcap_ClouMS02_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 82),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, cloudcap_ClouMS02_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPSetLights1(cloudcap_M_Logo_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_cloudcap_M_Logo[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_cloudcap_CloudCap_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cloudcap_Cloud02_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 20),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, cloudcap_Cloud02_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPSetLights1(cloudcap_CloudCap_f3d_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_cloudcap_CloudCap_f3d[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx cloudcap_cloud_mario_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(cloudcap_cloud_mario_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_cloudcap_M_Logo),
	gsSPDisplayList(cloudcap_cloud_mario_mesh_tri_0),
	gsSPDisplayList(mat_revert_cloudcap_M_Logo),
	gsSPDisplayList(mat_cloudcap_CloudCap_f3d),
	gsSPDisplayList(cloudcap_cloud_mario_mesh_tri_1),
	gsSPDisplayList(mat_revert_cloudcap_CloudCap_f3d),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

