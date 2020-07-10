#include <iostream>
#include <string.h>
#include <fstream>
#include "dsmaybay.h"

using namespace std;

int main()
{
	mayBay mb;
	listMayBay lmb;
	readFile(lmb);
	menu(lmb,mb);
	writeFile(lmb);
	
	return 0;
}
