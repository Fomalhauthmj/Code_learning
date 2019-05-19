#include <cstring>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
#define N 105
//!: 贪心
//因为每次加油价格都随城市序号增加 理想方案是每到一个城市看剩余距离当前油能不能跑完 不能就加到能跑完
void DP(int n, int v) //动态规划怎么做？
{
    int dp[N][N];
    int dis;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
            dp[i][j] = inf;
    }
    for (int i = 0; i <= v; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 1; i < n; i++) //当前城市
    {
        for (int j = 0; j <= v; j++)
        {
            //判断加多少油
            dis = n - i;
            if (dis >= v) //加满
            {
                dp[i + 1][v - 1] = min(dp[i + 1][v - 1], dp[i][j] + (v - j) * i);
            }
            else
            {
                dp[i + 1][dis - 1] = min(dp[i + 1][dis - 1], dp[i][j] + (dis - j) * i);
            }
        }
    }
    cout << dp[n][0] << endl; //最佳输出到达n城市时剩余0油量
}
void Greedy(int n, int v)
{
    int dis = n - 1; //剩余距离
    int cur = 0;     //当前油量
    int money = 0;   //消费
    for (int i = 1; i <= n; i++)
    {
        if (dis >= v)
        {
            money += (v - cur) * i; //需要加满
            dis--;
            cur = v - 1;
        }
        else if (dis < v)
        {
            money += (dis - cur) * i; //不必加满
            break;
        }
    }
    cout << money << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v;
    while (cin >> n >> v)
    {
        //Greedy(n, v);
        DP(n, v);
    }
}