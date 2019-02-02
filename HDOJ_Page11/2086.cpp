#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double a0;
        double an1;
        scanf("%lf%lf",&a0,&an1);
        double c[n+1]={0};
        for(int i=1;i<=n;i++) scanf("%lf",&c[i]);
        double sumc=0;
        for(int i=1;i<=n;i++) sumc+=2*i*c[n-i+1];
        double res=(n*a0+an1-sumc)/(n+1);
        cout<<fixed<<setprecision(2)<<res<<endl;

    }

}
