#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,q;
long long a[N];
long long c1[N];
long long c2[N];
long long lowbit(long long x)
{
    return x&(-x);
}
long long getSum(int x,long long c[])
{
    long long sum=0;
    while(x>=1)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void edit(int x,long long val,long long c[])
{
    while(x<=n)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>q)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            edit(i,a[i],c1);
            edit(i,i*a[i],c2);
        }
        int x,l,r;
        long long ans;
        for(int i=1;i<=q;i++)
        {
            cin>>x>>l>>r;
            if(x==1)
            {
                //查询y-z范围内值
                ans=(r+1)*(getSum(r,c1)-getSum(l-1,c1))-(getSum(r,c2)-getSum(l-1,c2));
                cout<<ans<<endl;
            }
            else if(x==2)
            {
                //单点修改
                edit(l,-a[l]+r,c1);
                edit(l,l*(r-a[l]),c2);
                a[l]=r;//!:注意这里的修改
            }
        }
    }
}