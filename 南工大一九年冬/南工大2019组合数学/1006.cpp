//求给定范围内次方数的数量 次方>=2
#include<iostream>
#include<math.h>
using namespace std;
long long n;
long long ans;
int prime[17]={2,3,5,7,11,
            13,17,19,23,29,
            31,37,41,43,47,
            53,59};
//2^60>1e18 最大次方数为60 以上为1-60内的素数
//2*3*5=30 2*3*7=42 2*3*11=66 3*5*7>60
void DFS(int cur,int pri,int cnt)
{
    long long temp=pow(n,1.0/pri);//计算得到以pri为k的数量
    if(pri>60) return;
    if(temp>1)
    {
        //cout<<"cur temp:"<<temp<<endl;
        if(cnt&1)   ans+=temp-1;//减去1
        else ans-=temp-1;//减去1
    }
    for(int i=cur+1;i<17;i++)
        DFS(i,prime[i]*pri,cnt+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        ans=1;//加上1
        for(int i=0;i<17;i++)
        {
            DFS(i,prime[i],1);
        }
        cout<<ans<<endl;
    }
}