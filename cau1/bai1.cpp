#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
ifstream h("C:\\Users\\anhng\\Desktop\\BODE1\\cau1\\cosan.txt");

ofstream g("output1.txt");
void nhap(string &str){
	ofstream f("input1.txt");
	cout<<"nhap mot chuoi :";
	cin.sync();
	getline(cin,str);
	f<<str;
	f.close();
}
// xoa khoang trang
string xkt(string str){
	int i=0;
	int n = str.size();
	for(int i=0;i<n-1;i++)
		{
			while((str[i]==32) && (str[i+1]==32))
				{
				
					for(int j= i ;j<n-1;j++)
					{
						str[j]=str[j+1];
						
					}
					str.erase(str.begin() + (str.size()-1));	
				}
		}
	
	if((str[0]==32)){
		 str.erase(str.begin() ); 
		}
	
	if((str[str.size()-1]==32)){
		str.erase(str.size()-1); 	
	}
	
		return str;
}
// chuan hoa chuoi
string Chuanhoa(string str){
	int i=0;
	int n= str.size();
	for(i=0;i<n;i++)
	{
		if(i==0){
			if( str[i]<='z'&& str[i]>='a')
					str[i]= str[i]-32;	
			}
		else
			if (str[i]==32)
				{
				if( str[i+1]<='z'&& str[i+1]>='a')
					str[i+1]= str[i+1]-32;
				}
			else
				if( str[i+1]<='Z'&& str[i+1]>='A')
					str[i+1]= str[i+1]+32;
				
	}
	return str;
	
}
	
//thong ke cac chu cai
void thongke(string s)
{
	int dem = 0;
    int count[122] = {0};
    int n=s.size();
    for(int i=0;i<n;i++){
    	if(!count[s[i]]){
		    count[s[i]]=1;
		    for(int j=i+1;j<n;j++)
			if(s[j]==s[i])
			    count[s[i]]++;
	    	}
	}
    for(int i=65;i<122;i++)
        if(count[i]){
            cout<<char(i)<<" "<<count[i]<<endl;
			g<<char(i)<<" "<<count[i]<<endl;
    		}
}
void menu(string &str)
{
	int tam;
	do{
		cout<<"1.nhap chuoi: "<<endl;
		cout<<"5. nhap chuoi co san: "<<endl;
		cout<<"2.xoa khoang trang:"<<endl;
		cout<<"3.chuan hoa chuoi:"<<endl;
		cout<<"4.thong ke so luong cac ky tu:"<<endl;
		cout<<"6.Endl"<<endl ;
		cout<<"chon >>" ;
		cin.sync();
		cin>>tam;
		
		switch(tam)
		{
			case 1:
				nhap(str);
					cin.sync();
					break;
			case 2:
				g<<"xoa khoang trang"<<endl;
				
				cout<< xkt(str);
				g<<xkt(str)<<endl;
					cout<<endl;
					break;
			case 3:
					g<<"chuan hoa chuoi"<<endl;
					cout<< Chuanhoa(str);
					g<<Chuanhoa(str)<<endl;
						cout<<endl;
					break;
			
			case 4:
				g<<"thong ke ky tu"<<endl;
				thongke(str);
				break;
				case 5:
					if(h!=NULL) getline(h,str);
						cout<<endl<<str<<endl;
					break;
				
		}
	
	}while(tam!=6);
		h.close();
		g.close();
}

int main()
{
	string str;
	menu(str);
	system("pause");
}
 
