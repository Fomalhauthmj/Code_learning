#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define N 12
#define MAX 100
#define ll long long
ll fac[N];//最多选出十件物品
void init()//预处理阶乘数
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=fac[i-1]*i;
        //cout<<fac[i]<<endl;
    }
}
int num[N];//每种物品的数量 最多十种
double c1[MAX];
double c2[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    init();
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>num[i];//每种物品的数量
        }
        //初始化
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        c1[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=num[i]&&j<=m;j++)//当前种数量
            {
                for(int k=0;k<=m&&k+j<=m;k++)//当前取出总数
                {
                    c2[k+j]+=c1[k]/fac[j];
                }
            }
            for(int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%.0lf\n",c1[m]*fac[m]);//这个精度更高
    }
}
//!:指数型母函数