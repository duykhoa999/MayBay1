#include <iostream>
#define MAX 300

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
	NODEMAYBAY nodeMB[MAX];
};
typedef ListMayBay listMayBay;
