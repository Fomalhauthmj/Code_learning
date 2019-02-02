#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		int sheetnum=n/4;
		sheetnum+=n%4==0?0:1;
		cout<<"Printing order for "<<n<<" pages:"<<endl;
		int p1,p2,p3,p4;
		if(n%4==0)
		{
			p1=n,p2=1,p3=2,p4=n-1;
            for(int i=1;i<=sheetnum;i++)
			{
				cout<<"Sheet "<<i<<", front: ";
				cout<<p1<<", "<<p2<<endl;
				cout<<"Sheet "<<i<<", back : ";
				cout<<p3<<", "<<p4<<endl;
				p1-=2;p2+=2;p3+=2;p4-=2;
			}
		}
		else if(n%4==1)
		{
			p1=n-1,p2=5,p3=4,p4=n;
            for(int i=1;i<=sheetnum;i++)
			{
				cout<<"Sheet "<<i<<", front: ";
				if(i==1||i==2) 
				{
					cout<<"Blank, ";
					if(i==1) cout<<1<<endl;
					else cout<<3<<endl;
				}
				else 
				{
					cout<<p1<<", "<<p2<<endl;p1-=2;p2+=2;
				}
				if(n>1)
				{
					cout<<"Sheet "<<i<<", back : ";
					if(i==1) cout<<2<<", Blank"<<endl;
					else 
					{
						cout<<p3<<", "<<p4<<endl;p3+=2;p4-=2;
					}
				}
			}
		}
		else if(n%4==2)
		{
			p1=n,p2=3,p3=4,p4=n-1;
            for(int i=1;i<=sheetnum;i++)
			{
				cout<<"Sheet "<<i<<", front: ";
				if(i==1) cout<<"Blank, "<<1<<endl;
				else 
				{
					cout<<p1<<", "<<p2<<endl;p1-=2;p2+=2;
				}
				cout<<"Sheet "<<i<<", back : ";
				if(i==1) cout<<2<<", Blank"<<endl;
				else 
				{
					cout<<p3<<", "<<p4<<endl;p3+=2;p4-=2;
				}
			}
		}
		else if(n%4==3)
		{
			p1=n-1,p2=3,p3=2,p4=n;
            for(int i=1;i<=sheetnum;i++)
			{
				cout<<"Sheet "<<i<<", front: ";
				if(i==1) cout<<"Blank, "<<1<<endl;
				else 
				{
					cout<<p1<<", "<<p2<<endl;p1-=2;p2+=2;
				}
				cout<<"Sheet "<<i<<", back : ";
			    cout<<p3<<", "<<p4<<endl;p3+=2;p4-=2;
			}
		}
	}
}