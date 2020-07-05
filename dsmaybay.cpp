#include <iostream>
#include <string.h>
#include "dsmaybay.h"

using namespace std;

mayBay nhap() 
{
	mayBay mb;
	NODEMAYBAY nmb;
	fflush(stdin);
	cout<<"Nhap so hieu may bay: ";
	gets(mb.soHieuMayBay);
	fflush(stdin);
	cout<<"Nhap loai may bay: ";
	gets(mb.loaiMayBay);
	cout<<"Nhap so day cua may bay: ";
	cin>>mb.soDay;
	cout<<"Nhap so dong cua may bay: ";
	cin>>mb.soDong;
	
	
	
	return mb;
}

bool isNhap(char *s) 
{
	if (stricmp(s,"\n"))
}

int fullDS (listMayBay lmb) 
{
	return lmb.n == MAXLIST;
}

void insertNode (listMayBay &lmb, mayBay mb)
{
	int i = lmb.n;
	NODEMAYBAY nmb;
	nmb = new nodeMB;
	nmb->data = mb;
	if (fullDS(lmb))
	{
		cout<<"Danh sach day khong them duoc nua!";
		return;
	}
	lmb.NodeMayBay[lmb.n] = nmb;
	lmb.n++;
	
}

void xuat(mayBay mb)
{
	cout<<"\nSo hieu may bay: "<<mb.soHieuMayBay<<endl;
	cout<<"Loai may bay: "<<mb.loaiMayBay<<endl;
	cout<<"So day cua may bay: "<<mb.soDay<<endl;
	cout<<"So dong cua may bay: "<<mb.soDong<<endl;
}
