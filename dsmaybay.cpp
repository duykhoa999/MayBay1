#include <iostream>
#include <string.h>
#include <conio.h>
#include "dsmaybay.h"
#include "mylib.h"

//thieu buoc kiem tra chuyen bay da khoi hanh chua khi xo�

using namespace std;

mayBay nhap(listMayBay &lmb, mayBay &mb) 
{
	
	nhapSoHieu(lmb,mb.soHieuMayBay);
	
	nhapLoaiMB(lmb,mb.loaiMayBay);
	
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

int checkNhapKyTu (char *a)
{
	int dem = 0;
	if (a[0] == '\0') 
	{
		return 0;
	}
	
	for (int i = 0;i<strlen(a);i++)
		if (((a[i]>=65) && (a[i]<=90)) || ((a[i]>=97) && (a[i]<=122)) || ((a[i] >= 48) && (a[i] <= 57)) || a[i] == 32)
			dem++;
	if(dem == strlen(a))	return 1;
	return 2;
}

void nhapLoaiMB(listMayBay &lmb, char *loaiMB)
{
	do
	{
		fflush(stdin);
		cout<<"Nhap loai may bay: ";
		gets(loaiMB);
		if(checkNhapKyTu(loaiMB) == 1)
		{
			int l = strlen(loaiMB);
			chuanHoaChuoi(loaiMB,l);
			break;
		}
		else if (checkNhapKyTu(loaiMB) == 0)	cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTu(loaiMB) != 1);
}

void nhapSoHieu(listMayBay &lmb, char *soHieu)
{
	Nhap:
		fflush(stdin);
		cout<<"Nhap so hieu may bay: ";
		gets(soHieu);
		if (searchNodeMB(lmb,soHieu) >= 0)
		{
			cout<<"So hieu nay da ton tai. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(soHieu) == 2)
		{
			cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(soHieu) == 0)
		{
			cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
			goto Nhap;
		} 
		else
		{
			int l = strlen(soHieu);
			chuanHoaChuoi(soHieu,l);
		}
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

void updateNode(listMayBay &lmb, int i)
{
	int luachon;
	mayBay mb;
	mb = lmb.NodeMayBay[i]->data;
	do
	{
		clrscr();
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
				cout<<"Nhap lai thong tin can chinh sua!"<<endl;
				nhapSoHieu(lmb,mb.soHieuMayBay);
				break;
			case 2:
				fflush(stdin);
				cout<<"Nhap lai thong tin can chinh sua!"<<endl;
				nhapLoaiMB(lmb,mb.loaiMayBay);
				break;
			case 3:
				cout<<"Nhap lai thong tin can chinh sua!";
				cout<<"Nhap so day: ";
				cin>>mb.soDay;
				break;
			case 4:
				cout<<"Nhap lai thong tin can chinh sua!";
				cout<<"Nhap so dong: ";
				cin>>mb.soDong;
				break;
		}
		cout<<"Ban muon hieu chinh nua khong(y/n)?";
		cin>>kt;
		if (kt == "n") break;
	} while(luachon != 5);
	lmb.NodeMayBay[i]->data = mb;
	cout<<"\nCap nhat thanh cong! Nhan Enter de ve menu!"<<endl;
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

void menu(listMayBay &lmb, mayBay &mb)
{
	char s[20];
	int luachon;
	string kt;
	do
	{
		clrscr();
		cout<<"\n\n-----Menu-----"<<endl;		
		cout<<"1. Them may bay"<<endl;
		cout<<"2. Xuat thong tin may bay"<<endl;
		cout<<"3. Chinh sua thong tin may bay"<<endl;
		cout<<"4. Xoa thong tin may bay"<<endl;
		cout<<"5. Thoat"<<endl;
		cout<<"Lua chon cua ban: ";
		cin>>luachon;
		switch(luachon)
		{
			case 1:
				do
				{
					cout<<"\nNhap thong tin may bay!"<<endl;
					mb = nhap(lmb,mb);
					insertNode(lmb,mb);
					cout<<"Ban muon nhap nua khong(y/n)?";
					cin>>kt;
					if (kt == "n") break;
				} while (true);
				break;
			case 2:
				cout<<"\n\n\n\nDanh sach vua nhap la!"<<endl;
				for (int i = 0; i < lmb.n; i++)
				{
					cout<<"\n\nMay bay thu "<<i+1<<"!";
					xuat(lmb.NodeMayBay[i]->data);
				}
				cout<<"\nNhan Enter de ve lai menu!";
				getch();
				break;
			case 3:
				cout<<"\n\nNhap vao so hieu may bay muon hieu chinh: ";
				fflush(stdin);
				gets(s);
				if (searchNodeMB(lmb,s) == -1) 
				{
					cout<<"\nKhong tim thay so hieu nay! Nhan Enter de ve menu!";
					getch();
				}
				else 
				{
					updateNode(lmb,searchNodeMB(lmb,s));
					getch();
				}
				break;
			case 4:
				cout<<"\n\nNhap vao so hieu may bay muon xoa: ";
				fflush(stdin);
				gets(s);
				if (searchNodeMB(lmb,s) == -1) 
				{
					cout<<"\nKhong tim thay so hieu nay! Nhan Enter de ve menu!";
					getch();
				}
				else 
				{
					cout<<"Ban co chac chan muon xoa khong(y/n)?";
					cin>>kt;
					if (kt == "y")
					{
						deleteNode(lmb,searchNodeMB(lmb,s));
						cout<<"\nXoa thanh cong! Nhan Enter de ve menu!";
						getch();
					}
				}
				break;
		}
//		cout<<"Ban muon hieu chinh nua khong(y/n)?";
//		cin>>kt;
//		if (kt == "n") break;
	} while(luachon != 5);
}

