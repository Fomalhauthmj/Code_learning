	#include<iostream>
	using namespace std;
	int main()
	{
		int n;
		while(cin>>n)
		{
			if(n==0) continue;
			else
			{	
			int *ptr=new int[n];
			for(int i=0;i<n;i++)
			{
				cin>>ptr[i];
			}
			int minpos=0;
			for(int i=0;i<n;i++)
			{
				if(ptr[i]<ptr[minpos])
				{
					minpos=i;
				}
				else continue;
			}
			int temp=ptr[0];
			ptr[0]=ptr[minpos];
			ptr[minpos]=temp;
			for(int i=0;i<n;i++)
			{
				if(i==n-1)
				{
					cout<<ptr[i];
				}
				else
				{
					cout<<ptr[i]<<" ";
				}
			}
			cout<<endl;
		}
		}
	}
