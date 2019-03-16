#include <algorithm>
#include <iostream>
using namespace std;
#define N 10010
//保存所有竖直边
struct segment
{
    int low_y;
    int high_y;
    int pos_x;
    int io; //in or out
    node(int y1, int y2, int x, int f)
    {
        low_y = y1;
        high_y = y2;
        pos_x = x;
        io = f;
    }
};
segment segs[2 * N];
bool cmp(segment &s1, segment &s2) //根据pos_x排序
{
    return s1.pos_x < s2.pos_x;
}
int tree[N << 2];
//线段树 维护y轴区间
void push_up(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void build(int left, int right, int rt)
{
    if (left == right)
    {
        tree[rt] = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, rt << 1);
    build(mid + 1, right, rt << 1 | 1);
    push_up(rt);
}
int query(int start, int end, int left, int right, int rt)
{
    if (start == left && right == end)
    {
        return tree[rt];
    }
    int mid = (left + right) >> 1;
    int ans = 0;
    if (end <= mid)
        ans += query(start, end, left, mid, rt << 1);
    else if (start > mid)
        ans += query(start, end, mid + 1, right, rt << 1 | 1);
    else
    {
        ans += query(start, mid, left, mid, rt << 1);
        ans += query(mid + 1, end, mid + 1, right, rt << 1 | 1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int x1, y1, x2, y2;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            swap(y1, y2);
            swap(x1, x2);
        }
        //调整至左下-右上 或左上-右下
        segs[cnt + 1].low_y = segs[cnt].low_y = min(y1, y2);
        segs[cnt + 1].high_y = segs[cnt].high_y = max(y1, y2);
        segs[cnt].pos_x = x1;
        segs[cnt + 1].pos_x = x2;
        segs[cnt].io = 1;      //left
        segs[cnt + 1].io = -1; //right
        cnt += 2;
    }
    //排序
    sort(segs, segs + cnt, cmp);
    long long ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        //扫描线
        if ()
    }
    cout << ans << endl;
    system("pause");
}