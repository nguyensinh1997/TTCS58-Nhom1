#include<iostream>
#include<string.h>
#include<math.h>
#include"console.h"
#include <stdio.h>
#include<fstream>
using namespace std;
ifstream h("C:\\Users\\anhng\\Desktop\\BODE1\\cau3\\input3.txt");
ofstream g ("output.txt");
struct Nhanvien{
	int manv,tienluong;
	string ho ;
	string ten ;
};
typedef Nhanvien nhanvien;

void nhapnv_file(nhanvien a[],int &n)
{
	if(h.fail())
		cout<<"khong mo dc file";
	else
		{
			string s;
			getline(h,s);
			n=atof(s.c_str());
			for(int i=0;i<n;i++)
				{
					string str;
					getline(h,str);
					a[i].manv = atof(str.c_str());
					getline(h,str);
					a[i].ho =str;
					getline(h,str);
					a[i].ten =str;
					getline(h,str);
					a[i].tienluong = atof(str.c_str());
					
				}
		}
		
	h.close();
	
}
void ham_nhapnv(nhanvien a[], int &n)
{
		
		fstream f;
		f.open("C:\\Users\\anhng\\Desktop\\BODE1\\cau3\\input3.txt",ios::out);
		cout<<"nhap so luong nv:";cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"nhap thong tin nv thu "<<i+1<<": \n";
				cout<<"ma nv:"; cin>>a[i].manv;
				f<<a[i].manv<<"\t";
				cout<<"ho lot nv: "; cin.sync();
					getline(cin,a[i].ho);
				f<<a[i].ho<<"\t";
				cout<<"ten nv: "; cin.sync();
					getline(cin,a[i].ten);
				f<<a[i].ten<<"\t";
				cout<<"tien luong nv: ";cin>>a[i].tienluong;
				f<<a[i].tienluong<<endl;
				cout<<endl;
			}
		
		f.close();
}
void xuat_nv(nhanvien nv)
{
	
	cout<<nv.manv<<"\t";
	cout<<nv.ho;
	cout<<nv.ten<<"\t";
	cout<<nv.tienluong;
}

void ham_xuatnv(nhanvien a[],int n)
{
	cout<<"\t \t\t\t\t DANH SACH NHAN VIEN"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<"thong tin nv thu "<<i+1<<": ";
			cout<<a[i].manv<<"\t";
		
			cout<<a[i].ho;
			
			cout<<a[i].ten<<"\t";
		
			cout<<a[i].tienluong;
			g<<a[i].manv<<"\t"<<a[i].ho<<"\t"<<a[i].ten<<"\t"<<a[i].tienluong<<endl;
		cout<<endl;
	}

}
// tim thong tin nhan 
void tim_nv(nhanvien a[],int n)
{
		int tam,I;
		int dem=0;
	cout<<"nhap ma nv can tim: "; cin>>tam;
		for(int i=0;i<n;i++)
			{
				
				if(a[i].manv==tam){
					I=i;
					break;
					}
				else
					dem++;
			
			}
			
			if(dem == n) 
			{
				cout<<"Khong tim thay";
				g<<"Khong tim thay"<<endl;
				
				}
				else
						cout<< a[I].ho + a[I].ten;
						g<<a[I].ho <<"\t"<< a[I].ten;
						
						
}
int luongmax(nhanvien a[], int n)
{
	int max ;
	for(int i=0;i<n;i++)
	{
		max= a[i].tienluong;
		if( a[i+1].tienluong >max ) 
			max= a[i+1].tienluong;
		return max;
	}
	
}
void nv_luongmax(nhanvien a[], int n)
{	
	
	for(int j =0;j<n;j++)
	{
		if(a[j].tienluong== luongmax(a,n))
				cout<<a[j].ho<< a[j].ten<<endl;
				g<<a[j].ho<< a[j].ten<<endl;
			
	}	
}
//hien thi thong tin nhan vien co tien luong min

void nv_luongmin(nhanvien a[], int n)
{	
	int min =a[0].tienluong;
	int tam = 0;
	for(int i=0;i<n;i++)
	{
		if( a[i+1].tienluong <=min ) 
		{
			min= a[i+1].tienluong;
			tam = i+1;
		}
	}
	
	for(int j =0;j<n;j++)
	{
		if(a[j].tienluong==a[tam].tienluong){
				cout<<a[j].ho<< a[j].ten<<endl;
				g<<a[j].ho<< a[j].ten<<endl;
		}
		
	}	
}
void sapxepds(nhanvien a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
			for(int j= i+1;j<n;j++)
			{	
				if(a[i].ten.compare(a[j].ten)>0)
				{
					swap(a[i],a[j]);
				}
				else if (a[i].ten.compare(a[j].ten)==0)
				{
					if(a[i].ho.compare(a[j].ho)>0)
					{
						swap(a[i],a[j]);
					}
				}
				
			}
		
				
	}
}

void tomau(char *a,int color)
{
	TextColor(color);
	cout<< a;
	TextColor(7);
	
}

void menu(nhanvien a[], int n)
{
	int tam;
	do{
		cout<<"\t\t\t>>>>MENU<<<<<"<<endl;
		cout<<"1.nhap nhan vien"<<endl;
		cout<<"2.nhap nhan tu file"<<endl;
		cout<<"3.tim kiem nhan vien :"<<endl;
		cout<<"4.nhan vien co luong max/min"<<endl;
		cout<<"5.sap xep nhan vien"<<endl;
		cout<<"6.thoat"<<endl;
	    tomau("chon>>",5);
	cin>>tam;
	
	switch(tam)
	{
		case 1:
			
			ham_nhapnv(a,n);
			break;
		case 2:		
				tomau("2",10);
				cout<<endl;	
				nhapnv_file(a,n);
				ham_xuatnv(a,n);
			break;
		case 3:
			tomau("3",5);
			cout<<endl;	
			tim_nv(a,n);
			cout<<endl;
			break;
		case 4:
			tomau("4",9);
			cout<<"nv luong max:"<<endl;
			nv_luongmax(a,n);
			cin.sync();
			
			cout<<"nv luong min:"<<endl;
			nv_luongmin(a,n);
			cin.sync();
			break;
			
		case 5:
			sapxepds(a,n);
			ham_xuatnv(a,n);
			break;
	}
	}while(tam!=6);
	
	g.close();
	
}
int main()
{	
	int n;
	nhanvien a[50];
	menu(a,n);
	system("pause");
}
