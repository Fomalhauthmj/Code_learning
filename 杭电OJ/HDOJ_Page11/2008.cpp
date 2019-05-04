#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		{
			continue;
		}
		else
		{
			float *ptr=new float[n];
			for(int i=0;i<n;i++)
			{
				cin>>ptr[i];
			}
			int a=0;
			int b=0;
			int c=0;
			for(int i=0;i<n;i++)
			{
				if(ptr[i]>0)
				{
					c++;
					continue;
				}
				if(ptr[i]<0)
				{
					a++;
					continue;
				}
				if(ptr[i]==0)
				{
					b++;
					continue;
				}
			}
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
}
