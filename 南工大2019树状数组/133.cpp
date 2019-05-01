//https://loj.ac/problem/133
#include<iostream>
#include<cstring>
using namespace std;
#define N 5050
long long tree[N][N];
long long n,m;
long long lowbit(long long x)
{
    return x&(-x);
}
void change(long long x,long long y,long long val)
{
    long long init_y=y;
    //这里注意n,m的限制
    while(x<=n)
    {
        y=init_y;
        while(y<=m)
        {
            tree[x][y]+=val;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
long long getsum(long long x,long long y)
{
    long long ans=0;
    long long init_y=y;
    while(x>=1)
    {
        y=init_y;
        while(y>=1)
        {
            ans+=tree[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    //这里画图理解
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    cin>>n>>m;
    int kind;
    int x,y,k;
    int a,b,c,d;
    memset(tree,0,sizeof(tree));
    while(cin>>kind)
    {
        if(kind&1)
        {
            cin>>x>>y>>k;
            change(x,y,k);
        }
        else
        {   
            cin>>a>>b>>c>>d;
            cout<<getsum(c,d)+getsum(a-1,b-1)-getsum(a-1,d)-getsum(c,b-1)<<endl;
            //二维前缀和
        }
    }
    //system("pause");
    return 0;
}