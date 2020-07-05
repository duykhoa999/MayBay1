#include<stdlib.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

// 1800 <  NAM < 9999

const int max_nam=9999;
const int min_nam=1800;
struct NgayThang
{
	 int ngay;
	 int thang;
	 int nam;
};
typedef struct NgayThang NGAY_THANG;
