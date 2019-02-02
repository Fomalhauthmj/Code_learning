#include<iostream>
using namespace std;
struct object
{
	int start;
	int end;
};
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) continue;
		else
		{
			object *a=new object[n];
			for(int i=0;i<n;i++) cin>>a[i].start>>a[i].end;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-i-1;j++)
				{
					if(a[j].end>a[j+1].end)
					{
						object temp;
						temp=a[j];
						a[j]=a[j+1];
						a[j+1]=temp;
					}
				}
			}
			int maxnum=1;
			int end=a[0].end;
			for(int i=1;i<n;i++)
			{
				if(a[i].start>=end)
				{
					end=a[i].end;
					maxnum++;
				}
				else continue;
			}
			cout<<maxnum<<endl;
		}
	}
}
