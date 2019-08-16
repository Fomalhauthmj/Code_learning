#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
const int M = 2e6 + 50;
#define ll long long
int n;
int head[N], nxt[M], edge[M], ver[M], tot, in_degree[N];
int c[N], q[N << 1];  //c[]属于哪一个基环树 q[]双端队列
ll diameter[N], d[N]; //求子树直径
ll a[N << 1], sum[N << 1];
bool vis[N];
inline void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, in_degree[y]++;
}
void BFS(int start, int color)
{
    int l = 1, r = 1;
    c[start] = color;
    q[1] = start;
    while (l <= r)
    {
        for (int i = head[q[l]]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!c[y])
            {
                c[y] = color;
                q[++r] = y;
            }
        }
        l++;
    }
}
void Topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 1)
            q.push(i); //不在环上点入队
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (in_degree[y] > 1) //无向图避免访问父节点
            {
                diameter[c[x]] = max(diameter[c[x]], d[x] + d[y] + edge[i]);
                d[y] = max(d[y], d[x] + edge[i]); // 维护直径  这里的写法与树形DP中的递归并不完全一致 顺序是自底向上
                if (--in_degree[y] == 1)
                    q.push(y);
            }
        }
    }
}
void DP(int color, int x)
{
    int pcnt = 0; //环上点的计数
    int y = x, k; //y:起点->终点
    do
    {
        a[++pcnt] = d[y];
        /*
        a[] 保存从环上各节点出发走向以该节点为根的子树（不访问环上节点）
        最远能到达的距离
        sum[i] 保存到环上第i个节点需要经过距离和
        */
        in_degree[y] = 1;
        for (k = head[y]; k; k = nxt[k])
            if (in_degree[ver[k]] > 1)
            {
                sum[pcnt + 1] = sum[pcnt] + edge[k];
                y = ver[k];
                break;
            }
    } while (k);
    if (pcnt == 2)
    {
        //两点成环
        int temp = 0;
        for (int i = head[y]; i; i = nxt[i])
            if (ver[i] == x)
                temp = max(temp, edge[i]);
        diameter[color] = max(diameter[color], d[x] + d[y] + temp);
        return;
    }
    for (int i = head[y]; i; i = nxt[i])
        if (ver[i] == x)
        {
            sum[pcnt + 1] = sum[pcnt] + edge[i];
            break;
        }
    for (int i = 1; i < pcnt; i++)
        //断环为链 复制一倍
        a[i + pcnt] = a[i], sum[i + pcnt] = sum[pcnt + 1] + sum[i];
    //单调队列优化DP
    q[1] = 1;
    int l = 1, r = 1;
    for (int i = 2; i < (pcnt << 1); i++)
    {
        while (l <= r && i - q[l] >= pcnt)
            l++;
        diameter[color] = max(diameter[color], a[i] + a[q[l]] + sum[i] - sum[q[l]]);
        while (l <= r && a[q[r]] - sum[q[r]] <= a[i] - sum[i])
            r--;
        q[++r] = i;
    }
}
int main()
{
    scanf("%d", &n);
    for (int x = 1, y, z; x <= n; x++)
    {
        scanf("%d%d", &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    int ccnt = 0;
    for (int i = 1; i <= n; i++)
        if (!c[i])
            BFS(i, ++ccnt);
    Topo();
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] > 1 && !vis[c[i]])
        {
            //i为基环树环上点 且该基环树尚未访问
            vis[c[i]] = true;
            DP(c[i], i);
            ans += diameter[c[i]]; //累加基环树的最长链
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}