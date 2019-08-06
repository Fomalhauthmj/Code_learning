#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 50;
const int M = 5e5 + 50;
#define ll long long
int head[N], ver[M << 1], nxt[M << 1], tot = 0;
int n, m;
ll ans[N];
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int dfn[N], low[N], root, num = 0;
ll sze[N];
bool cut[N];
void Tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    sze[x]=1;
    int flag = 0;
    ll sum=0;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            Tarjan(y);
            sze[x]+=sze[y];
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x])
            {
                flag++;
                sum+=sze[y];
                ans[x]+=sze[y]*(n-sze[y]);
                if (x != root || flag >= 2)
                    cut[x] = true;
            }
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
    if(cut[x]) ans[x]+=n-1+(n-sum-1)*(1+sum);
    else ans[x]=2*(n-1);
}
int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++)
        scanf("%d%d",&u,&v), add(u, v),add(v,u);
    root = 1;
    Tarjan(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    system("pause");
    return 0;
}