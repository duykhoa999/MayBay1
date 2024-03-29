#include <iostream>
#include "chuyenbay.h"

using namespace std;

chuyenBay nhapChuyenBay(PTRListChuyenBay &First, chuyenBay &cb, listMayBay lmb) 
{
	nhapMaCB(First, cb.maChuyenBay);
	cout<<"Nhap ngay gio khoi hanh!"<<endl;
	cb.ngayKhoiHanh = nhapNgayThangNam();
	cb.gioKhoiHanh = nhapGioKhoiHanh();
	fflush(stdin);
	cout<<"Nhap san bay den: ";
	gets(cb.sanBayDen);
	nhapSoHieuCB(lmb, cb.soHieuMayBay);
	
	return cb;
}

void xuatChuyenBay(chuyenBay cb)
{
	cout<<"\nMa chuyen bay: "<<cb.maChuyenBay<<endl;
	cout<<"Ngay khoi hanh: "<<cb.ngayKhoiHanh.ngay<<"-"<<cb.ngayKhoiHanh.thang<<"-"<<cb.ngayKhoiHanh.nam<<endl;
	cout<<"Gio khoi hanh: "<<cb.gioKhoiHanh.gio<<":"<<cb.gioKhoiHanh.phut<<endl;
	cout<<"San bay den: "<<cb.sanBayDen<<endl;
}

void insertNodeCB(PTRListChuyenBay &First, chuyenBay cb)
{
	PTRListChuyenBay p = new listChuyenBay;
		p->data = cb ; 
		p->next=NULL;
		if (First==NULL) 
			First = p;
		else 
		{ PTRListChuyenBay Last;
	       for (Last = First;Last->next !=NULL; Last=Last->next) ;		
	       Last->next = p;
	   	}
}

void traverseCB(PTRListChuyenBay First)
{
	for(PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		xuatChuyenBay(p->data);
	}
}

void deleteNodeCB(PTRListChuyenBay &First)
{
	char maChuyenBay[20];
	PTRListChuyenBay p;
	string kt;
	Xoatiep	 :
		cout << "\nMa chuyen bay vien muon xoa :" ;
		fflush(stdin); 
		gets(maChuyenBay);
		
		if (stricmp(First->data.maChuyenBay,maChuyenBay) == 0)
		{
			cout<<"Ban co that su muon xoa hay khong (Y/N)?";
			cin>>kt;
			if (kt == "y") 
			{
				PTRListChuyenBay p = First;
				First = p ->next ; 
				delete p;
				cout<<"Xoa thanh cong! Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
			else
			{
				cout<<"Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
		}
		for(p = First; p->next != NULL && stricmp(p->next->data.maChuyenBay, maChuyenBay) != 0; p = p->next);
		if (p->next!=NULL)
		{
			cout<<"Ban co that su muon xoa hay khong (Y/N)?";
			cin>>kt;
			if (kt == "y") 
			{
				PTRListChuyenBay q = p->next ;
				p->next= q->next;
				delete q;
				cout<<"Xoa thanh cong! Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
			else
			{
				cout<<"Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
		}
		else 
		{
			cout << "Ma chuyen bay muon xoa khong ton tai. Ban co muon xoa nua khong(y/n)?";
			cin>>kt;
			if (kt == "y")
			{
				goto Xoatiep;
			}
		}
		return;
}

//void DSVe1 ()
//{	
//	char x[5] = "ABCD";
//	char temp[4];
//	int i = 2;
//	char array[3];
//	itoa(i,array,10);
//	temp[0] = x[0];
//	temp[1] = '\0';
////	temp[1] = array[0];
////	temp[2] = array[1];
//	strcat(temp, "0");
//	strcat(temp,array);
//	cout<<temp;
//	
//}

void DSVe (listMayBay lmb, chuyenBay &cb)
{
	char day[26] = "ABCDEFGHIJKLMN";
	char temp[4];
	int tempSDay = lmb.NodeMayBay[searchNodeMB(lmb,cb.soHieuMayBay)]->data.soDay;
	int tempSDong = lmb.NodeMayBay[searchNodeMB(lmb,cb.soHieuMayBay)]->data.soDong;
	cb.listVe.dsVe = new nodeVe[tempSDay*tempSDong];
	int k = 0;
	for (int i = 0; i< tempSDay; i++)
	{
		temp[0] = day[i];
		for (int j = 1; j <= tempSDong; j++)
		{
			if (j < 10)
			{
				
				char array[3];
				temp[1] = '\0';
				strcat(temp,"0");
				itoa(j, array, 10);
				strcat(temp,array);
			}
			else
			{
				char array[3];
				temp[1] = '\0';
				itoa(j, array, 10);
				strcat(temp, array);
			}
			strcpy(cb.listVe.dsVe[k].data.soVe,temp);
			//cb.listVe.dsVe[k].data.soVe
			//cb.listVe.dsVe++;
//			cout<<cb.listVe.dsVe[k].data.soVe<<endl;
			cb.listVe.n++;
			k++;
		}
	}
}

bool searchNodeCB(PTRListChuyenBay First, char *s)
{
	for (PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		if(stricmp(p->data.maChuyenBay,s) == 0)
			return true;
	}
	return false;
}

void nhapSoHieuCB(listMayBay &lmb, char *soHieu)
{
	Nhap:
		fflush(stdin);
		cout<<"Nhap so hieu may bay: ";
		gets(soHieu);
		int l = strlen(soHieu);
		chuanHoaChuoi(soHieu,l);
		if (searchNodeMB(lmb,soHieu) < 0)
		{
			cout<<"Khong tim thay so hieu nay. Vui long nhap lai!"<<endl;
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
}

void nhapMaCB(PTRListChuyenBay &First, char *MaCB)
{
	Nhap:
		fflush(stdin);
		cout<<"Nhap ma chuyen bay: ";
		gets(MaCB);
		int l = strlen(MaCB);
		chuanHoaChuoi(MaCB,l);
		if (searchNodeCB(First,MaCB))
		{
			cout<<"Ma nay da ton tai. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(MaCB) == 2)
		{
			cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(MaCB) == 0)
		{
			cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
}

NGAY_THANG nhapNgayThangNam()
{
	NGAY_THANG nt;
	cout<<"Nhap ngay khoi hanh: ";
	cin>>nt.ngay;
	cout<<"Nhap thang khoi hanh: ";
	cin>>nt.thang;
	cout<<"Nhap nam khoi hanh: ";
	cin>>nt.nam;
	
	return nt;
}

NGAY_THANG nhapGioKhoiHanh()
{
	NGAY_THANG gp;
	cout<<"Nhap gio khoi hanh: ";
	cin>>gp.gio;
	cout<<"Nhap phut khoi hanh: ";
	cin>>gp.phut;
	
	return gp;
}
