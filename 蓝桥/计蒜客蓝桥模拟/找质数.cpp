#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define N 1000100
int prime[N];
bool check[N];
int tot;
void gPrime()
{
    memset(check,0,sizeof(check));
    tot=0;
    for(int i=2;i<N;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
        }
        for(int j=0;j<tot;j++)
        {
            if(prime[j]*i>=N) break;
            check[prime[j]*i]=1;
            if(i%prime[j]==0) break; //最小质因子筛
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gPrime();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<tot;i++)
        {
            if(!check[n-prime[i]])
            {
                //cout<<prime[i]<<" "<<n-prime[i]<<endl;
                printf("%d %d\n",prime[i],n-prime[i]); //TODO:注意计蒜客使用上一种输出超时
                break;
            }
        }
    }
}