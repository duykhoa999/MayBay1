#include <iostream>

struct hanhkhach {
	int CMND;
	char ho[8];
	char tendem[8];
	char ten[8];
	int phai;
};
typedef hanhkhach hanhKhach;

struct nodeHanhKhach {
	hanhKhach data;
	struct nodeHanhKhach *Left;
	struct nodeHanhKhach *Right;
};
typedef nodeHanhKhach NodeHanhKhach;
typedef NodeHanhKhach* TREEhanhkhach;
