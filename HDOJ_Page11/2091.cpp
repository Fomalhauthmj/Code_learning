#include<iostream>
using namespace std;
int main()
{
	char ch;
	int n;
	int flag=0;
	while(cin>>ch>>n)
	{
		if(ch=='@') break; 
		if(flag) cout<<endl;
		if(n==1) cout<<ch;
		else{
		for(int i=1;i<=n;i++)
		{
			for(int j=n-i;j>0;j--) cout<<" ";
			if(i==1) cout<<ch<<endl;
			if(i>1&&i<n)
			{
				cout<<ch;
				for(int k=1;k<=2*i-3;k++) cout<<" ";
				cout<<ch<<endl;
			}
			if(i==n) for(int l=1;l<=2*n-1;l++) cout<<ch;
		}
	}
		cout<<endl;
		flag=1;
	}
}
