#include <iostream>
#include <string.h>
#include "dsmaybay.h"

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
		if(checkNhapKyTu(mb.soHieuMayBay) == 1 && !kiemTraTrung(lmb,mb.soHieuMayBay))
		{
			int l = strlen(mb.soHieuMayBay);
			chuanHoaChuoi(mb.soHieuMayBay,l);
			break;
		}
		else if (checkNhapKyTu(mb.soHieuMayBay) == 0)cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
		if (kiemTraTrung(lmb,mb.soHieuMayBay)) cout<<"So hieu nay da ton tai. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTu(mb.soHieuMayBay) != 1 && kiemTraTrung(lmb,mb.soHieuMayBay));
	
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

bool kiemTraTrung(listMayBay lmb, char *s) 
{
	for (int j = 0; j < lmb.n; j++)
	{
		if (stricmp(lmb.NodeMayBay[j]->data.soHieuMayBay,s) == 0)
			return true;
	}
	return false;
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
		if (((a[i]>=65) && (a[i]<=90)) || ((a[i]>=97) && (a[i]<=122)) || ((a[i] >= 48) && (a[i] <= 57)) || a[i]==32)
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
