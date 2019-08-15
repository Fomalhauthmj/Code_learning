#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 5e5+500;
const int M = 1e6+500;
#define ll long long
int head[N], ver[M], nxt[M], edge[M], tot = 0;
int n, m, init_pos[N];
ll dis[N][20];
int fa[N][20], k, son_of_rt[N], scnt = 0;
bool vis[N], army_on[N];
int which_son_of_rt[N];
vector<ll> son[N];
ll cur_pos[N], cur_dis[N], length_of_son_to_rt[N], target_length[N],rest_army[N];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], edge[tot] = z, head[x] = tot;
}
void BFS()
{
    k = log2(n) + 1;
    queue<int> q;
    vis[1] = true;
    for (int i = head[1]; i; i = nxt[i])
    {
        son_of_rt[++scnt] = ver[i];
        which_son_of_rt[ver[i]] = scnt;
        length_of_son_to_rt[scnt] = edge[i];
        vis[ver[i]] = true;
        q.push(ver[i]);
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!vis[y])
            {
                vis[y] = true;
                fa[y][0] = x;
                dis[y][0] = edge[i];
                q.push(y);
                for (int j = 1; j <= k; j++)
                    fa[y][j] = fa[fa[y][j - 1]][j - 1], dis[y][j] = dis[fa[y][j - 1]][j - 1] + dis[y][j - 1];
            }
        }
    }
}
bool DFS(int x)
{
    vis[x] = 1;
    if (army_on[x] && !which_son_of_rt[x])
        return true; //已被管辖
    bool flag = false;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            flag = true;
            if (!DFS(y))
                return false;
        }
    }
    return flag;
}
bool Judge(ll mid)
{
    for (int i = 1; i <= scnt; i++)
        son[i].clear();
    memset(army_on, 0, sizeof(army_on));
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    for (int i = 1; i <= m; i++)
    {
        cur_pos[i] = init_pos[i];
        cur_dis[i] = 0;
        for (int j = k; j >= 0; j--)
        {
            if (fa[cur_pos[i]][j] && cur_dis[i] + dis[cur_pos[i]][j] <= mid)
            {
                cur_dis[i] += dis[cur_pos[i]][j];
                cur_pos[i] = fa[cur_pos[i]][j]; //最多上跳至根节点的子结点
            }
        }
        army_on[cur_pos[i]] = true;
        int which = which_son_of_rt[cur_pos[i]];
        if (which)
        {
            son[which].push_back(mid - cur_dis[i]); //剩余时间
            if (son[which].size() > 1 && mid - cur_dis[i] > son[which][son[which].size() - 2])
                swap(son[which][son[which].size() - 2], son[which][son[which].size() - 1]); //剩余时间少的放在最后
        }
    }
    int p = 0, q = 0;
    for (int i = 1; i <= scnt; i++)
    {
        if (!DFS(son_of_rt[i])) //确定son_of_rt[i]为根的子树是否还有叶子节点未被管辖
        {
            //此子结点还有叶子节点未被管辖
            if (son[i].size() && son[i].back() < length_of_son_to_rt[i] * 2)
            {
                //移动力最差的军队不足以先移动到根节点再返回到此子节点
                son[i].pop_back(); //直接管辖此子节点
            }
            else
                target_length[++p] = length_of_son_to_rt[i]; //最后跨过根节点来管辖
        }
        for (int j = 0; j < son[i].size(); j++)
        {
            if (son[i][j] >= length_of_son_to_rt[i])
                rest_army[++q] = son[i][j] - length_of_son_to_rt[i];
        }
    }
    sort(target_length + 1, target_length + 1 + p);
    sort(rest_army + 1, rest_army + 1 + q);
    if (p > q)
        return false;
    for (int i = p, j = q; i; i--, j--)
        if (target_length[i] > rest_army[j])
            return false;
    return true;
}
int main()
{
    scanf("%d", &n);
    ll total_length = 0;
    for (int i = 0, x, y, z; i < n - 1; i++)
        scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z), total_length += z;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &init_pos[i]);
    BFS();
    ll left, right, mid;
    left = 0;                 //最好情况 初始所有位置已满足全部封锁 时间需要0
    right = total_length + 1; //最坏情况下 不会到达此上界
    while (left < right)
    {
        mid = (left + right) >> 1;
        //cout << "cur:" << mid << endl;
        if (Judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    if (left == total_length + 1)
        cout << -1 << endl;
    else
        cout << left << endl;
    system("pause");
    return 0;
}