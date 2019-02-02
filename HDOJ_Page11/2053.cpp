#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a=0;
		for(int i=1;i<=n;i++)
		{
			if(n%i==0&&a==1) 
			{
				a=0;
				continue;
			}
			if(n%i==0&&a==0) 
			{
				a=1;
				continue;
			}
		}
		cout<<a<<endl;
	}
}
