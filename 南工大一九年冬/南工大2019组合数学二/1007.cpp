#include<iostream>
using namespace std;
#define mod 1000000007
#define N 1010
int n,r,k,m;
//n为机器总数 r为选取机器数 k为编号至少相差数  m为等价类数
//从n中选出r个编号相隔至少为k的方案数*第二类斯特林数划分为m个等价类方案数
//1 2 .... k  k+1  1-k+1 至少要空开k-1个  A=n-(r-1)(k-1)-r=n-(r-1)*k-1  剩余空位B=r+1   
//将A个球放入B组 可以为空 隔板法  分成B组需要B-1个隔板 允许为空==C[A+B-1][B-1]=C[A+r][r] 
long long S[N][N];
void init_S()
{
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
long long C[2*N][2*N];
void init_C()
{
    C[0][0]=1;
    for(int i=1;i<2*N;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_C();
    init_S();
    while(cin>>n>>r>>k>>m)
    {
        long long ans_1=0;
        for(int i=1;i<=min(r,m);i++)
        {
            ans_1=(ans_1+S[r][i])%mod;
        }
        int temp=n-(r-1)*k-1;
        if(temp<0)
        {
            cout<<0<<endl;
            continue;
        }
        long long ans_2=C[temp+r][r];
        cout<<(ans_1*ans_2)%mod<<endl;
    }
}