#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) continue;
		else
		{
			int a[n][2];
			for(int i=0;i<n;i++)
			{
				cin>>a[i][0]>>a[i][1];
			}
			for(int i=1;i<n;i++)
			{
				a[i][0]-=a[0][0];
				a[i][1]-=a[0][1];
			}
			double area=0;
			for(int i=1;i<n-1;i++)
			{
				double s=(a[i][0]*a[i+1][1]-a[i][1]*a[i+1][0]); 
				area+=0.5*s;
			}
			cout<<fixed<<setprecision(1)<<area<<endl;
		}
	}
}
