#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) continue;
		else
		{
			int *ptr=new int [n+1];
			for(int i=0;i<n;i++)
			{
				cin>>ptr[i];
			}
			ptr[n]=0;
			int insertpos=0;
			for(int i=0;i<n;i++)
			{
				if(m>ptr[i]) insertpos=i+1;
				else continue;
			} 
			if(insertpos==0)
			{
				for(int i=n;i>0;i--)
				{
					ptr[i]=ptr[i-1];
				}
				ptr[0]=m;
			}
			if(insertpos==n)
			{
				ptr[n]=m;
			}
			if(insertpos>0&&insertpos<n)
			{
				for(int i=n;i>insertpos;i--)
				{
					ptr[i]=ptr[i-1];
				}
				ptr[insertpos]=m;
			}
			for(int i=0;i<n+1;i++)
			{
				if(i==n) cout<<ptr[i];
				else cout<<ptr[i]<<" ";
			}
			cout<<endl;
		} 
	}
}
