#include<bits/stdc++.h>
using namespace std;
long long n;
int q;
long long lowbit(long long x)
{
    return x&(-x);
}
long long cal(long long x) //计算移动1-x的总消耗
{
    long long ans=0;
    long long temp=1;
    for(int i=0;temp<=x;i++)
    {
        ans+=(x/temp-x/(temp<<1))*(temp);
        temp<<=1;
    }
    return ans;
}
long long getSum(long long x)
{
    long long ans=0;  //自身包含 且父节点也包含
    while(x<=n)
    {
        ans++;
        x+=lowbit(x);
    }
    return ans;
}
//对于添加数到新集合 消耗为 [i-lowbit(i)+1,i-1]+1=i-[i-lowbit(i)+1]+1=lowbit(i)
//https://www.cnblogs.com/chen9510/p/6953494.html
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>q)
    {
        int type;
        long long L,R,x;
        for(int i=1;i<=q;i++)
        {
            cin>>type;
            if(type==1)
            {
                cin>>L>>R;
                long long ans=cal(R)-cal(L-1);
                cout<<ans<<endl;
            }
            else if(type==2)
            {
                cin>>x;
                cout<<getSum(x)<<endl;
            }
        }
    }
}