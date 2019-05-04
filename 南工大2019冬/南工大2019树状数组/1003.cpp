#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n;//区块数
int m;//塔数
int k;//怪物数
long long c[N];
long long sum_c[N];
int lowbit(int x)
{
    return x&(-x);
}
void edit(int x,int data)
{
    while(x<=n)
    {
        c[x]+=data;
        x+=lowbit(x);
    }
}
long long getSum(int x)
{
    long long sum=0;
    while(x>=1)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void deal()
{
    sum_c[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum_c[i]=sum_c[i-1]+getSum(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0) break;
        memset(c,0,sizeof(c));
        cin>>m;
        int l,r,d;
        for(int i=1;i<=m;i++)
        {
            cin>>l>>r>>d;
            edit(l,d);
            edit(r+1,-d);    
        }//对每个塔范围内的区块伤害 区间修改 差分数组 初值为0
        //for(int i=1;i<=n;i++) cout<<getSum(i)<<" "; 获得每个区块伤害
        deal();
        //for(int i=1;i<=n;i++) cout<<sum_c[i]<<" "; 
        cin>>k;
        int ans=0;
        long long hp;
        int x;
        for(int i=1;i<=k;i++)
        {
            cin>>hp>>x;
            long long sum_damage=sum_c[n]-sum_c[x-1];
            if(sum_damage<hp) ans++;
        }
        cout<<ans<<endl;
    }
}