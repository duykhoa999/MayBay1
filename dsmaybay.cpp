#include <iostream>
#include <string.h>
#include "dsmaybay.h"

//Xem lai kiem tra trung so hieu sau!

using namespace std;

mayBay nhap() 
{
	mayBay mb;
	listMayBay lmb;
	do 
	{
		fflush(stdin);
		cout<<"Nhap so hieu may bay: ";
		gets(mb.soHieuMayBay);
		if(checkNhapKyTu(mb.soHieuMayBay) == 1 && searchNodeMB(lmb,mb.soHieuMayBay) == -1)
		{
			int l = strlen(mb.soHieuMayBay);
			break;
		}
		else if (checkNhapKyTu(mb.soHieuMayBay) == 0)cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
		if (searchNodeMB(lmb,mb.soHieuMayBay) != -1) cout<<"So hieu nay da ton tai. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTu(mb.soHieuMayBay) != 1  && searchNodeMB(lmb,mb.soHieuMayBay) != -1);
	
	do
	{
		fflush(stdin);
		cout<<"Nhap loai may bay: ";
		gets(mb.loaiMayBay);
		if(checkNhapKyTu(mb.loaiMayBay) == 1)
		{
			int l = strlen(mb.loaiMayBay);
			chuanHoaChuoi(mb.loaiMayBay,l);
			break;
		}
		else if (checkNhapKyTu(mb.loaiMayBay) == 0)	cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTu(mb.loaiMayBay) != 1);
	
	cout<<"Nhap so day cua may bay: ";
	cin>>mb.soDay;
		
	cout<<"Nhap so dong cua may bay: ";
	cin>>mb.soDong;
	
	return mb;
}

int searchNodeMB(listMayBay lmb, char *s) 
{
	for (int j = 0; j < lmb.n; j++)
	{
		if (stricmp(lmb.NodeMayBay[j]->data.soHieuMayBay,s) == 0)
			return j;
	}
	return -1;
}

void deleteNode(listMayBay &lmb, int i) 
{
	int j;
	
	for (j = i+1 ; j < lmb.n; j++)
	{
		lmb.NodeMayBay[j-1] = lmb.NodeMayBay[j];
	}
	lmb.n--;
}

void updateNode(listMayBay lmb, int i)
{
	int luachon;
	mayBay mb;
	mb = lmb.NodeMayBay[i]->data;
	do
	{
		cout<<"\n\nThong tin may bay"<<endl;
		xuat(lmb.NodeMayBay[i]->data);
		cout<<"\n\nBan muon hieu chinh thong tin nao?"<<endl;		
		cout<<"1. So hieu may bay"<<endl;
		cout<<"2. Loai may bay"<<endl;
		cout<<"3. So day"<<endl;
		cout<<"4. So dong"<<endl;
		cout<<"5. Thoat"<<endl;
		cout<<"Lua chon cua ban: ";
		cin>>luachon;
		string kt;
		switch(luachon)
		{
			case 1:
				fflush(stdin);
				cout<<"Nhap lai thong tin can chinh sua: ";
				gets(mb.soHieuMayBay);
				break;
			case 2:
				fflush(stdin);
				cout<<"Nhap lai thong tin can chinh sua: ";
				gets(mb.loaiMayBay);
				break;
			case 3:
				cout<<"Nhap lai thong tin can chinh sua: ";
				cin>>mb.soDay;
				break;
			case 4:
				cout<<"Nhap lai thong tin can chinh sua: ";
				cin>>mb.soDong;
				break;
		}
		cout<<"Ban muon hieu chinh nua khong(y/n)?";
		cin>>kt;
		if (kt == "n") break;
	} while(luachon != 5);
	lmb.NodeMayBay[i]->data = mb;
	cout<<"Cap nhat thanh cong!"<<endl;
}

void chuanHoaChuoi (char st[100], int &l)
{
	int i;
	while (st[0] == ' ')
		strcpy(st,st+1);
	l=strlen (st);
	while(st[l-1] == ' ')
	{
		strcpy(st+l-1,st+l);
		l--;
	}
	while (st[i] != '\0')
	{
		if (st[i] == ' ')
			if (st[i+1] == ' ')
			{
				strcpy(st+i,st+i+1);
				i--;
				l--;
			}
			else i++;
	i++;
	}
}

int checkNhapKyTu (char *a)
{
	int dem = 0;
	if (a[0] == '\0') return 0;
	for (int i = 0;i<strlen(a);i++)
		if (((a[i]>=65) && (a[i]<=90)) || ((a[i]>=97) && (a[i]<=122)) || ((a[i] >= 48) && (a[i] <= 57)) || a[i] == 32)
			dem++;
	if(dem == strlen(a))	return 1;
	return 2;
}

int fullDS (listMayBay lmb) 
{
	return lmb.n == MAXLIST;
}

void insertNode(listMayBay &lmb, mayBay mb)
{
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
