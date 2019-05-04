//https://loj.ac/problem/131
#include<iostream>
using namespace std;
#define N 1000100
int n,q;
long long c[N];
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int val)
{
    while(x<=n)
    {
        c[x]+=val;
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
    //freopen("131_1.in","r",stdin);
    cin>>n>>q;
    int ai;
    int pre=0;
    //引入差分数组来解决树状数组的区间更新
    for(int i=1;i<=n;i++)
    {
        cin>>ai;
        change(i,ai-pre);
        pre=ai;
    }
    int kind;
    int l,r,x;
    for(int i=0;i<q;i++)
    {
        cin>>kind;
        if(kind&1)
        {
            //区间修改
            cin>>l>>r>>x;
            change(l,x);
            change(r+1,-x);
        }
        else
        {
            //单点查询
            cin>>x;
            cout<<getsum(x)<<endl;
        }
    }
    //system("pause");
    return 0;
}