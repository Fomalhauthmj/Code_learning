//!:区间DP
#include<iostream>
#include<cstring>
using namespace std;
#define N 110
#define mod 1000000007
#define inf 0x3f3f3f3f
int n;
long long dp[N][N];//dp[i][j] 坐满[i,j]范围内的椅子方案数
bool c[N];//颜色  0:blue  1:red
long long a[N][N]; //!:用二维数组来表示状态 而非简单的一维数组
/*
He won’t sit on the chair if the chair is satisfied the following three conditions.//满足下列所有三个条件则不坐这个椅子
1.The chair has both left and right adjacent chairs.//当前椅子有左右相邻椅子，即非首尾椅子
2.The left and right adjacent chairs are not empty.//左右相邻椅子有人坐了
3.The left and right adjacent chairs’ color are different.//左右相邻椅子的颜色不同
*/
/*
1 0 0  : 4    all: 123 132(x) 213 231(x) 312 321
1 0 0 1: 8    all：1234 2134 3124 3214 4123 4213 4312 4321
*/
void init_a(int n)
{
    memset(a,0,sizeof(a));
    a[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        a[i][0]=1;//!:初始化
        //C(n,0)=1 C(n,n)=1 C(0,0)=1
        for(int j=1;j<=i;j++)
        {
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%mod;//组合数公式
            //C(n,m)=C(n,n-m)=C(n-1,m-1)+C(n-1,m)
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>c[i];
        //如何初始化？
        init_a(n);
        memset(dp,0,sizeof(dp));//方案初始为0
        for(int i=1;i<=n;i++) 
        {
            dp[i][i]=1; //对于只有一个椅子 方案数为1 只能坐一个人
        }
        for(int r=1;r<=n;r++)
        {
            for(int i=1;i<=n-r;i++)
            {
                int j=i+r;
                for(int k=i;k<=j;k++)//枚举最后坐的椅子
                {
                    if(k==i) dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;//首尾情况
                    else if(k==j) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                    else 
                    {
                        if(c[k-1]==c[k+1]) dp[i][j]=(dp[i][j]+dp[i][k-1]*dp[k+1][j]%mod*a[r][k-i]%mod)%mod;
                        //a[r][k-i] 长度为r 已放好k-i个元素
                    }
                }
            }
        }
        cout<<dp[1][n]%mod<<endl;
    }
}