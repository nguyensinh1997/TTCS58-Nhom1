#include<stdio.h>
#include <windows.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include"console.h"
#include<fstream>
using namespace std;

ofstream h("output.txt");
int p,n;
int a[100];
void nhapfile()
{
	ifstream f("C:\\Users\\anhng\\Desktop\\BODE1\\cau4\\input.txt");
	string s;
	getline(f,s);
	n= atof(s.c_str());
	getline(f,s);
	p= atof(s.c_str());
	for(int i=0;i<n;i++)
	{
		getline(f,s);
		a[i]= atof(s.c_str());
	}
	f.close();
}
int b[100];
int tong=0;

void in()
{
	int s=0,tt=0;
	int j;
	for(j=0;j<n;j++)
	
	if(b[j]==1)	s=s+a[j];
	
		if(s==p)
		{
			for(j=0;j<n;j++)
			{
				if(b[j]==1)	{	
					TextColor(5);
					cout<< 1;
					h<<1;
					TextColor(7);
					}
				else
					{
					
					cout<<0;
					h<<0;
				}
			}
			cout<<endl;
			h<<endl;
			tt = p; 
		}
		h.close();

	}
	
void demo(int i)
{

	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(b[j]==1) 
		
	tong = tong +a[i];
		if( (i<n-1) &&( tong < p) )
			demo(i+1);
			else
			in();
			if(b[i]==1) tong = tong -a[i];
			b[i]=0;
		
}
}

int main()
{
	
//	cout<<"4,2,2,5,10,10"<<endl;
//	cout<<"nhap P"<<endl;
//	scanf("%d",&p);
	
	nhapfile();
	demo(0);
	return 0;
}
