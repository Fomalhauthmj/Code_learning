#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int row=n/m;
		for(int i=0;i<row;i++)
		{
			int sum=0;
			for(int j=1;j<=m;j++)
			{
				sum+=(i*m+j)*2;
			}
			if(i==0) cout<<sum/m;
			else cout<<" "<<sum/m;
		}
		if(n%m!=0)
		{
		    int lastsum=0;
		    for(int i=1;i<=n%m;i++)
		    {
			    lastsum+=(row*m+i)*2;
		    }
		    cout<<" "<<lastsum/(n%m);
	    }
	    cout<<endl;
	}
}
