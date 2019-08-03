#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1E5 + 20;
#define pii pair<int, int>
int n, m, val[N], cnt;
vector<int> v[N];
int fa[N], lca[N], vis[N], pre[N];
vector<pii> q[N];
int X[N], Y[N], Z[N];
int Find(int x)
{
  if (x == fa[x])
    return x;
  return fa[x] = Find(fa[x]);
}
void Tarjan(int x)
{
  vis[x] = 1;
  for (auto y : v[x])
  {
    if (!vis[y])
    {
      Tarjan(y);
      fa[y] = x;
      pre[y] = x;
    }
  }
  for (auto it : q[x])
  {
    int y = it.first, id = it.second;
    if (vis[y] == 2)
      lca[id] = Find(y);
  }
  vis[x] = 2;
}
struct SegmentTree
{
  int left, right, dat, pos;
  //区间最大值及最大值位置
} tree[N * 20*4];
int tree_num, root[N], ans[N];
void PushUp(int rt)
{
  int l = tree[rt].left, r = tree[rt].right;
  tree[rt].dat = max(tree[l].dat, tree[r].dat);
  tree[rt].pos = tree[l].dat >= tree[r].dat ? tree[l].pos : tree[r].pos;
}
void Insert(int rt, int l, int r, int val, int delta)
{
  if (l == r)
  {
    tree[rt].dat += delta;
    tree[rt].pos = tree[rt].dat ? l : 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (val <= mid)
  {
    if (!tree[rt].left)
      tree[rt].left = ++tree_num;
    Insert(tree[rt].left, l, mid, val, delta);
  }
  else
  {
    if (!tree[rt].right)
      tree[rt].right = ++tree_num;
    Insert(tree[rt].right, mid + 1, r, val, delta);
  }
  PushUp(rt);
}
int Merge(int p, int q, int l, int r)
{
  if (!p)
    return q;
  if (!q)
    return p;
  if (l == r)
  {
    tree[p].dat += tree[q].dat;
    tree[p].pos = tree[p].dat ? l : 0;
    return p;
  }
  int mid = (l + r) >> 1;
  tree[p].left = Merge(tree[p].left, tree[q].left, l, mid);
  tree[p].right = Merge(tree[p].right, tree[q].right, mid + 1, r);
  PushUp(p);
  return p;
}
void DFS_calc(int x)
{
  vis[x] = 1;
  for (auto y : v[x])
  {
    if (!vis[y])
    {
      DFS_calc(y);
      root[x] = Merge(root[x], root[y], 1, cnt);
    }
  }
  ans[x] = tree[root[x]].pos;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= m; i++)
  {
    cin >> X[i] >> Y[i] >> Z[i];
    val[i] = Z[i];
    if (X[i] == Y[i])
      lca[i] = X[i];
    else
    {
      q[X[i]].push_back({Y[i], i});
      q[Y[i]].push_back({X[i], i});
    }
  }
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  memset(vis, 0, sizeof(vis));
  Tarjan(1);
  sort(val + 1, val + 1 + m);
  cnt = unique(val + 1, val + 1 + m) - (val + 1);
  tree_num = 0;
  for (int i = 1; i <= n; i++)
    root[i] = ++tree_num;
  for (int i = 1; i <= m; i++)
  {
    int x = X[i], y = Y[i];
    int z = lower_bound(val + 1, val + 1 + cnt, Z[i]) - val;
    Insert(root[x], 1, cnt, z, 1);
    Insert(root[y], 1, cnt, z, 1);
    Insert(root[lca[i]], 1, cnt, z, -1);
    if (pre[lca[i]])
      Insert(root[pre[lca[i]]], 1, cnt, z, -1);
  }
  memset(vis, 0, sizeof(vis));
  DFS_calc(1);
  for (int i = 1; i <= n; i++)
    cout << val[ans[i]] << endl;
  //system("pause");
  return 0;
}