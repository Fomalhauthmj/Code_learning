#include<iostream>
#include<cmath>
using namespace std;
struct time
{
	double h;
	double m;
	double s;
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		time p;
		cin>>p.h>>p.m>>p.s;
		if(p.h>12) p.h-=12;
		double res1=30.0*(p.h+p.m/60.0+p.s/3600);
		double res2=6.0*(p.m+p.s/60.0);
		double res=fabs(res1-res2);
		if(res>180) res=360.0-res;
		cout<<(int)res<<endl;
	}
}
