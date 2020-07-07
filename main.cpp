#include <iostream>
#include <string.h>
#include "dsmaybay.h"

using namespace std;

int main()
{
	mayBay mb;
	NODEMAYBAY nmb;
	listMayBay lmb;
	int n;
	char s[20];
	cout<<"So luong may bay can nhap: ";
	cin>>n;
	for (int i = 1; i<=n; i++)
	{
		cout<<"\n\nThong tin may bay thu " <<i<<": "<<endl;
		mb = nhap();
		insertNode(lmb,mb);
	}

	cout<<"\n\n\n\nDanh sach vua nhap la!"<<endl;
	for (int i = 0; i < lmb.n; i++)
	{
		cout<<"\n\nMay bay thu "<<i+1<<"!";
		xuat(lmb.NodeMayBay[i]->data);
	}
//	cout<<"\n\nNhap vao so hieu may bay muon hieu chinh: ";
//	fflush(stdin);
//	gets(s);
//	if (searchNodeMB(lmb,s) == -1) cout<<"Khong tim thay so hieu nay!";
//	else updateNode(lmb,searchNodeMB(lmb,s));
	//deleteNode(lmb,searchNodeMB(lmb,s));
	
//	for (int i = 0; i < lmb.n; i++)
//	{
//		cout<<"\n\nMay bay thu "<<i+1<<"!";
//		xuat(lmb.NodeMayBay[i]->data);
//	}
	
	return 0;
}
