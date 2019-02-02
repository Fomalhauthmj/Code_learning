#include<iostream>
using namespace std;
bool isNarcissistic_number(int i)
{
	int sum=0;
	int num=i;
	while(i/10!=0)
	{
		int n=i%10;
		sum+=n*n*n;
		i=i/10;
	}
	sum+=i*i*i;
	if(sum==num)
	{
		return true;
	}
	return false;
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int flag=0;
		for(int i=m;i<=n;i++)
		{
			if(isNarcissistic_number(i)==true)
			{
				flag=1;
				cout<<i;
				for(int j=i+1;j<=n;j++)
				{
					if(isNarcissistic_number(j)==true) 
					{
						cout<<" ";
						break;
					}
					else continue;
				}
			}
			else continue;
		}
		if(flag==0) cout<<"no"<<endl;
		else cout<<endl;
	}
}
