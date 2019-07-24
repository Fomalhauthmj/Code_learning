#include<iostream>
using namespace std;
#define N 2020
#define mod 1000
long long S[N][N];
void init()
{
    //第二类 斯特林数
    for(int i=1;i<N;i++)
    {
        S[i][i]=1;
        S[i][0]=0;
        for(int j=1;j<i;j++)
        {
            S[i][j]=(S[i-1][j-1]+j*S[i-1][j]%mod)%mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    init();
    while(n--)
    {
        int num;cin>>num;
        long long ans=0;
        for(int i=1;i<=num;i++) ans=(ans+S[num][i])%mod;
        cout<<ans<<endl;
    }
}