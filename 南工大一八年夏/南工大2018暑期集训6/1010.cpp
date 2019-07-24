//最大值最小化  F(x) = max(Si(x)), i = 1...n. The domain of x is [0, 1000]  ->min F(x)
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define size 10010
int n;
int a[size],b[size],c[size];
double value(double x,int a,int b,int c)
{
    return a*x*x+b*x+c;
}
double f(double mid)
{
    double tempmax=value(mid,a[0],b[0],c[0]);
    for(int i=1;i<n;i++)
    {
        tempmax=max(tempmax,value(mid,a[i],b[i],c[i]));
    }
    return tempmax;
}
double trisearch(double left,double right)
{
    double lm,rm;
    while(left<right) //或者固定循环次数
    {
        if(fabs(left-right)<1e-10) break;
        lm=left+(right-left)/3;
        rm=right-(right-left)/3;
        if(f(lm)<f(rm))
        {
            right=rm;
        }
        else left=lm;
    }
    return f(left);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
        double ans=trisearch(0,1000);
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }
}
