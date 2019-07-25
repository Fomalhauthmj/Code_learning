//http://codeforces.com/problemset/problem/9/D
//组合计数  二叉搜索树
#include <iostream>
#include<cstring>
using namespace std;
const int N = 36;
#define ll long long
int n, h;
ll dp[N][N];
/*
dp[0][0]=1 空树 dp[1...n][0]=0
dp[n][h] 结点数n  树高h
    assume:root=m
    left:结点数m-1
    right:结点数n-m
    dp[n][h]=sigma(dp[m-1][h-1]*dp[n-m][0...h-1]+dp[n-m][h-1]*dp[m-1][0...h-2])
*/
ll DP()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)//n
    {
        for(int j=1;j<=n;j++)//h
        {
            for(int k=1;k<=i;k++)//m
            {
                ll left_sum=0,right_sum=0;
                for(int t=0;t<=j-1;t++) left_sum+=dp[i-k][t];
                left_sum*=dp[k-1][j-1];
                for(int t=0;t<=j-2;t++) right_sum+=dp[k-1][t];
                right_sum*=dp[i-k][j-1];
                dp[i][j]+=left_sum+right_sum;
            }
        }
    }
    ll ret=0;
    for(int i=h;i<=n;i++)
        ret+=dp[n][i];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    cout<<DP()<<endl;
    //system("pause");
    return 0;
}