#include <iostream>
#include <string.h>
#include <fstream>
#include "chuyenbay.h"
#include "hanhkhach.h"

using namespace std;

int main()
{
	chuyenBay cb;
	string kt;
	PTRListChuyenBay First;
	TREEhanhkhach t;
	First = NULL;
	mayBay mb;
	listMayBay lmb;
//	menu(lmb,mb);
//	do
//	{
//		cout<<"\nNhap thong tin chuyen bay!"<<endl;
//		cb = nhapChuyenBay(First,cb,lmb);
//		insertNodeCB(First, cb);
//		cout<<"Ban muon nhap nua khong(y/n)?";
//		cin>>kt;
//		if (kt == "n") break;
//	} while (true);
//	gets(cb.soHieuMayBay);
//	DSVe(lmb,cb);
//	for(int i = 0; i < cb.listVe.n; i++)
//	{
//		cout<<cb.listVe.dsVe[i].data.soVe<<endl;
//	}
//	menu(lmb,mb);
	menuHK();
//	traverseCB(First);
//	deleteNodeCB(First);
//	traverseCB(First);

	
	return 0;
}
