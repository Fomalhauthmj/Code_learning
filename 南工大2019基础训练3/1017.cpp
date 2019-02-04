#include<iostream>
#include<cstring>
using namespace std;
#define N 105
double dp[N][N]; //dp[i][j]表示i根绳子 j个绳圈的概率
/*
假设n-1根绳子配对完毕共有f(n - 1)种情，那么在此基础上加一根绳子，重新进行配对，有以下两种情况可以选择：
（1）绳圈个数不变，在n - 1根已配对完毕的绳头中选择一个绳头和当前新添加的一根绳子绳头打结连接起来；
（2）增加一个绳圈，直接让新添加的绳子两个绳头直接相连。
f(n)=f(n-1)*(C[2n-2][1]+1)=f(n-1)*(2n-2+1)=f(n-1)*(2n-1)
*/
//TODO:因为所有绳子都要两两配对 到最后不存在有绳子的绳头未打结所以也不存在新添的绳子两端分别连接空绳头成圈的情况
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;//初始化
    for(int i=2;i<=100;i++)
    {
        for(int j=1;j<=i;j++)//最多形成i个绳圈 最少形成一个绳圈
        {
            dp[i][j]=dp[i-1][j]*(2*i-2)/(2*i-1)+dp[i-1][j-1]/(2*i-1);
        }
    }
    double maxp=0;
    for(int i=1;i<=100;i++)
    {
        cout<<dp[100][i]<<" "<<i<<endl;
        if(dp[100][i]>maxp)
        {
            maxp=dp[100][i];
            cout<<i<<" "<<maxp<<endl;
        }
    }//3
    system("pause");
}