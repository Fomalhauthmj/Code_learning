#include<iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int max,min;
		if(m>n)
		{
			max=m;
			min=n;
		}
		else
		{
			max=n;
			min=m;
		}
		int sum1=0;
		int sum2=0;
		for(int i=min;i<=max;i++)
		{
			if(i%2!=0)
			{
				sum1+=i*i*i; 
			}
			else
			{
				sum2+=i*i;
			}
		}
		cout<<sum2<<" "<<sum1<<endl;
	}
}
