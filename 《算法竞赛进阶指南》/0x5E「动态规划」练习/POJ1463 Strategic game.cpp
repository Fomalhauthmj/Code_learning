#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1550;
int n;
int dp[N][2];
vector<int> son[N];
bool vis[N];
/*
dp[rt][0] 观察以rt为根的子树所有边且rt不放置士兵的情况下 所需最小士兵数
dp[rt][1] 观察以rt为根的子树所有边且rt放置士兵的情况下 所需最小士兵数
dp[rt][0]=Σdp[s][1]
dp[rt][1]=Σmin(dp[s][0],dp[s][1])+1
s∈son[rt]
 */
void DP(int rt)
{
    dp[rt][0] = 0;
    dp[rt][1] = 1;
    for (int i = 0; i < son[rt].size(); i++)
    {
        int s = son[rt][i];
        DP(s);
        dp[rt][0] += dp[s][1];
        dp[rt][1] += min(dp[s][0], dp[s][1]);
    }
}
int main()
{
    int id, num, s, root;
    while (scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            son[i].clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d:(%d)", &id, &num);
            for (int j = 0; j < num; j++)
                scanf("%d", &s), son[id].push_back(s), vis[s] = 1;
            //s is a son of id
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                root = i;
                break;
            }
        }
        DP(root);
        cout << min(dp[root][0], dp[root][1]) << endl;
    }
    //system("pause");
    return 0;
}