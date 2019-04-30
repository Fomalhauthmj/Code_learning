//https://loj.ac/problem/130
#include<bits/stdc++.h>
using namespace std;
#define N 1000100
long long c[N];
int n,q;
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
long long getsum(int x)
{
    long long ans=0;
    while(x>=1)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    int ai;
    for(int i=1;i<=n;i++)
    {
        cin>>ai;
        change(i,ai);
    }
    int x,y,z;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            change(y,z);
        }
        else
        {
            cout<<getsum(z)-getsum(y-1)<<endl;
        }
    }
    return 0;
}