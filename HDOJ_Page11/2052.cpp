#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		cout<<'+';
		for(int i=1;i<=n;i++) cout<<'-';
		cout<<'+'<<endl;
		for(int i=1;i<=m;i++)
		{
			cout<<'|';
			for(int j=1;j<=n;j++) cout<<' ';
			cout<<'|'<<endl;
		}
		cout<<'+';
	    for(int i=1;i<=n;i++) cout<<'-';
		cout<<'+'<<endl;
		cout<<endl;
	}
}
