#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e5 + 50;
char str[MAXLEN];
int N, Q;
struct node
{
    int l, r, k, id;
    bool operator<(const node &n)
    {
        if (l != n.l)
            return l < n.l;
        return r < n.r;
    }
} ns[MAXLEN];
int ans[MAXLEN];
// __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>::iterator it;
__gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> tr;
struct state
{
    int len, link, next[26];
    int first_pos;
    bool end;
} st[MAXLEN * 2];
int sz, last;
int head[MAXLEN * 2], ver[MAXLEN * 2], nxt[MAXLEN * 2], tot;
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
    st[cur].first_pos = st[cur].len - 1;
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
            st[clone].first_pos = st[q].first_pos;
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
void BuildLinkTree()
{
    for (int i = 1; i < sz; i++)
        add(st[i].link, i);
}
stack<int> s;
void DFS(int x, int p_len)
{
    s.push(x);
    while (!s.empty())
    {
        int now = s.top();
        s.pop();
        if (st[now].end)
            tr.insert(st[now].first_pos - p_len + 2);
        for (int i = head[now]; i; i = nxt[i])
        {
            int y = ver[i];
            s.push(y);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &N, &Q);
        scanf("%s", str + 1);
        SAM_Init();
        for (int i = 1; i <= N; i++)
            SAM_Extend(str[i] - 'a'), st[last].end = true;
        BuildLinkTree();
        for (int i = 1; i <= Q; i++)
        {
            scanf("%d%d%d", &ns[i].l, &ns[i].r, &ns[i].k);
            ns[i].id = i;
        }
        sort(ns + 1, ns + Q + 1);
        int v = 0, pos;
        ns[0].l = 0;
        tr.clear();
        for (int i = 1; i <= Q; i++)
        {
            if (ns[i].l == ns[i - 1].l)
                pos = ns[i - 1].r + 1;
            else
                pos = ns[i].l, v = 0;
            //cout << "cur:" << ns[i].l << " " << ns[i].r << " " << pos << endl;
            while (pos <= ns[i].r && st[v].next[str[pos] - 'a'])
                v = st[v].next[str[pos] - 'a'], pos++;
            tr.clear();
            DFS(v, ns[i].r - ns[i].l + 1);
            if (tr.size() < ns[i].k)
                ans[ns[i].id] = -1;
            else
                ans[ns[i].id] = *tr.find_by_order(ns[i].k - 1);
        }
        for (int i = 1; i <= Q; i++)
            printf("%d\n", ans[i]);
    }
    //system("pause");
    return 0;
}
