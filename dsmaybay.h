#include <iostream>
#define MAXLIST 300

struct maybay{
	char soHieuMayBay[20];
	char loaiMayBay[45];
	int soDay;
	int soDong;
};
typedef struct maybay mayBay;

struct nodeMayBay {
	mayBay data;
};
typedef struct nodeMayBay nodeMB;
typedef struct nodeMayBay* NODEMAYBAY;

struct ListMayBay{
	int n = 0;
	NODEMAYBAY NodeMayBay[MAXLIST];
};
typedef struct ListMayBay listMayBay;

mayBay nhap(listMayBay &lmb, mayBay &mb);

void xuat(mayBay mb);

int fullDS (listMayBay lmb);

void insertNode (listMayBay &lmb, mayBay mb);

void chuanHoaChuoi (char st[100], int &l);

int checkNhapKyTu (char *a);

int searchNodeMB(listMayBay lmb, char *s);

void deleteNode(listMayBay &lmb, int i);

void updateNode(listMayBay &lmb, int i);

void nhapSoHieu(listMayBay &lmb, char *soHieu);

void nhapLoaiMB(listMayBay &lmb, char *loaiMB);

void menu(listMayBay &lmb, mayBay &mb);

