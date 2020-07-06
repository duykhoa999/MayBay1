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
typedef ListMayBay listMayBay;

mayBay nhap();

void xuat(mayBay mb);

int fullDS (listMayBay lmb);

void insertNode (listMayBay &lmb, mayBay mb);

void chuanHoaChuoi (char st[100], int &l);

int checkNhapKyTu (char *a);

bool kiemTraTrung(listMayBay lmb, char *s);

