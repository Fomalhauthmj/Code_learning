#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e4 + 50;
const int M = 5e3 + 50;
int n, h;
struct node
{
    int b, e, t;
    node(int bb, int ee, int tt) : b(bb), e(ee), t(tt) {}
    bool operator<(const node &n) const
    {
        if (e != n.e)
            return e < n.e;
        return b < n.b;
    }
};
vector<node> v;
int c[N << 2];
//树状数组 单点更新 区间查询
int fa[N];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
int lowbit(int x)
{
    return x & (-x);
}
void change(int x, int val)
{
    while (x <= n)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
int getsum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    int b, e, t;
    for (int i = 0; i < h; i++)
    {
        cin >> b >> e >> t;
        v.push_back(node(b, e, t));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (auto ele : v)
    {
        //cout << ele.b << " " << ele.e << endl;
        /*
        int has = 0;
        for (int i = ele.b; i <= ele.e; i++)
        {
            if (tree[i])
                has++;
        }
        */
        ele.t -= (getsum(ele.e) - getsum(ele.b - 1));
        //已有数量
        for (int i = Find(ele.e); ele.t > 0; i = Find(i))
        {
            change(i, 1); //单点更新
            fa[i] = Find(i - 1);
            //Find(i) 返回最左的无树块 包括本身
            ele.t--;
        }
    }
    //树状数组维护 区间查询
    cout << getsum(n) << endl;
    //system("pause");
    return 0;
}