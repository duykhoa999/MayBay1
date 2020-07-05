#include <iostream>
#include "date.h"

struct chuyenbay {
	char maChuyenBay[20];
	NGAY_THANG ngayKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
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
