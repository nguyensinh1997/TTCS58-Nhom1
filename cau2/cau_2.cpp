#include<iostream>
using namespace std;
int i, j;
struct nut
{
	int gtri;
	nut *tiep;
};
typedef nut Node;
void KhoiTao(Node *&dau)
{
	dau=NULL;
}
void NhapDs(Node *&dau,int n,int m)
{
	Node *p,*q;
	int temp;
		for( i=0;i<n;i++)
		{
		cout <<"dong" <<i+1<<": ";
			
			for( j=0;j<m;j++)
				{
					cout<<"\t"<<"cot"<<j+1<<": ";
					cin >> temp;
					if(temp!=0)
						{
							p=new Node;
							p->gtri=temp;
							p->tiep=NULL;
						
					if(dau==NULL) dau=p;
						else q->tiep=p;
						q=p;
						}
				}
		}

}
void XuatDs(Node *dau)
{
	Node *p;
	p=dau;
	while(p!=NULL)
	{
		if(p->gtri!=0)
			cout << p->gtri << " ";
		p=p->tiep;
	}
}


void xuatmatran(Node *dau,int n,int m)
{
	int a[n][m];
	for( i=0;i<n;i++){
		for(j=0;j<m;j++)
		{
			
			if(a[i][j]!=NULL)
				cout<<(a+i*(n+j));
				else
					cout<<0;
		}
	cout<<endl;
		}
}

// nhan 1 so khac 0
void nhan1so(Node *dau,int n){

	while (dau != NULL)
	{
		dau->gtri= dau->gtri * n;
		dau = dau->tiep;
	}
	cout << "sau khi nhan "<<n << endl;
}

int main()
{	
	Node *a;
	int n,m;
	cout<<"nhap dong/cot: "<<endl;
	cin>>n>>m;
	KhoiTao(a);
	NhapDs(a,n,m);
	cout<<endl;
	XuatDs(a);
	xuatmatran(a,n,m);
//	cout << "\n";
//	nhan1so(a,5);
//	XuatDs(a);
	system("pause");
}
