/**
 ** pc6x8.c ---- GRX 2.0 font converted to C by 'GrDumpFont()'
 **
 **/
 
#define  GrFont_PC6x8	FONTNAME_TEMPORARY_REDIRECTION
#include "mgrx.h"
#undef	 GrFont_PC6x8

static unsigned char GrFont_PC6x8_bits[] = {
	/* character 0 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	/* character 1 */
	0x70,0xf8,0xa8,0xf8,0xd8,0x88,0x70,0x00,
	/* character 2 */
	0x70,0xf8,0xa8,0xf8,0x88,0xd8,0x70,0x00,
	/* character 3 */
	0x00,0x50,0xf8,0xf8,0xf8,0x70,0x20,0x00,
	/* character 4 */
	0x00,0x20,0x70,0xf8,0xf8,0x70,0x20,0x00,
	/* character 5 */
	0x70,0x50,0xf8,0xa8,0xf8,0x20,0x70,0x00,
	/* character 6 */
	0x20,0x70,0xf8,0xf8,0xf8,0x20,0x70,0x00,
	/* character 7 */
	0x00,0x00,0x20,0x70,0x70,0x20,0x00,0x00,
	/* character 8 */
	0xf8,0xf8,0xd8,0x88,0x88,0xd8,0xf8,0xf8,
	/* character 9 */
	0x00,0x00,0x20,0x50,0x50,0x20,0x00,0x00,
	/* character 10 */
	0xf8,0xf8,0xd8,0xa8,0xa8,0xd8,0xf8,0xf8,
	/* character 11 */
	0x00,0x38,0x18,0x68,0xa0,0xa0,0x40,0x00,
	/* character 12 */
	0x70,0x88,0x88,0x70,0x20,0xf8,0x20,0x00,
	/* character 13 */
	0x78,0x48,0x78,0x40,0x40,0x40,0xc0,0x00,
	/* character 14 */
	0x78,0x48,0x78,0x48,0x48,0x58,0xc0,0x00,
	/* character 15 */
	0x20,0xa8,0x70,0xd8,0xd8,0x70,0xa8,0x20,
	/* character 16 */
	0x80,0xc0,0xf0,0xf8,0xf0,0xc0,0x80,0x00,
	/* character 17 */
	0x08,0x18,0x78,0xf8,0x78,0x18,0x08,0x00,
	/* character 18 */
	0x20,0x70,0xa8,0x20,0xa8,0x70,0x20,0x00,
	/* character 19 */
	0xd8,0xd8,0xd8,0xd8,0xd8,0x00,0xd8,0x00,
	/* character 20 */
	0x78,0xa8,0xa8,0x68,0x28,0x28,0x28,0x00,
	/* character 21 */
	0x30,0x48,0x50,0x28,0x10,0x48,0x48,0x30,
	/* character 22 */
	0x00,0x00,0x00,0x00,0x00,0xfc,0xfc,0x00,
	/* character 23 */
	0x20,0x70,0xa8,0x20,0xa8,0x70,0x20,0xf8,
	/* character 24 */
	0x00,0x20,0x70,0xa8,0x20,0x20,0x20,0x00,
	/* character 25 */
	0x00,0x20,0x20,0x20,0xa8,0x70,0x20,0x00,
	/* character 26 */
	0x00,0x20,0x10,0xf8,0x10,0x20,0x00,0x00,
	/* character 27 */
	0x00,0x20,0x40,0xf8,0x40,0x20,0x00,0x00,
	/* character 28 */
	0x00,0x80,0x80,0x80,0xf8,0x00,0x00,0x00,
	/* character 29 */
	0x00,0x50,0xf8,0xf8,0x50,0x00,0x00,0x00,
	/* character 30 */
	0x00,0x20,0x20,0x70,0xf8,0xf8,0x00,0x00,
	/* character 31 */
	0x00,0xf8,0xf8,0x70,0x20,0x20,0x00,0x00,
	/* character 32 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	/* character 33 */
	0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00,
	/* character 34 */
	0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,
	/* character 35 */
	0x50,0x50,0xf8,0x50,0xf8,0x50,0x50,0x00,
	/* character 36 */
	0x20,0x78,0xa0,0x70,0x28,0xf0,0x20,0x00,
	/* character 37 */
	0xc0,0xc8,0x10,0x20,0x40,0x98,0x18,0x00,
	/* character 38 */
	0x40,0xa0,0xa0,0x40,0xa8,0x90,0x68,0x00,
	/* character 39 */
	0x30,0x30,0x20,0x40,0x00,0x00,0x00,0x00,
	/* character 40 */
	0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00,
	/* character 41 */
	0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00,
	/* character 42 */
	0x20,0xa8,0x70,0xf8,0x70,0xa8,0x20,0x00,
	/* character 43 */
	0x00,0x20,0x20,0xf8,0x20,0x20,0x00,0x00,
	/* character 44 */
	0x00,0x00,0x00,0x00,0x30,0x30,0x20,0x40,
	/* character 45 */
	0x00,0x00,0x00,0xf8,0x00,0x00,0x00,0x00,
	/* character 46 */
	0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,
	/* character 47 */
	0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,
	/* character 48 */
	0x70,0x88,0x98,0xa8,0xc8,0x88,0x70,0x00,
	/* character 49 */
	0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00,
	/* character 50 */
	0x70,0x88,0x08,0x70,0x80,0x80,0xf8,0x00,
	/* character 51 */
	0xf8,0x08,0x10,0x30,0x08,0x88,0x70,0x00,
	/* character 52 */
	0x10,0x30,0x50,0x90,0xf8,0x10,0x10,0x00,
	/* character 53 */
	0xf8,0x80,0xf0,0x08,0x08,0x88,0x70,0x00,
	/* character 54 */
	0x38,0x40,0x80,0xf0,0x88,0x88,0x70,0x00,
	/* character 55 */
	0xf8,0x08,0x08,0x10,0x20,0x40,0x80,0x00,
	/* character 56 */
	0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00,
	/* character 57 */
	0x70,0x88,0x88,0x78,0x08,0x10,0xe0,0x00,
	/* character 58 */
	0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00,
	/* character 59 */
	0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00,
	/* character 60 */
	0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00,
	/* character 61 */
	0x00,0x00,0xf8,0x00,0xf8,0x00,0x00,0x00,
	/* character 62 */
	0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00,
	/* character 63 */
	0x70,0x88,0x08,0x30,0x20,0x00,0x20,0x00,
	/* character 64 */
	0x70,0x88,0xa8,0xb8,0xb0,0x80,0x78,0x00,
	/* character 65 */
	0x20,0x50,0x88,0x88,0xf8,0x88,0x88,0x00,
	/* character 66 */
	0xf0,0x88,0x88,0xf0,0x88,0x88,0xf0,0x00,
	/* character 67 */
	0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00,
	/* character 68 */
	0xf0,0x88,0x88,0x88,0x88,0x88,0xf0,0x00,
	/* character 69 */
	0xf8,0x80,0x80,0xf0,0x80,0x80,0xf8,0x00,
	/* character 70 */
	0xf8,0x80,0x80,0xf0,0x80,0x80,0x80,0x00,
	/* character 71 */
	0x78,0x88,0x80,0x80,0x98,0x88,0x78,0x00,
	/* character 72 */
	0x88,0x88,0x88,0xf8,0x88,0x88,0x88,0x00,
	/* character 73 */
	0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00,
	/* character 74 */
	0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00,
	/* character 75 */
	0x88,0x90,0xa0,0xc0,0xa0,0x90,0x88,0x00,
	/* character 76 */
	0x80,0x80,0x80,0x80,0x80,0x80,0xf8,0x00,
	/* character 77 */
	0x88,0xd8,0xa8,0xa8,0xa8,0x88,0x88,0x00,
	/* character 78 */
	0x88,0x88,0xc8,0xa8,0x98,0x88,0x88,0x00,
	/* character 79 */
	0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00,
	/* character 80 */
	0xf0,0x88,0x88,0xf0,0x80,0x80,0x80,0x00,
	/* character 81 */
	0x70,0x88,0x88,0x88,0xa8,0x90,0x68,0x00,
	/* character 82 */
	0xf0,0x88,0x88,0xf0,0xa0,0x90,0x88,0x00,
	/* character 83 */
	0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00,
	/* character 84 */
	0xf8,0xa8,0x20,0x20,0x20,0x20,0x20,0x00,
	/* character 85 */
	0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,
	/* character 86 */
	0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00,
	/* character 87 */
	0x88,0x88,0x88,0xa8,0xa8,0xa8,0x50,0x00,
	/* character 88 */
	0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00,
	/* character 89 */
	0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00,
	/* character 90 */
	0xf8,0x08,0x10,0x70,0x40,0x80,0xf8,0x00,
	/* character 91 */
	0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00,
	/* character 92 */
	0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,
	/* character 93 */
	0x78,0x08,0x08,0x08,0x08,0x08,0x78,0x00,
	/* character 94 */
	0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00,
	/* character 95 */
	0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,
	/* character 96 */
	0x60,0x60,0x20,0x10,0x00,0x00,0x00,0x00,
	/* character 97 */
	0x00,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 98 */
	0x80,0x80,0xb0,0xc8,0x88,0xc8,0xb0,0x00,
	/* character 99 */
	0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00,
	/* character 100 */
	0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00,
	/* character 101 */
	0x00,0x00,0x70,0x88,0xf8,0x80,0x70,0x00,
	/* character 102 */
	0x10,0x28,0x20,0x70,0x20,0x20,0x20,0x00,
	/* character 103 */
	0x00,0x00,0x70,0x98,0x98,0x68,0x08,0x70,
	/* character 104 */
	0x80,0x80,0xb0,0xc8,0x88,0x88,0x88,0x00,
	/* character 105 */
	0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00,
	/* character 106 */
	0x10,0x00,0x10,0x10,0x10,0x90,0x60,0x00,
	/* character 107 */
	0x80,0x80,0x90,0xa0,0xc0,0xa0,0x90,0x00,
	/* character 108 */
	0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00,
	/* character 109 */
	0x00,0x00,0xd0,0xa8,0xa8,0xa8,0xa8,0x00,
	/* character 110 */
	0x00,0x00,0xb0,0xc8,0x88,0x88,0x88,0x00,
	/* character 111 */
	0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00,
	/* character 112 */
	0x00,0x00,0xb0,0xc8,0xc8,0xb0,0x80,0x80,
	/* character 113 */
	0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08,
	/* character 114 */
	0x00,0x00,0xb0,0xc8,0x80,0x80,0x80,0x00,
	/* character 115 */
	0x00,0x00,0x78,0x80,0x70,0x08,0xf0,0x00,
	/* character 116 */
	0x20,0x20,0xf8,0x20,0x20,0x28,0x10,0x00,
	/* character 117 */
	0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00,
	/* character 118 */
	0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00,
	/* character 119 */
	0x00,0x00,0x88,0x88,0xa8,0xa8,0x50,0x00,
	/* character 120 */
	0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00,
	/* character 121 */
	0x00,0x00,0x88,0x88,0x78,0x08,0x88,0x70,
	/* character 122 */
	0x00,0x00,0xf8,0x10,0x20,0x40,0xf8,0x00,
	/* character 123 */
	0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00,
	/* character 124 */
	0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00,
	/* character 125 */
	0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00,
	/* character 126 */
	0x40,0xa8,0x10,0x00,0x00,0x00,0x00,0x00,
	/* character 127 */
	0x20,0x70,0xd8,0x88,0x88,0xf8,0x00,0x00,
	/* character 128 */
	0x70,0x88,0x80,0x80,0x88,0x70,0x10,0x60,
	/* character 129 */
	0x00,0x88,0x00,0x88,0x88,0x98,0x68,0x00,
	/* character 130 */
	0x18,0x00,0x70,0x88,0xf8,0x80,0x78,0x00,
	/* character 131 */
	0xf8,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 132 */
	0x88,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 133 */
	0xc0,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 134 */
	0x30,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 135 */
	0x00,0x78,0xc0,0xc0,0x78,0x10,0x30,0x00,
	/* character 136 */
	0xf8,0x00,0x70,0x88,0xf8,0x80,0x78,0x00,
	/* character 137 */
	0x88,0x00,0x70,0x88,0xf8,0x80,0x78,0x00,
	/* character 138 */
	0xc0,0x00,0x70,0x88,0xf8,0x80,0x78,0x00,
	/* character 139 */
	0x28,0x00,0x30,0x10,0x10,0x10,0x38,0x00,
	/* character 140 */
	0x30,0x48,0x30,0x10,0x10,0x10,0x38,0x00,
	/* character 141 */
	0x60,0x00,0x30,0x10,0x10,0x10,0x38,0x00,
	/* character 142 */
	0x50,0x00,0x20,0x50,0x88,0xf8,0x88,0x88,
	/* character 143 */
	0x20,0x00,0x20,0x50,0x88,0xf8,0x88,0x88,
	/* character 144 */
	0x30,0x00,0xf0,0x80,0xe0,0x80,0xf0,0x00,
	/* character 145 */
	0x00,0x00,0x7c,0x10,0x78,0x90,0x7c,0x00,
	/* character 146 */
	0x3c,0x50,0x90,0xf8,0x90,0x90,0x9c,0x00,
	/* character 147 */
	0x70,0x88,0x00,0x70,0x88,0x88,0x70,0x00,
	/* character 148 */
	0x00,0x88,0x00,0x70,0x88,0x88,0x70,0x00,
	/* character 149 */
	0x00,0xc0,0x00,0x70,0x88,0x88,0x70,0x00,
	/* character 150 */
	0x70,0x88,0x00,0x88,0x88,0x98,0x68,0x00,
	/* character 151 */
	0x00,0xc0,0x00,0x88,0x88,0x98,0x68,0x00,
	/* character 152 */
	0x48,0x00,0x48,0x48,0x48,0x38,0x08,0x70,
	/* character 153 */
	0x88,0x00,0x70,0x88,0x88,0x88,0x70,0x00,
	/* character 154 */
	0x88,0x00,0x88,0x88,0x88,0x88,0x70,0x00,
	/* character 155 */
	0x20,0x20,0xf8,0xa0,0xa0,0xf8,0x20,0x20,
	/* character 156 */
	0x30,0x58,0x48,0xe0,0x40,0x48,0xf8,0x00,
	/* character 157 */
	0xd8,0xd8,0x70,0xf8,0x20,0xf8,0x20,0x20,
	/* character 158 */
	0xe0,0x90,0x90,0xe0,0x90,0xb8,0x90,0x90,
	/* character 159 */
	0x18,0x28,0x20,0x70,0x20,0x20,0xa0,0xc0,
	/* character 160 */
	0x18,0x00,0x60,0x10,0x70,0x90,0x78,0x00,
	/* character 161 */
	0x18,0x00,0x30,0x10,0x10,0x10,0x38,0x00,
	/* character 162 */
	0x00,0x18,0x00,0x70,0x88,0x88,0x70,0x00,
	/* character 163 */
	0x00,0x18,0x00,0x88,0x88,0x98,0x68,0x00,
	/* character 164 */
	0x00,0x78,0x00,0x70,0x48,0x48,0x48,0x00,
	/* character 165 */
	0xf8,0x00,0xc8,0xe8,0xb8,0x98,0x88,0x00,
	/* character 166 */
	0x70,0x90,0x90,0x78,0x00,0xf8,0x00,0x00,
	/* character 167 */
	0x70,0x88,0x88,0x70,0x00,0xf8,0x00,0x00,
	/* character 168 */
	0x20,0x00,0x20,0x60,0x80,0x88,0x70,0x00,
	/* character 169 */
	0x00,0x00,0x00,0xf8,0x80,0x80,0x00,0x00,
	/* character 170 */
	0x00,0x00,0x00,0xf8,0x08,0x08,0x00,0x00,
	/* character 171 */
	0x80,0x88,0x90,0xb8,0x48,0x98,0x20,0x38,
	/* character 172 */
	0x80,0x88,0x90,0xa8,0x58,0xb8,0x08,0x08,
	/* character 173 */
	0x20,0x20,0x00,0x20,0x20,0x20,0x20,0x00,
	/* character 174 */
	0x00,0x28,0x50,0xa0,0x50,0x28,0x00,0x00,
	/* character 175 */
	0x00,0xa0,0x50,0x28,0x50,0xa0,0x00,0x00,
	/* character 176 */
	0x20,0x88,0x20,0x88,0x20,0x88,0x20,0x88,
	/* character 177 */
	0x54,0xa8,0x54,0xa8,0x54,0xa8,0x54,0xa8,
	/* character 178 */
	0xa8,0x54,0xa8,0x54,0xa8,0x54,0xa8,0x54,
	/* character 179 */
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	/* character 180 */
	0x10,0x10,0x10,0x10,0xf0,0x10,0x10,0x10,
	/* character 181 */
	0x10,0x10,0xf0,0x10,0xf0,0x10,0x10,0x10,
	/* character 182 */
	0x28,0x28,0x28,0x28,0xe8,0x28,0x28,0x28,
	/* character 183 */
	0x00,0x00,0x00,0x00,0xf8,0x28,0x28,0x28,
	/* character 184 */
	0x00,0x00,0xf0,0x10,0xf0,0x10,0x10,0x10,
	/* character 185 */
	0x28,0x28,0xe8,0x08,0xe8,0x28,0x28,0x28,
	/* character 186 */
	0x28,0x28,0x28,0x28,0x28,0x28,0x28,0x28,
	/* character 187 */
	0x00,0x00,0xf8,0x08,0xe8,0x28,0x28,0x28,
	/* character 188 */
	0x28,0x28,0xe8,0x08,0xf8,0x00,0x00,0x00,
	/* character 189 */
	0x28,0x28,0x28,0x28,0xf8,0x00,0x00,0x00,
	/* character 190 */
	0x10,0x10,0xf0,0x10,0xf0,0x00,0x00,0x00,
	/* character 191 */
	0x00,0x00,0x00,0x00,0xf0,0x10,0x10,0x10,
	/* character 192 */
	0x10,0x10,0x10,0x10,0x1c,0x00,0x00,0x00,
	/* character 193 */
	0x10,0x10,0x10,0x10,0xfc,0x00,0x00,0x00,
	/* character 194 */
	0x00,0x00,0x00,0x00,0xfc,0x10,0x10,0x10,
	/* character 195 */
	0x10,0x10,0x10,0x10,0x1c,0x10,0x10,0x10,
	/* character 196 */
	0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,
	/* character 197 */
	0x10,0x10,0x10,0x10,0xfc,0x10,0x10,0x10,
	/* character 198 */
	0x10,0x10,0x1c,0x10,0x1c,0x10,0x10,0x10,
	/* character 199 */
	0x28,0x28,0x28,0x28,0x2c,0x28,0x28,0x28,
	/* character 200 */
	0x28,0x28,0x2c,0x20,0x3c,0x00,0x00,0x00,
	/* character 201 */
	0x00,0x00,0x3c,0x20,0x2c,0x28,0x28,0x28,
	/* character 202 */
	0x28,0x28,0xec,0x00,0xfc,0x00,0x00,0x00,
	/* character 203 */
	0x00,0x00,0xfc,0x00,0xec,0x28,0x28,0x28,
	/* character 204 */
	0x28,0x28,0x2c,0x20,0x2c,0x28,0x28,0x28,
	/* character 205 */
	0x00,0x00,0xfc,0x00,0xfc,0x00,0x00,0x00,
	/* character 206 */
	0x28,0x28,0xec,0x00,0xec,0x28,0x28,0x28,
	/* character 207 */
	0x10,0x10,0xfc,0x00,0xfc,0x00,0x00,0x00,
	/* character 208 */
	0x28,0x28,0x28,0x28,0xfc,0x00,0x00,0x00,
	/* character 209 */
	0x00,0x00,0xfc,0x00,0xfc,0x10,0x10,0x10,
	/* character 210 */
	0x00,0x00,0x00,0x00,0xfc,0x28,0x28,0x28,
	/* character 211 */
	0x28,0x28,0x28,0x28,0x3c,0x00,0x00,0x00,
	/* character 212 */
	0x10,0x10,0x1c,0x10,0x1c,0x00,0x00,0x00,
	/* character 213 */
	0x00,0x00,0x1c,0x10,0x1c,0x10,0x10,0x10,
	/* character 214 */
	0x00,0x00,0x00,0x00,0x3c,0x28,0x28,0x28,
	/* character 215 */
	0x28,0x28,0x28,0x28,0xfc,0x28,0x28,0x28,
	/* character 216 */
	0x10,0x10,0xfc,0x10,0xfc,0x10,0x10,0x10,
	/* character 217 */
	0x10,0x10,0x10,0x10,0xf0,0x00,0x00,0x00,
	/* character 218 */
	0x00,0x00,0x00,0x00,0x1c,0x10,0x10,0x10,
	/* character 219 */
	0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,
	/* character 220 */
	0x00,0x00,0x00,0x00,0xfc,0xfc,0xfc,0xfc,
	/* character 221 */
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
	/* character 222 */
	0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,
	/* character 223 */
	0xfc,0xfc,0xfc,0xfc,0x00,0x00,0x00,0x00,
	/* character 224 */
	0x00,0x00,0x68,0x90,0x90,0x90,0x68,0x00,
	/* character 225 */
	0x00,0x70,0x98,0xf0,0x98,0xf0,0x80,0x00,
	/* character 226 */
	0x00,0xf8,0x98,0x80,0x80,0x80,0x80,0x00,
	/* character 227 */
	0x00,0xf8,0x50,0x50,0x50,0x50,0x50,0x00,
	/* character 228 */
	0xf8,0x88,0x40,0x20,0x40,0x88,0xf8,0x00,
	/* character 229 */
	0x00,0x00,0x78,0x90,0x90,0x90,0x60,0x00,
	/* character 230 */
	0x00,0x50,0x50,0x50,0x50,0x68,0xc0,0x00,
	/* character 231 */
	0x00,0xf8,0xa0,0x20,0x20,0x20,0x20,0x00,
	/* character 232 */
	0xf8,0x20,0x70,0x88,0x88,0x70,0x20,0xf8,
	/* character 233 */
	0x20,0x50,0x88,0xf8,0x88,0x50,0x20,0x00,
	/* character 234 */
	0x20,0x50,0x88,0x88,0x50,0x50,0xd8,0x00,
	/* character 235 */
	0x30,0x40,0x30,0x70,0x88,0x88,0x70,0x00,
	/* character 236 */
	0x00,0x00,0x00,0x70,0xa8,0xa8,0x70,0x00,
	/* character 237 */
	0x08,0x70,0x98,0xa8,0xa8,0xc8,0x70,0x80,
	/* character 238 */
	0x70,0x80,0x80,0xf0,0x80,0x80,0x70,0x00,
	/* character 239 */
	0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x00,
	/* character 240 */
	0x00,0xf8,0x00,0xf8,0x00,0xf8,0x00,0x00,
	/* character 241 */
	0x20,0x20,0xf8,0x20,0x20,0x00,0xf8,0x00,
	/* character 242 */
	0x40,0x20,0x10,0x20,0x40,0x00,0xf8,0x00,
	/* character 243 */
	0x10,0x20,0x40,0x20,0x10,0x00,0xf8,0x00,
	/* character 244 */
	0x38,0x28,0x20,0x20,0x20,0x20,0x20,0x20,
	/* character 245 */
	0x20,0x20,0x20,0x20,0x20,0xa0,0xa0,0xe0,
	/* character 246 */
	0x30,0x30,0x00,0xfc,0x00,0x30,0x30,0x00,
	/* character 247 */
	0x00,0xe8,0xb8,0x00,0xe8,0xb8,0x00,0x00,
	/* character 248 */
	0x70,0xd8,0xd8,0x70,0x00,0x00,0x00,0x00,
	/* character 249 */
	0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,
	/* character 250 */
	0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	/* character 251 */
	0x38,0x20,0x20,0x20,0xa0,0xa0,0x60,0x20,
	/* character 252 */
	0x70,0x48,0x48,0x48,0x48,0x00,0x00,0x00,
	/* character 253 */
	0x70,0x18,0x30,0x60,0x78,0x00,0x00,0x00,
	/* character 254 */
	0x00,0x00,0x78,0x78,0x78,0x78,0x00,0x00,
	/* character 255 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

struct {
    GrFont	  theFont;
    GrFontChrInfo rest[255];
} GrFont_PC6x8 = {
    {
	{			    /* font header */
	    "pc6x8",                /* font name */
	    "pc",                   /* font family name */
	    0,			    /* characters have varying width */
	    0,			    /* derived from a scalable font */
	    1,			    /* font permanently linked into program */
	    GR_FONTCVT_NONE,	    /* 'tweaked' font (resized, etc..) */
	    6,			    /* width (average when proportional) */
	    8,			    /* font height */
	    6,			    /* baseline pixel pos (from top) */
	    7,			    /* underline pixel pos (from top) */
	    1,			    /* underline width */
	    0,			    /* lowest character code in font */
	    256,		    /* number of characters in font */
        GR_FONTENC_CP437 /* encoding */
	},
	(char *)GrFont_PC6x8_bits,  /* character bitmap array */
	0,			    /* auxiliary bitmap */
	6,			    /* width of narrowest character */
	6,			    /* width of widest character */
	0,			    /* allocated size of auxiliary bitmap */
	0,			    /* free space in auxiliary bitmap */
	{  0		},	    /* converted character bitmap offsets */
	{{ 6,	0	}}	    /* first character info */
    },
    {
	{  6,	8	},	    /* info for character 1   */
	{  6,	16	},	    /* info for character 2   */
	{  6,	24	},	    /* info for character 3   */
	{  6,	32	},	    /* info for character 4   */
	{  6,	40	},	    /* info for character 5   */
	{  6,	48	},	    /* info for character 6   */
	{  6,	56	},	    /* info for character 7   */
	{  6,	64	},	    /* info for character 8   */
	{  6,	72	},	    /* info for character 9   */
	{  6,	80	},	    /* info for character 10  */
	{  6,	88	},	    /* info for character 11  */
	{  6,	96	},	    /* info for character 12  */
	{  6,	104	},	    /* info for character 13  */
	{  6,	112	},	    /* info for character 14  */
	{  6,	120	},	    /* info for character 15  */
	{  6,	128	},	    /* info for character 16  */
	{  6,	136	},	    /* info for character 17  */
	{  6,	144	},	    /* info for character 18  */
	{  6,	152	},	    /* info for character 19  */
	{  6,	160	},	    /* info for character 20  */
	{  6,	168	},	    /* info for character 21  */
	{  6,	176	},	    /* info for character 22  */
	{  6,	184	},	    /* info for character 23  */
	{  6,	192	},	    /* info for character 24  */
	{  6,	200	},	    /* info for character 25  */
	{  6,	208	},	    /* info for character 26  */
	{  6,	216	},	    /* info for character 27  */
	{  6,	224	},	    /* info for character 28  */
	{  6,	232	},	    /* info for character 29  */
	{  6,	240	},	    /* info for character 30  */
	{  6,	248	},	    /* info for character 31  */
	{  6,	256	},	    /* info for character 32  */
	{  6,	264	},	    /* info for character 33  */
	{  6,	272	},	    /* info for character 34  */
	{  6,	280	},	    /* info for character 35  */
	{  6,	288	},	    /* info for character 36  */
	{  6,	296	},	    /* info for character 37  */
	{  6,	304	},	    /* info for character 38  */
	{  6,	312	},	    /* info for character 39  */
	{  6,	320	},	    /* info for character 40  */
	{  6,	328	},	    /* info for character 41  */
	{  6,	336	},	    /* info for character 42  */
	{  6,	344	},	    /* info for character 43  */
	{  6,	352	},	    /* info for character 44  */
	{  6,	360	},	    /* info for character 45  */
	{  6,	368	},	    /* info for character 46  */
	{  6,	376	},	    /* info for character 47  */
	{  6,	384	},	    /* info for character 48  */
	{  6,	392	},	    /* info for character 49  */
	{  6,	400	},	    /* info for character 50  */
	{  6,	408	},	    /* info for character 51  */
	{  6,	416	},	    /* info for character 52  */
	{  6,	424	},	    /* info for character 53  */
	{  6,	432	},	    /* info for character 54  */
	{  6,	440	},	    /* info for character 55  */
	{  6,	448	},	    /* info for character 56  */
	{  6,	456	},	    /* info for character 57  */
	{  6,	464	},	    /* info for character 58  */
	{  6,	472	},	    /* info for character 59  */
	{  6,	480	},	    /* info for character 60  */
	{  6,	488	},	    /* info for character 61  */
	{  6,	496	},	    /* info for character 62  */
	{  6,	504	},	    /* info for character 63  */
	{  6,	512	},	    /* info for character 64  */
	{  6,	520	},	    /* info for character 65  */
	{  6,	528	},	    /* info for character 66  */
	{  6,	536	},	    /* info for character 67  */
	{  6,	544	},	    /* info for character 68  */
	{  6,	552	},	    /* info for character 69  */
	{  6,	560	},	    /* info for character 70  */
	{  6,	568	},	    /* info for character 71  */
	{  6,	576	},	    /* info for character 72  */
	{  6,	584	},	    /* info for character 73  */
	{  6,	592	},	    /* info for character 74  */
	{  6,	600	},	    /* info for character 75  */
	{  6,	608	},	    /* info for character 76  */
	{  6,	616	},	    /* info for character 77  */
	{  6,	624	},	    /* info for character 78  */
	{  6,	632	},	    /* info for character 79  */
	{  6,	640	},	    /* info for character 80  */
	{  6,	648	},	    /* info for character 81  */
	{  6,	656	},	    /* info for character 82  */
	{  6,	664	},	    /* info for character 83  */
	{  6,	672	},	    /* info for character 84  */
	{  6,	680	},	    /* info for character 85  */
	{  6,	688	},	    /* info for character 86  */
	{  6,	696	},	    /* info for character 87  */
	{  6,	704	},	    /* info for character 88  */
	{  6,	712	},	    /* info for character 89  */
	{  6,	720	},	    /* info for character 90  */
	{  6,	728	},	    /* info for character 91  */
	{  6,	736	},	    /* info for character 92  */
	{  6,	744	},	    /* info for character 93  */
	{  6,	752	},	    /* info for character 94  */
	{  6,	760	},	    /* info for character 95  */
	{  6,	768	},	    /* info for character 96  */
	{  6,	776	},	    /* info for character 97  */
	{  6,	784	},	    /* info for character 98  */
	{  6,	792	},	    /* info for character 99  */
	{  6,	800	},	    /* info for character 100 */
	{  6,	808	},	    /* info for character 101 */
	{  6,	816	},	    /* info for character 102 */
	{  6,	824	},	    /* info for character 103 */
	{  6,	832	},	    /* info for character 104 */
	{  6,	840	},	    /* info for character 105 */
	{  6,	848	},	    /* info for character 106 */
	{  6,	856	},	    /* info for character 107 */
	{  6,	864	},	    /* info for character 108 */
	{  6,	872	},	    /* info for character 109 */
	{  6,	880	},	    /* info for character 110 */
	{  6,	888	},	    /* info for character 111 */
	{  6,	896	},	    /* info for character 112 */
	{  6,	904	},	    /* info for character 113 */
	{  6,	912	},	    /* info for character 114 */
	{  6,	920	},	    /* info for character 115 */
	{  6,	928	},	    /* info for character 116 */
	{  6,	936	},	    /* info for character 117 */
	{  6,	944	},	    /* info for character 118 */
	{  6,	952	},	    /* info for character 119 */
	{  6,	960	},	    /* info for character 120 */
	{  6,	968	},	    /* info for character 121 */
	{  6,	976	},	    /* info for character 122 */
	{  6,	984	},	    /* info for character 123 */
	{  6,	992	},	    /* info for character 124 */
	{  6,	1000	},	    /* info for character 125 */
	{  6,	1008	},	    /* info for character 126 */
	{  6,	1016	},	    /* info for character 127 */
	{  6,	1024	},	    /* info for character 128 */
	{  6,	1032	},	    /* info for character 129 */
	{  6,	1040	},	    /* info for character 130 */
	{  6,	1048	},	    /* info for character 131 */
	{  6,	1056	},	    /* info for character 132 */
	{  6,	1064	},	    /* info for character 133 */
	{  6,	1072	},	    /* info for character 134 */
	{  6,	1080	},	    /* info for character 135 */
	{  6,	1088	},	    /* info for character 136 */
	{  6,	1096	},	    /* info for character 137 */
	{  6,	1104	},	    /* info for character 138 */
	{  6,	1112	},	    /* info for character 139 */
	{  6,	1120	},	    /* info for character 140 */
	{  6,	1128	},	    /* info for character 141 */
	{  6,	1136	},	    /* info for character 142 */
	{  6,	1144	},	    /* info for character 143 */
	{  6,	1152	},	    /* info for character 144 */
	{  6,	1160	},	    /* info for character 145 */
	{  6,	1168	},	    /* info for character 146 */
	{  6,	1176	},	    /* info for character 147 */
	{  6,	1184	},	    /* info for character 148 */
	{  6,	1192	},	    /* info for character 149 */
	{  6,	1200	},	    /* info for character 150 */
	{  6,	1208	},	    /* info for character 151 */
	{  6,	1216	},	    /* info for character 152 */
	{  6,	1224	},	    /* info for character 153 */
	{  6,	1232	},	    /* info for character 154 */
	{  6,	1240	},	    /* info for character 155 */
	{  6,	1248	},	    /* info for character 156 */
	{  6,	1256	},	    /* info for character 157 */
	{  6,	1264	},	    /* info for character 158 */
	{  6,	1272	},	    /* info for character 159 */
	{  6,	1280	},	    /* info for character 160 */
	{  6,	1288	},	    /* info for character 161 */
	{  6,	1296	},	    /* info for character 162 */
	{  6,	1304	},	    /* info for character 163 */
	{  6,	1312	},	    /* info for character 164 */
	{  6,	1320	},	    /* info for character 165 */
	{  6,	1328	},	    /* info for character 166 */
	{  6,	1336	},	    /* info for character 167 */
	{  6,	1344	},	    /* info for character 168 */
	{  6,	1352	},	    /* info for character 169 */
	{  6,	1360	},	    /* info for character 170 */
	{  6,	1368	},	    /* info for character 171 */
	{  6,	1376	},	    /* info for character 172 */
	{  6,	1384	},	    /* info for character 173 */
	{  6,	1392	},	    /* info for character 174 */
	{  6,	1400	},	    /* info for character 175 */
	{  6,	1408	},	    /* info for character 176 */
	{  6,	1416	},	    /* info for character 177 */
	{  6,	1424	},	    /* info for character 178 */
	{  6,	1432	},	    /* info for character 179 */
	{  6,	1440	},	    /* info for character 180 */
	{  6,	1448	},	    /* info for character 181 */
	{  6,	1456	},	    /* info for character 182 */
	{  6,	1464	},	    /* info for character 183 */
	{  6,	1472	},	    /* info for character 184 */
	{  6,	1480	},	    /* info for character 185 */
	{  6,	1488	},	    /* info for character 186 */
	{  6,	1496	},	    /* info for character 187 */
	{  6,	1504	},	    /* info for character 188 */
	{  6,	1512	},	    /* info for character 189 */
	{  6,	1520	},	    /* info for character 190 */
	{  6,	1528	},	    /* info for character 191 */
	{  6,	1536	},	    /* info for character 192 */
	{  6,	1544	},	    /* info for character 193 */
	{  6,	1552	},	    /* info for character 194 */
	{  6,	1560	},	    /* info for character 195 */
	{  6,	1568	},	    /* info for character 196 */
	{  6,	1576	},	    /* info for character 197 */
	{  6,	1584	},	    /* info for character 198 */
	{  6,	1592	},	    /* info for character 199 */
	{  6,	1600	},	    /* info for character 200 */
	{  6,	1608	},	    /* info for character 201 */
	{  6,	1616	},	    /* info for character 202 */
	{  6,	1624	},	    /* info for character 203 */
	{  6,	1632	},	    /* info for character 204 */
	{  6,	1640	},	    /* info for character 205 */
	{  6,	1648	},	    /* info for character 206 */
	{  6,	1656	},	    /* info for character 207 */
	{  6,	1664	},	    /* info for character 208 */
	{  6,	1672	},	    /* info for character 209 */
	{  6,	1680	},	    /* info for character 210 */
	{  6,	1688	},	    /* info for character 211 */
	{  6,	1696	},	    /* info for character 212 */
	{  6,	1704	},	    /* info for character 213 */
	{  6,	1712	},	    /* info for character 214 */
	{  6,	1720	},	    /* info for character 215 */
	{  6,	1728	},	    /* info for character 216 */
	{  6,	1736	},	    /* info for character 217 */
	{  6,	1744	},	    /* info for character 218 */
	{  6,	1752	},	    /* info for character 219 */
	{  6,	1760	},	    /* info for character 220 */
	{  6,	1768	},	    /* info for character 221 */
	{  6,	1776	},	    /* info for character 222 */
	{  6,	1784	},	    /* info for character 223 */
	{  6,	1792	},	    /* info for character 224 */
	{  6,	1800	},	    /* info for character 225 */
	{  6,	1808	},	    /* info for character 226 */
	{  6,	1816	},	    /* info for character 227 */
	{  6,	1824	},	    /* info for character 228 */
	{  6,	1832	},	    /* info for character 229 */
	{  6,	1840	},	    /* info for character 230 */
	{  6,	1848	},	    /* info for character 231 */
	{  6,	1856	},	    /* info for character 232 */
	{  6,	1864	},	    /* info for character 233 */
	{  6,	1872	},	    /* info for character 234 */
	{  6,	1880	},	    /* info for character 235 */
	{  6,	1888	},	    /* info for character 236 */
	{  6,	1896	},	    /* info for character 237 */
	{  6,	1904	},	    /* info for character 238 */
	{  6,	1912	},	    /* info for character 239 */
	{  6,	1920	},	    /* info for character 240 */
	{  6,	1928	},	    /* info for character 241 */
	{  6,	1936	},	    /* info for character 242 */
	{  6,	1944	},	    /* info for character 243 */
	{  6,	1952	},	    /* info for character 244 */
	{  6,	1960	},	    /* info for character 245 */
	{  6,	1968	},	    /* info for character 246 */
	{  6,	1976	},	    /* info for character 247 */
	{  6,	1984	},	    /* info for character 248 */
	{  6,	1992	},	    /* info for character 249 */
	{  6,	2000	},	    /* info for character 250 */
	{  6,	2008	},	    /* info for character 251 */
	{  6,	2016	},	    /* info for character 252 */
	{  6,	2024	},	    /* info for character 253 */
	{  6,	2032	},	    /* info for character 254 */
	{  6,	2040	} 	    /* info for character 255 */
    }
};

