#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
const int N = 205;
#define ll long long
#define inf 0x3f3f3f3f
int n, m, tot;
map<string, int> name;
vector<int> son[N];
ll dia[N];
ll dp[N][N];
char str[N];
bool vis[N];
/*
    dp[i][j] 以i为根的子树中已经获取j个国家的支持的 最少花费
*/
int DP(int rt)
{
    int node_cnt=1;
    for(int i=1;i<=n;i++) dp[rt][i]=inf;
    dp[rt][0]=0;
    for (int i = 0; i < son[rt].size(); i++) //分组
    {
        int s = son[rt][i];
        node_cnt+=DP(s);
        for (int j = n; j >= 0; j--) //已获得支持j
        {
            for (int k = 0; k <= j; k++) //子树中获得支持k
            {
                if (j >= k)
                    dp[rt][j] = min(dp[rt][j], dp[rt][j - k] + dp[s][k]);
            }
        }
    }
    dp[rt][node_cnt]=min(dp[rt][node_cnt],dia[rt]);
    //比较
    return node_cnt;
}
int main()
{
    while (fgets(str, sizeof(str), stdin) && str[0] != '#')
    {
        sscanf(str, "%d%d", &n, &m);
        tot = 0;
        name.clear();
        for (int i = 0; i <= n; i++)
            son[i].clear();
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            int diamond;
            scanf("%s %d", str, &diamond);
            if (!name.count(str))
                name[str] = ++tot;
            int fa=name[str];
            dia[fa] = diamond;
            fgets(str, sizeof(str), stdin);
            stringstream ss(str);
            string temp;
            while (ss >> temp)
            {
                if (!name.count(temp))
                    name[temp] = ++tot;
                int s=name[temp];
                vis[s] = 1;
                son[fa].push_back(s);
            }
        }
        for(int i=1;i<=n;i++) if(!vis[i]) son[0].push_back(i);
        dia[0]=inf;
        //输入数据可能为森林 增加虚根 
        DP(0);
        ll ans=inf;
        for(int i=m;i<=n;i++) ans=min(ans,dp[0][i]);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}