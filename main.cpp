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
	
	return 0;
}
