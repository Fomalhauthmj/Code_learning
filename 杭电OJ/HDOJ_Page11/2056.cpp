#include<iostream>
#include<iomanip>
using namespace std;
struct point
{
	double x;
	double y;
};
double getlength(double x1,double x2,double x3,double x4)
{
	if(x3>=x1&&x4<=x2) return x4-x3;
	if(x3<=x1&&x4>=x2) return x2-x1;
	if(x3>=x1&&x3<=x2) return x2-x3;
	if(x4>=x1&&x4<=x2) return x4-x1;
	return 0.0;
}
int main()
{
	point p1[2];
	point p2[2];
	while(cin>>p1[0].x>>p1[0].y>>p1[1].x>>p1[1].y
	         >>p2[0].x>>p2[0].y>>p2[1].x>>p2[1].y)
	         {
	         	double area;
	         	if(p1[0].x>p1[1].x) swap(p1[0],p1[1]);
	         	if(p2[0].x>p2[1].x) swap(p2[0],p2[1]);
	         	double x=getlength(p1[0].x,p1[1].x,p2[0].x,p2[1].x);
	         	if(p1[0].y>p1[1].y) swap(p1[0],p1[1]);
	         	if(p2[0].y>p2[1].y) swap(p2[0],p2[1]);
	         	double y=getlength(p1[0].y,p1[1].y,p2[0].y,p2[1].y);
				area=x*y;
				cout<<fixed<<setprecision(2)<<area<<endl;
			 }
}
