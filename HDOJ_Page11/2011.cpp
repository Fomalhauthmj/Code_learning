#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	int m;
	while(cin>>m)
	{
		int *ptr=new int [m];
		for(int i=0;i<m;i++)
		{
			cin>>ptr[i];
		}
		for(int i=0;i<m;i++)
		{
			double sum=0;
			for(int j=0;j<ptr[i];j++)
			{
				sum+=pow(-1,j)/(j+1);
			}
			cout<<fixed<<setprecision(2)<<sum<<endl;
		}
	}
}
