#include <iostream>
#include "date.h"
#define MAXLISTVE 200

struct ve {
	char soVe[5];
	char soCMND[10];
};
typedef ve Ve;

struct NodeVe {
	Ve data;
};
typedef nodeVe nodeVe;

struct danhsachve {
	int n = 0;
	nodeVe dsVe[MAXLISTVE];
};
typedef danhsachve danhSachVe;

struct chuyenbay {
	char maChuyenBay[20];
	NGAY_THANG ngayKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	danhSachVe listVe;
};
typedef chuyenbay chuyenBay;

struct nodeChuyenBay {
	chuyenBay data;
	struct nodeChuyenBay *next;
};
typedef nodeChuyenBay* PTRChuyenBay;

struct Linked_List {
	int n = 0;
	PTRChuyenBay First = NULL;
};
typedef Link_List listChuyenBay;
