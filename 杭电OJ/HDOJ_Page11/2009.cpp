#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		double sum=0;
		double num=n;
		for(int i=0;i<m;i++)
		{
			sum+=num;
			num=sqrt(num);
		}
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
}
