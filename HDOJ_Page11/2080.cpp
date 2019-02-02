#include<iostream>
#include<iomanip>
#include<math.h>
#define PI 3.141592654 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		double res1;
		double res2;
		res1=atan2(x1,y1)*180/PI;
		res2=atan2(x2,y2)*180/PI;
		if(res1<0) res1=360.0+res1;
		if(res2<0) res2=360.0+res2;
		double result=min(fabs(res1-res2),360.0-fabs(res1-res2));
		cout<<fixed<<setprecision(2)<<result<<endl;
	}
}
