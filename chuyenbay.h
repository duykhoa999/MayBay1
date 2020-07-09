#include <iostream>
#include "date.h"
#define MAXLISTVE 200

struct ve {
	char soVe[5];
	char soCMND[12];
};
typedef struct ve Ve;

struct NodeVe {
	Ve data;
};
typedef struct nodeVe nodeVe;

struct danhsachve {
	int n = 0;
	nodeVe *dsVe;
};
typedef struct danhsachve danhSachVe;

struct chuyenbay {
	char maChuyenBay[20];
	NGAY_THANG ngayKhoiHanh;
	NGAY_THANG gioKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	danhSachVe listVe;
};
typedef struct chuyenbay chuyenBay;

struct nodeChuyenBay {
	chuyenBay data;
	struct nodeChuyenBay *next;
};
typedef struct nodeChuyenBay* PTRChuyenBay;

struct Linked_List {
	int n = 0;
	PTRChuyenBay First = NULL;
};
typedef struct Link_List listChuyenBay;
