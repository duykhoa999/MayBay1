#include <iostream>

struct hanhkhach {
	char soCMND[12];
	char ho[50];
	char ten[10];
	int phai;
};
typedef struct hanhkhach hanhKhach;

struct nodeHanhKhach {
	hanhKhach data;
	struct nodeHanhKhach *Left;
	struct nodeHanhKhach *Right;
};
typedef struct nodeHanhKhach NodeHanhKhach;
typedef struct NodeHanhKhach* TREEhanhkhach;
