#include <bits/stdc++.h>
using namespace std;

int X[5][16], Y[5][16], Z[5][16], XX[5][16], YY[5][16], ZZ[5][16], DX[5][16], DY[5][16], DZ[5][16];
int Sbox1[256] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
int Sbox2[256] = {
	0xe2, 0x4e, 0x54, 0xfc, 0x94, 0xc2, 0x4a, 0xcc, 0x62, 0x0d, 0x6a, 0x46, 0x3c, 0x4d, 0x8b, 0xd1,
	0x5e, 0xfa, 0x64, 0xcb, 0xb4, 0x97, 0xbe, 0x2b, 0xbc, 0x77, 0x2e, 0x03, 0xd3, 0x19, 0x59, 0xc1,
	0x1d, 0x06, 0x41, 0x6b, 0x55, 0xf0, 0x99, 0x69, 0xea, 0x9c, 0x18, 0xae, 0x63, 0xdf, 0xe7, 0xbb,
	0x00, 0x73, 0x66, 0xfb, 0x96, 0x4c, 0x85, 0xe4, 0x3a, 0x09, 0x45, 0xaa, 0x0f, 0xee, 0x10, 0xeb,
	0x2d, 0x7f, 0xf4, 0x29, 0xac, 0xcf, 0xad, 0x91, 0x8d, 0x78, 0xc8, 0x95, 0xf9, 0x2f, 0xce, 0xcd,
	0x08, 0x7a, 0x88, 0x38, 0x5c, 0x83, 0x2a, 0x28, 0x47, 0xdb, 0xb8, 0xc7, 0x93, 0xa4, 0x12, 0x53,
	0xff, 0x87, 0x0e, 0x31, 0x36, 0x21, 0x58, 0x48, 0x01, 0x8e, 0x37, 0x74, 0x32, 0xca, 0xe9, 0xb1,
	0xb7, 0xab, 0x0c, 0xd7, 0xc4, 0x56, 0x42, 0x26, 0x07, 0x98, 0x60, 0xd9, 0xb6, 0xb9, 0x11, 0x40,
	0xec, 0x20, 0x8c, 0xbd, 0xa0, 0xc9, 0x84, 0x04, 0x49, 0x23, 0xf1, 0x4f, 0x50, 0x1f, 0x13, 0xdc,
	0xd8, 0xc0, 0x9e, 0x57, 0xe3, 0xc3, 0x7b, 0x65, 0x3b, 0x02, 0x8f, 0x3e, 0xe8, 0x25, 0x92, 0xe5,
	0x15, 0xdd, 0xfd, 0x17, 0xa9, 0xbf, 0xd4, 0x9a, 0x7e, 0xc5, 0x39, 0x67, 0xfe, 0x76, 0x9d, 0x43,
	0xa7, 0xe1, 0xd0, 0xf5, 0x68, 0xf2, 0x1b, 0x34, 0x70, 0x05, 0xa3, 0x8a, 0xd5, 0x79, 0x86, 0xa8,
	0x30, 0xc6, 0x51, 0x4b, 0x1e, 0xa6, 0x27, 0xf6, 0x35, 0xd2, 0x6e, 0x24, 0x16, 0x82, 0x5f, 0xda,
	0xe6, 0x75, 0xa2, 0xef, 0x2c, 0xb2, 0x1c, 0x9f, 0x5d, 0x6f, 0x80, 0x0a, 0x72, 0x44, 0x9b, 0x6c,
	0x90, 0x0b, 0x5b, 0x33, 0x7d, 0x5a, 0x52, 0xf3, 0x61, 0xa1, 0xf7, 0xb0, 0xd6, 0x3f, 0x7c, 0x6d,
	0xed, 0x14, 0xe0, 0xa5, 0x3d, 0x22, 0xb3, 0xf8, 0x89, 0xde, 0x71, 0x1a, 0xaf, 0xba, 0xb5, 0x81
};
int iSbox1[256] = {
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};
int iSbox2[256] = {
	0x30, 0x68, 0x99, 0x1b, 0x87, 0xb9, 0x21, 0x78, 0x50, 0x39, 0xdb, 0xe1, 0x72, 0x09, 0x62, 0x3c,
	0x3e, 0x7e, 0x5e, 0x8e, 0xf1, 0xa0, 0xcc, 0xa3, 0x2a, 0x1d, 0xfb, 0xb6, 0xd6, 0x20, 0xc4, 0x8d,
	0x81, 0x65, 0xf5, 0x89, 0xcb, 0x9d, 0x77, 0xc6, 0x57, 0x43, 0x56, 0x17, 0xd4, 0x40, 0x1a, 0x4d,
	0xc0, 0x63, 0x6c, 0xe3, 0xb7, 0xc8, 0x64, 0x6a, 0x53, 0xaa, 0x38, 0x98, 0x0c, 0xf4, 0x9b, 0xed,
	0x7f, 0x22, 0x76, 0xaf, 0xdd, 0x3a, 0x0b, 0x58, 0x67, 0x88, 0x06, 0xc3, 0x35, 0x0d, 0x01, 0x8b,
	0x8c, 0xc2, 0xe6, 0x5f, 0x02, 0x24, 0x75, 0x93, 0x66, 0x1e, 0xe5, 0xe2, 0x54, 0xd8, 0x10, 0xce,
	0x7a, 0xe8, 0x08, 0x2c, 0x12, 0x97, 0x32, 0xab, 0xb4, 0x27, 0x0a, 0x23, 0xdf, 0xef, 0xca, 0xd9,
	0xb8, 0xfa, 0xdc, 0x31, 0x6b, 0xd1, 0xad, 0x19, 0x49, 0xbd, 0x51, 0x96, 0xee, 0xe4, 0xa8, 0x41,
	0xda, 0xff, 0xcd, 0x55, 0x86, 0x36, 0xbe, 0x61, 0x52, 0xf8, 0xbb, 0x0e, 0x82, 0x48, 0x69, 0x9a,
	0xe0, 0x47, 0x9e, 0x5c, 0x04, 0x4b, 0x34, 0x15, 0x79, 0x26, 0xa7, 0xde, 0x29, 0xae, 0x92, 0xd7,
	0x84, 0xe9, 0xd2, 0xba, 0x5d, 0xf3, 0xc5, 0xb0, 0xbf, 0xa4, 0x3b, 0x71, 0x44, 0x46, 0x2b, 0xfc,
	0xeb, 0x6f, 0xd5, 0xf6, 0x14, 0xfe, 0x7c, 0x70, 0x5a, 0x7d, 0xfd, 0x2f, 0x18, 0x83, 0x16, 0xa5,
	0x91, 0x1f, 0x05, 0x95, 0x74, 0xa9, 0xc1, 0x5b, 0x4a, 0x85, 0x6d, 0x13, 0x07, 0x4f, 0x4e, 0x45,
	0xb2, 0x0f, 0xc9, 0x1c, 0xa6, 0xbc, 0xec, 0x73, 0x90, 0x7b, 0xcf, 0x59, 0x8f, 0xa1, 0xf9, 0x2d,
	0xf2, 0xb1, 0x00, 0x94, 0x37, 0x9f, 0xd0, 0x2e, 0x9c, 0x6e, 0x28, 0x3f, 0x80, 0xf0, 0x3d, 0xd3,
	0x25, 0x8a, 0xb5, 0xe7, 0x42, 0xb3, 0xc7, 0xea, 0xf7, 0x4c, 0x11, 0x33, 0x03, 0xa2, 0xac, 0x60
};
int x[256][16], y[256][16], z[256][16], dx[256][16], dy[256][16], dz[256][16];
vector<int> DDT_Sbox1[256][256], DDT_Sbox2[256][256], DDT_iSbox1[256][256], DDT_iSbox2[256][256];
FILE* in;
int seq_cnt = 0;

int DLA[16][16] = {
	0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,0,
	0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,1,
	0,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,
	1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,
	1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,
	0,1,0,1,1,0,0,0,0,1,1,0,0,0,1,1,
	1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,0,
	0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,0,
	1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,
	1,1,0,0,0,1,1,0,0,0,0,1,1,0,1,0,
	0,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,
	0,0,1,1,1,0,0,1,0,1,0,0,1,0,1,0,
	0,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,
	1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,0,
	1,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0,
	0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,1
};

void build_DDT() {
	for (int i = 0; i < 256; i++) {
		for (int j = i + 1; j < 256; j++) {
			DDT_Sbox1[i ^ j][Sbox1[i] ^ Sbox1[j]].push_back(i);
			DDT_Sbox1[i ^ j][Sbox1[i] ^ Sbox1[j]].push_back(j);

			DDT_Sbox2[i ^ j][Sbox2[i] ^ Sbox2[j]].push_back(i);
			DDT_Sbox2[i ^ j][Sbox2[i] ^ Sbox2[j]].push_back(j);

			DDT_iSbox1[i ^ j][iSbox1[i] ^ iSbox1[j]].push_back(i);
			DDT_iSbox1[i ^ j][iSbox1[i] ^ iSbox1[j]].push_back(j);

			DDT_iSbox2[i ^ j][iSbox2[i] ^ iSbox2[j]].push_back(i);
			DDT_iSbox2[i ^ j][iSbox2[i] ^ iSbox2[j]].push_back(j);
		}
	}
}
void get_16_params() {
	DY[1][0] = rand() % 255 + 1;
	X[2][3] = rand() % 256;
	X[2][4] = rand() % 256;
	X[2][6] = rand() % 256;
	X[2][8] = rand() % 256;
	X[2][9] = rand() % 256;
	X[2][13] = rand() % 256;
	X[2][14] = rand() % 256;
	Y[4][3] = rand() % 256;
	Y[4][4] = rand() % 256;
	Y[4][6] = rand() % 256;
	Y[4][8] = rand() % 256;
	Y[4][9] = rand() % 256;
	Y[4][13] = rand() % 256;
	Y[4][14] = rand() % 256;
	DZ[4][0] = rand() % 255 + 1;
}
void get_sequence() {
	vector<int> cnt(256, 0);
	for (int i = 0; i < 256; i++) {
		x[i][3] = X[2][3] ^ i;
		x[i][4] = X[2][4] ^ i;
		x[i][6] = X[2][4] ^ i;
		x[i][8] = X[2][8] ^ i;
		x[i][9] = X[2][9] ^ i;
		x[i][13] = X[2][13] ^ i;
		x[i][14] = X[2][14] ^ i;

		y[i][3] = iSbox2[x[i][3]];
		y[i][4] = Sbox1[x[i][4]];
		y[i][6] = iSbox1[x[i][6]];
		y[i][8] = Sbox1[x[i][8]];
		y[i][9] = Sbox2[x[i][9]];
		y[i][13] = Sbox1[x[i][13]];
		y[i][14] = iSbox1[x[i][14]];

		dy[i][3] = y[0][3] ^ y[i][3];
		dy[i][4] = y[0][4] ^ y[i][4];
		dy[i][6] = y[0][6] ^ y[i][6];
		dy[i][8] = y[0][8] ^ y[i][8];
		dy[i][9] = y[0][9] ^ y[i][9];
		dy[i][13] = y[0][13] ^ y[i][13];
		dy[i][14] = y[0][14] ^ y[i][14];

		dz[i][0] = dy[i][3] ^ dy[i][4] ^ dy[i][6] ^ dy[i][8] ^ dy[i][9] ^ dy[i][13] ^ dy[i][14];
		dz[i][1] = dy[i][8] ^ dy[i][9];
		dz[i][2] = dy[i][4] ^ dy[i][6];
		dz[i][3] = dy[i][13] ^ dy[i][14];
		dz[i][4] = dy[i][8] ^ dy[i][14];
		dz[i][5] = dy[i][3] ^ dy[i][4] ^ dy[i][9] ^ dy[i][14];
		dz[i][6] = dy[i][9] ^ dy[i][13];
		dz[i][7] = dy[i][3] ^ dy[i][6] ^ dy[i][8] ^ dy[i][13];
		dz[i][8] = dy[i][4] ^ dy[i][13];
		dz[i][9] = dy[i][6] ^ dy[i][14];
		dz[i][10] = dy[i][3] ^ dy[i][6] ^ dy[i][8] ^ dy[i][13];
		dz[i][11] = dy[i][3] ^ dy[i][4] ^ dy[i][9] ^ dy[i][14];
		dz[i][12] = dy[i][6] ^ dy[i][9];
		dz[i][13] = dy[i][3] ^ dy[i][6] ^ dy[i][8] ^ dy[i][13];
		dz[i][14] = dy[i][3] ^ dy[i][4] ^ dy[i][9] ^ dy[i][14];
		dz[i][15] = dy[i][4] ^ dy[i][8];

		for (int j = 0; j < 16; j++) x[i][j] = X[3][j] ^ dz[i][j];

		for (int j = 0; j < 4; j++) {
			y[i][4 * j] = Sbox1[x[i][4 * j]];
			y[i][4 * j + 1] = Sbox2[x[i][4 * j + 1]];
			y[i][4 * j + 2] = iSbox1[x[i][4 * j + 2]];
			y[i][4 * j + 3] = iSbox2[x[i][4 * j + 3]];
		}

		for (int j = 0; j < 16; j++) dy[i][j] = y[0][j] ^ y[i][j];

		dz[i][3] = dy[i][0] ^ dy[i][5] ^ dy[i][7] ^ dy[i][10] ^ dy[i][11] ^ dy[i][13] ^ dy[i][14];
		dz[i][4] = dy[i][0] ^ dy[i][2] ^ dy[i][5] ^ dy[i][8] ^ dy[i][11] ^ dy[i][14] ^ dy[i][15];
		dz[i][6] = dy[i][0] ^ dy[i][2] ^ dy[i][7] ^ dy[i][9] ^ dy[i][10] ^ dy[i][12] ^ dy[i][13];
		dz[i][8] = dy[i][0] ^ dy[i][1] ^ dy[i][4] ^ dy[i][7] ^ dy[i][10] ^ dy[i][13] ^ dy[i][14];
		dz[i][9] = dy[i][0] ^ dy[i][1] ^ dy[i][5] ^ dy[i][6] ^ dy[i][11] ^ dy[i][12] ^ dy[i][14];
		dz[i][13] = dy[i][0] ^ dy[i][3] ^ dy[i][6] ^ dy[i][7] ^ dy[i][8] ^ dy[i][10] ^ dy[i][13];
		dz[i][14] = dy[i][0] ^ dy[i][3] ^ dy[i][4] ^ dy[i][5] ^ dy[i][9] ^ dy[i][11] ^ dy[i][14];

		x[i][3] = X[4][3] ^ dz[i][3];
		x[i][4] = X[4][4] ^ dz[i][4];
		x[i][6] = X[4][6] ^ dz[i][6];
		x[i][8] = X[4][8] ^ dz[i][8];
		x[i][9] = X[4][9] ^ dz[i][9];
		x[i][13] = X[4][13] ^ dz[i][13];
		x[i][14] = X[4][14] ^ dz[i][14];

		y[i][3] = iSbox2[x[i][3]];
		y[i][4] = Sbox1[x[i][4]];
		y[i][6] = iSbox1[x[i][6]];
		y[i][8] = Sbox1[x[i][8]];
		y[i][9] = Sbox2[x[i][9]];
		y[i][13] = Sbox1[x[i][13]];
		y[i][14] = iSbox1[x[i][14]];

		dy[i][3] = y[0][3] ^ y[i][3];
		dy[i][4] = y[0][4] ^ y[i][4];
		dy[i][6] = y[0][6] ^ y[i][6];
		dy[i][8] = y[0][8] ^ y[i][8];
		dy[i][9] = y[0][9] ^ y[i][9];
		dy[i][13] = y[0][13] ^ y[i][13];
		dy[i][14] = y[0][14] ^ y[i][14];

		dz[i][0] = dy[i][3] ^ dy[i][4] ^ dy[i][6] ^ dy[i][8] ^ dy[i][9] ^ dy[i][13] ^ dy[i][14];

		fprintf(in, "%d ", dz[i][0]);
	}
	fprintf(in, "\n");
	seq_cnt++;
}
void get_30_params() {
	XX[2][3] = X[2][3] ^ DY[1][0];
	XX[2][4] = X[2][4] ^ DY[1][0];
	XX[2][6] = X[2][6] ^ DY[1][0];
	XX[2][8] = X[2][8] ^ DY[1][0];
	XX[2][9] = X[2][9] ^ DY[1][0];
	XX[2][13] = X[2][13] ^ DY[1][0];
	XX[2][14] = X[2][14] ^ DY[1][0];

	DY[2][3] = iSbox2[X[2][3]] ^ iSbox2[XX[2][3]];
	DY[2][4] = Sbox1[X[2][4]] ^ Sbox1[XX[2][4]];
	DY[2][6] = iSbox1[X[2][6]] ^ iSbox1[XX[2][6]];
	DY[2][8] = Sbox1[X[2][8]] ^ Sbox1[XX[2][8]];
	DY[2][9] = Sbox2[X[2][9]] ^ Sbox2[XX[2][9]];
	DY[2][13] = Sbox2[X[2][13]] ^ Sbox2[XX[2][13]];
	DY[2][14] = iSbox1[X[2][14]] ^ iSbox1[XX[2][14]];

	DX[3][0] = DY[2][3] ^ DY[2][4] ^ DY[2][6] ^ DY[2][8] ^ DY[2][9] ^ DY[2][13] ^ DY[2][14];
	DX[3][1] = DY[2][8] ^ DY[2][9];
	DX[3][2] = DY[2][4] ^ DY[2][6];
	DX[3][3] = DY[2][13] ^ DY[2][14];
	DX[3][4] = DY[2][8] ^ DY[2][14];
	DX[3][5] = DY[2][3] ^ DY[2][4] ^ DY[2][9] ^ DY[2][14];
	DX[3][6] = DY[2][9] ^ DY[2][13];
	DX[3][7] = DY[2][3] ^ DY[2][6] ^ DY[2][8] ^ DY[2][13];
	DX[3][8] = DY[2][4] ^ DY[2][13];
	DX[3][9] = DY[2][6] ^ DY[2][14];
	DX[3][10] = DY[2][3] ^ DY[2][6] ^ DY[2][8] ^ DY[2][13];
	DX[3][11] = DY[2][3] ^ DY[2][4] ^ DY[2][9] ^ DY[2][14];
	DX[3][12] = DY[2][6] ^ DY[2][9];
	DX[3][13] = DY[2][3] ^ DY[2][6] ^ DY[2][8] ^ DY[2][13];
	DX[3][14] = DY[2][3] ^ DY[2][4] ^ DY[2][9] ^ DY[2][14];
	DX[3][15] = DY[2][4] ^ DY[2][8];

	YY[4][3] = Y[4][3] ^ DZ[4][0];
	YY[4][4] = Y[4][4] ^ DZ[4][0];
	YY[4][6] = Y[4][6] ^ DZ[4][0];
	YY[4][8] = Y[4][8] ^ DZ[4][0];
	YY[4][9] = Y[4][9] ^ DZ[4][0];
	YY[4][13] = Y[4][13] ^ DZ[4][0];
	YY[4][14] = Y[4][14] ^ DZ[4][0];

	X[4][3] = Sbox2[Y[4][3]];
	X[4][4] = iSbox1[Y[4][4]];
	X[4][6] = Sbox1[Y[4][6]];
	X[4][8] = iSbox1[Y[4][8]];
	X[4][9] = iSbox2[Y[4][9]];
	X[4][13] = iSbox2[Y[4][13]];
	X[4][14] = Sbox1[Y[4][14]];

	DZ[3][3] = X[4][3] ^ Sbox2[YY[4][3]];
	DZ[3][4] = X[4][4] ^ iSbox1[YY[4][4]];
	DZ[3][6] = X[4][6] ^ Sbox1[YY[4][6]];
	DZ[3][8] = X[4][8] ^ iSbox1[YY[4][8]];
	DZ[3][9] = X[4][9] ^ iSbox2[YY[4][9]];
	DZ[3][13] = X[4][13] ^ iSbox2[YY[4][13]];
	DZ[3][14] = X[4][14] ^ Sbox1[YY[4][14]];

	DY[3][0] = DZ[3][3] ^ DZ[3][4] ^ DZ[3][6] ^ DZ[3][8] ^ DZ[3][9] ^ DZ[3][13] ^ DZ[3][14];
	DY[3][1] = DZ[3][8] ^ DZ[3][9];
	DY[3][2] = DZ[3][4] ^ DZ[3][6];
	DY[3][3] = DZ[3][13] ^ DZ[3][14];
	DY[3][4] = DZ[3][8] ^ DZ[3][14];
	DY[3][5] = DZ[3][3] ^ DZ[3][4] ^ DZ[3][9] ^ DZ[3][14];
	DY[3][6] = DZ[3][9] ^ DZ[3][13];
	DY[3][7] = DZ[3][3] ^ DZ[3][6] ^ DZ[3][8] ^ DZ[3][13];
	DY[3][8] = DZ[3][4] ^ DZ[3][13];
	DY[3][9] = DZ[3][6] ^ DZ[3][14];
	DY[3][10] = DZ[3][3] ^ DZ[3][6] ^ DZ[3][8] ^ DZ[3][13];
	DY[3][11] = DZ[3][3] ^ DZ[3][4] ^ DZ[3][9] ^ DZ[3][14];
	DY[3][12] = DZ[3][6] ^ DZ[3][9];
	DY[3][13] = DZ[3][3] ^ DZ[3][6] ^ DZ[3][8] ^ DZ[3][13];
	DY[3][14] = DZ[3][3] ^ DZ[3][4] ^ DZ[3][9] ^ DZ[3][14];
	DY[3][15] = DZ[3][4] ^ DZ[3][8];

	for (int i = 0; i < 4; i++) {
		if (DDT_Sbox1[DX[3][4 * i]][DY[3][4 * i]].size() == 0) return;
	}
	for (int i = 0; i < 4; i++) {
		if (DDT_Sbox2[DX[3][4 * i + 1]][DY[3][4 * i + 1]].size() == 0) return;
	}
	for (int i = 0; i < 4; i++) {
		if (DDT_iSbox1[DX[3][4 * i + 2]][DY[3][4 * i + 2]].size() == 0) return;
	}
	for (int i = 0; i < 4; i++) {
		if (DDT_iSbox2[DX[3][4 * i + 3]][DY[3][4 * i + 3]].size() == 0) return;
	}

	printf("found!\n");
	for (auto i0 : DDT_Sbox1[DX[3][0]][DY[3][0]]) {
		for (auto i1 : DDT_Sbox2[DX[3][1]][DY[3][1]]) {
			for (auto i2 : DDT_iSbox1[DX[3][2]][DY[3][2]]) {
				for (auto i3 : DDT_iSbox2[DX[3][3]][DY[3][3]]) {
					for (auto i4 : DDT_Sbox1[DX[3][4]][DY[3][4]]) {
						for (auto i5 : DDT_Sbox2[DX[3][5]][DY[3][5]]) {
							for (auto i6 : DDT_iSbox1[DX[3][6]][DY[3][6]]) {
								for (auto i7 : DDT_iSbox2[DX[3][7]][DY[3][7]]) {
									for (auto i8 : DDT_Sbox1[DX[3][8]][DY[3][8]]) {
										for (auto i9 : DDT_Sbox2[DX[3][9]][DY[3][9]]) {
											for (auto i10 : DDT_iSbox1[DX[3][10]][DY[3][10]]) {
												for (auto i11 : DDT_iSbox2[DX[3][11]][DY[3][11]]) {
													for (auto i12 : DDT_Sbox1[DX[3][12]][DY[3][12]]) {
														for (auto i13 : DDT_Sbox2[DX[3][13]][DY[3][13]]) {
															for (auto i14 : DDT_iSbox1[DX[3][14]][DY[3][14]]) {
																for (auto i15 : DDT_iSbox2[DX[3][15]][DY[3][15]]) {
																	X[3][0] = i0;
																	X[3][1] = i1;
																	X[3][2] = i2;
																	X[3][3] = i3;
																	X[3][4] = i4;
																	X[3][5] = i5;
																	X[3][6] = i6;
																	X[3][7] = i7;
																	X[3][8] = i8;
																	X[3][9] = i9;
																	X[3][10] = i10;
																	X[3][11] = i11;
																	X[3][12] = i12;
																	X[3][13] = i13;
																	X[3][14] = i14;
																	X[3][15] = i15;
																	get_sequence();
																	if (seq_cnt == 1048576) return;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int main() {
	in = fopen("sampling_result_ARIA.txt", "w");
	build_DDT();
	while (true) {
		get_16_params();
		get_30_params();
		if (seq_cnt == 1048576) {
      fclose(in);
      break;
    }
	}
}
