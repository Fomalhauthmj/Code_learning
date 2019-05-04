/*
有N个房间，然后每个房间里有1把钥匙(可以是其他房间的钥匙，也可以是本房间的钥匙)，
你最初手里没有任何钥匙，要靠破门而入！
但第一个房间不能破门进去，只能靠钥匙打开，其他都可以。
给你房间数N和最多能破门的个数K(1 < N ≤ 20, 1 ≤ K < N)，
求能全部把房间打开的概率

TODO:第一类斯特林数
破门k=1次 S[n][1]=(n-1)!  构成一个环
破门k>=2次 S[n][k]-S[n-1][k-1] 第一个房间不能单独成组 要减去此种情况
*/
#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
#define N 21
long long S[N][N];
void init()
{
    S[1][1]=1;
    for(int i=2;i<=N;i++)
    {
        S[i][i]=1;S[i][0]=0;
        for(int j=1;j<i;j++)
        {
            S[i][j]=S[i-1][j-1]+(i-1)*S[i-1][j];
        }
    }
}
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    init();
    while(T--)
    {   
        cin>>n>>k;
        long long ans=0;//可行情况数
        for(int i=1;i<=k;i++)//枚举破门次数
        {
            if(i==1) ans+=S[n][1];
            else ans+=S[n][i]-S[n-1][i-1];
        }
        long long sum=S[n][1]*n;
        //cout<<"cur sum:"<<sum<<" cur ans:"<<ans<<endl;
        double ret=ans*1.0/sum;
        cout<<fixed<<setprecision(4)<<ret<<endl;
        //printf("%.4lf\n",ret);
        
    }
}