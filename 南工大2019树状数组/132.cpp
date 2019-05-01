//https://loj.ac/problem/132
#include<iostream>
using namespace std;
#define N 1000100
long long n,q;
long long c1[N];
long long c2[N];
long long lowbit(long long x)
{
    return x&(-x);
}
long long getsum(long long *c,long long x)
{
    long long ans=0;
    while(x>=1)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void change(long long *c,long long x,long long val)
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
    cin.tie(0);
    cin>>n>>q;
    long long ai;
    long long pre=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ai;
        change(c1,i,ai-pre);
        change(c2,i,i*(ai-pre));
        //为什么这么写？ 你需要写以下前缀和的表达式
        pre=ai;
        //建立差分数组->区间更新
    }
    long long kind;
    long long l,r,x;
    for(int i=0;i<q;i++)
    {
        cin>>kind;
        if(kind&1)
        {
            cin>>l>>r>>x;
            change(c1,l,x);
            change(c2,l,l*x);
            change(c1,r+1,-x);
            change(c2,r+1,-(r+1)*x);
        }
        else
        {
            //区间查询
            cin>>l>>r;
            long long temp1=l*getsum(c1,l-1)-getsum(c2,l-1);
            long long temp2=(r+1)*getsum(c1,r)-getsum(c2,r);
            cout<<temp2-temp1<<endl;
        }
    }
    //system("pause");
}