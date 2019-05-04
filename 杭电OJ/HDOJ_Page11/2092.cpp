#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		else
		{
			if(m==0) cout<<"Yes"<<endl;
			else
			{
				int flag=0;
				int max=sqrt(abs(m));
				int min=-max;
				for(int i=min;i<=max;i++)
				{
					if(i==0) continue;
					if(m%i==0&&(m/i+i)==n)
					{
						flag=1;
						break;
					}
				}
				if(flag==1) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}	
	}
	
} 
