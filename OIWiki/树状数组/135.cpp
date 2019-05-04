//https://loj.ac/problem/135
//https://www.cnblogs.com/RabbitHu/p/BIT.html
#include<iostream>
#include<cstring>
using namespace std;
#define N 2050
long long t1[N][N];
long long t2[N][N];
long long t3[N][N];
long long t4[N][N];
long long n,m;
long long lowbit(long long x)
{
    return x&(-x);
}
long long getsum(long long x,long long y)
{
    long long ans=0;
    long long init_y=y;
    long long init_x=x;
    while(x>=1)
    {
        y=init_y;
        while(y>=1)
        {
            ans+=(init_x+1)*(init_y+1)*t1[x][y];
            ans-=(init_y+1)*t2[x][y];
            ans-=(init_x+1)*t3[x][y];
            ans+=t4[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    return ans;
}
void change(long long x,long long y,long long val)
{
    long long init_x=x;
    long long init_y=y;
    while(x<=n)
    {
        y=init_y;
        while(y<=m)
        {
            t1[x][y]+=val;
            t2[x][y]+=init_x*val;
            t3[x][y]+=init_y*val;
            t4[x][y]+=init_x*init_y*val;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    long long kind;
    long long a,b,c,d,x;
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    memset(t3,0,sizeof(t3));
    memset(t4,0,sizeof(t4));
    while(cin>>kind)
    {
        if(kind&1)
        {
            cin>>a>>b>>c>>d>>x;
            //区间修改
            change(c+1,d+1,x);
            change(a,b,x);
            change(a,d+1,-x);
            change(c+1,b,-x);
        }
        else
        {
            //区间查询
            cin>>a>>b>>c>>d;
            cout<<getsum(c,d)+getsum(a-1,b-1)-getsum(c,b-1)-getsum(a-1,d)<<endl;
        }
    }
    //system("pause");
    return 0;
}