#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	double p1[2];
	double p2[2];
	while(cin>>p1[0]>>p1[1]>>p2[0]>>p2[1])
	{
		cout<<fixed<<setprecision(2)<<sqrt((p1[0]-p2[0])*(p1[0]-p2[0])
		+(p1[1]-p2[1])*(p1[1]-p2[1]))<<endl;
	}
}
