#include <bits/stdc++.h>
using namespace std;
bool matrix[2050][2050];
int n, m;
const int N = 1e4 + 50;
struct SegmentTreeNode
{
    int l, r, val;
};
struct SegmentTree
{
    SegmentTreeNode tree[N << 2];
    void PushUp(int rt)
    {
        tree[rt].val = max(tree[rt << 1].val, tree[rt << 1 | 1].val);
    }
    void Build(int rt, int l, int r)
    {
        tree[rt].l = l, tree[rt].r = r;
        if (l == r)
        {
            tree[rt].val = 0;
            return;
        }
        int mid = (l + r) >> 1;
        Build(rt << 1, l, mid), Build(rt << 1 | 1, mid + 1, r), PushUp(rt);
    }
    //单点更新
    void Update(int rt, int pos, int val)
    {
        int l = tree[rt].l, r = tree[rt].r;
        if (l == r)
        {
            tree[rt].val = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            Update(rt << 1, pos, val);
        else
            Update(rt << 1 | 1, pos, val);
        PushUp(rt);
    }
    int Query(int rt, int st, int ed, int limit)
    {
        int l = tree[rt].l, r = tree[rt].r;
        if (l == r)
            return l;
        int res = 0;
        if ()
            int mid = (l + r) >> 1;
    }
} t1, t2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            matrix[i][j] = (ch == 'X') ? 1 : 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
            {
                int len = 1;
                bool flag = true;
                while (flag)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dir[k][0] * len;
                        int ny = j + dir[k][1] * len;
                        if (!legal(nx, ny))
                            flag = false;
                    }
                    if (flag)
                        len++;
                }
                if (ans < len * 2 - 1 && judge(i, j, len))
                    ans = len * 2 - 1;
            }
        }
    }
    cout << ans << endl;
    //system("pause");
}