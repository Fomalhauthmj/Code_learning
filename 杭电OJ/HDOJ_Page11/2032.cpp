#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[30][30]={0};
		a[0][0]=1;
		for(int i=0;i<n;i++) a[i][0]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j<i) cout<<a[i][j]<<" ";
				if(j==i) cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
