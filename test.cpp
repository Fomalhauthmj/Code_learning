#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e5 + 50;
struct SegmentTree
{
    int lc, rc, cnt;
} tree[2 * MAXLEN * 20];
int tree_node, root[MAXLEN * 2];
int Insert(int now, int l, int r, int x)
{
    int p = ++tree_node;
    tree[p].cnt++;
    if (l == r)
        return p;
    int mid = (l + r) >> 1;
    if (x <= mid)
        tree[p].lc = Insert(tree[now].lc, l, mid, x);
    else
        tree[p].rc = Insert(tree[now].rc, mid + 1, r, x);
    return p;
}
int Ask(int p, int l, int r, int k)
{
    if (tree[p].cnt < k)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int lcnt = tree[tree[p].lc].cnt;
    if (k <= lcnt)
        return Ask(tree[p].lc, l, mid, k);
    else
        return Ask(tree[p].rc, mid + 1, r, k - lcnt);
}
int Merge(int p, int q)
{
    if (!p || !q)
        return p + q;
    int rt = ++tree_node;
    tree[rt].lc = Merge(tree[p].lc, tree[q].lc);
    tree[rt].rc = Merge(tree[p].rc, tree[q].rc);
    tree[rt].cnt = tree[tree[rt].lc].cnt + tree[tree[rt].rc].cnt;
    return rt;
}
char str[MAXLEN];
int N, Q;
struct state
{
    int len, link, next[26];
} st[MAXLEN * 2];
int sz, last;
int head[MAXLEN * 2], ver[MAXLEN * 2], nxt[MAXLEN * 2], tot;
int fa[MAXLEN * 2][20], pos[MAXLEN], val[MAXLEN * 2];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void SAM_Init()
{
    memset(st, 0, sizeof(st));
    st[0].len = 0, st[0].link = -1;
    sz = 1, last = 0;
}
void SAM_Extend(int c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next[c])
    {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[q].len == st[p].len + 1)
            st[cur].link = q;
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q)
            {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void DFS(int x)
{
    for (int i = 1; i < 20; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        fa[y][0] = x;
        DFS(y);
        root[x] = Merge(root[x], root[y]);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(head, 0, sizeof(head));
        memset(val, 0, sizeof(val));
        memset(tree, 0, sizeof(tree));
        memset(root, 0, sizeof(root));
        tree_node = 0, tot = 0;
        scanf("%d%d", &N, &Q);
        scanf("%s", str + 1);
        SAM_Init();
        for (int i = 1; i <= N; i++)
            SAM_Extend(str[i] - 'a'), pos[i] = last, val[last] = i;
        for (int i = 1; i < sz; i++)
            add(st[i].link, i);
        for (int i = 1; i < sz; i++)
            if (val[i])
                root[i] = Insert(root[i], 1, N, val[i]);
        DFS(0);
        int l, r, k;
        for (int i = 1; i <= Q; i++)
        {
            scanf("%d%d%d", &l, &r, &k);
            int v = pos[r];
            for (int j = 19; j >= 0; j--)
                if (st[fa[v][j]].len >= r - l + 1)
                    v = fa[v][j];
            int ans = Ask(root[v], 1, N, k);
            if (ans == -1)
                printf("-1\n");
            else
                printf("%d\n", ans - (r - l + 1) + 1);
        }
    }
    //system("pause");
    return 0;
}