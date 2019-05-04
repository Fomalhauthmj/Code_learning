#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define PI 3.1415927
int main()
{
	double r;
	while(cin>>r)
	{
		double v;
		v=4*PI*r*r*r/3;
		cout<<fixed<<setprecision(3)<<v<<endl;
	}
}
