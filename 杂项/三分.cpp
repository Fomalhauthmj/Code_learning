//二分处理单调 若非单调？
//f(x)=ax^2+bx+c  P(x,y)  求P到f(x)的最短距离
#include<iostream>
#include<math.h>
using namespace std;
#define UP 1000.0
#define DOWN -1000.0
struct point
{
    double x;
    double y;
    point(double d1,double d2)
    {
        x=d1;y=d2;
    }
};
point P(0,0);
int a,b,c;
point f(double x)
{
    return point(x,a*x*x+b*x+c);
}
double dis2(point p1)
{
    return (p1.x-P.x)*(p1.x-P.x)+(p1.y-P.y)*(p1.y-P.y);
}
double trisearch(double left,double right)
{
    double lm,rm;
    while(left<=right)
    {
        lm=left+(right-left)/3;
        rm=right-(right-left)/3;
        if(dis2(f(lm))<=dis2(f(rm)))
        {
            right=rm;
        }
        else left=lm;
        if(fabs(right-left)<1e-3) break;
    }
    return dis2(f(left));
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b>>c)
    {
        cin>>P.x>>P.y;
        double axis=-b*1.0/2/a;
        double ret;
        if(P.x<axis)
        {
            ret=trisearch(DOWN,axis);
        }
        else if(P.x>=axis)
        {
            ret=trisearch(axis,UP);
        }
        cout<<sqrt(ret)<<endl;
    }
}
