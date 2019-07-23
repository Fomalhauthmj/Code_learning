#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e4 + 50;
int n;
int head[N], ver[N * 2], nxt[N * 2], edge[N * 2], tot;
bool vis[N];
int dis[N][2], f[N];
/*
dis[rt][0,1] 以rt为根的子树中到rt最大 次大距离
dis[rt][0]=max(dis[s][0]+edge[i],dis[rt][0])
f[s]  表示以s的父结点rt为根的子树-以s为根的子树到rt的最大距离+edge(rt,s)
即s的反向最大距离
f数组初始化0
 */
void add(int u, int v, int w)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    edge[tot] = w;
}
void Init()
{
    tot = 0;
    memset(head, 0, sizeof(head));
}
void DP(int rt)
{
    vis[rt] = 1;
    dis[rt][0] = dis[rt][1] = 0;
    for (int i = head[rt]; i; i = nxt[i])
    {
        int s = ver[i];
        if (!vis[s])
        {
            DP(s);
            int temp = dis[s][0] + edge[i];
            if (temp >= dis[rt][0])
            {
                dis[rt][1] = dis[rt][0];
                dis[rt][0] = temp;
            }
            else if (temp > dis[rt][1])
            {
                dis[rt][1] = temp;
            }
        }
    }
    //cout << "rt:" << rt << " " << dis[rt][0] << " " << dis[rt][1] << endl;
}
void DFS(int rt)
{
    vis[rt] = 1;
    for (int i = head[rt]; i; i = nxt[i])
    {
        int s = ver[i];
        if (!vis[s])
        {
            if (dis[s][0] + edge[i] == dis[rt][0])
                f[s] = max(f[rt], dis[rt][1]) + edge[i];
            else
                f[s] = max(f[rt], dis[rt][0]) + edge[i];
            DFS(s);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int con, len;
    while (cin >> n)
    {
        Init();
        for (int i = 2; i <= n; i++)
        {
            cin >> con >> len;
            add(i, con, len);
            add(con, i, len);
        }
        int root = 1;
        memset(vis, 0, sizeof(vis));
        DP(root);
        memset(vis, 0, sizeof(vis));
        DFS(root);
        for (int i = 1; i <= n; i++)
        {
            cout << max(f[i], dis[i][0]) << endl;
        }
    }
    system("pause");
    return 0;
}