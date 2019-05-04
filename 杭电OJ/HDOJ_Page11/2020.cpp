#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n!=0)
		{
			int *ptr=new int [n];
			for(int i=0;i<n;i++)
			{
				cin>>ptr[i];
			}
			for(int i=0;i<n-1;i++)
			{
				for(int j=0;j<n-i-1;j++)
				{
					if(abs(ptr[j])<abs(ptr[j+1]))
					{
						int temp=ptr[j];
						ptr[j]=ptr[j+1];
						ptr[j+1]=temp;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(i==n-1) cout<<ptr[i];
				else cout<<ptr[i]<<" ";
			}
			cout<<endl;
		}
		else continue;
	}
}
