/*
//83%
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 10010
//以横坐标作为线段(区间),对横坐标线段进行扫描
//扫描的作用是每次更新下底边总长度和下底边个数,增加新面积
struct seg
{ //线段
    int l, r, h;
    int d;
    seg() {}
    seg(int x1, int x2, int H, int c) : l(x1), r(x2), h(H), d(c) {}
    bool operator<(const seg &a) const
    {
        return h < a.h;
    }
};
seg s[MAX * 2];
struct node
{
    int cnt;
    int sum;
    node()
    {
        cnt = 0;
        sum = 0;
    }
};
node tree[MAX << 2];
int Hash[MAX * 2];
void push_up(int rt, int left, int right)
{
    if (tree[rt].cnt)
        tree[rt].sum = Hash[right + 1] - Hash[left]; //表示该区间整个线段长度可以作为底边
    else if (left == right)
        tree[rt].sum = 0; //叶子结点则底边长度为0(区间内线段长度为0)
    else
        tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void Update(int L, int R, int d, int rt, int left, int right)
{
    if (L <= left && right <= R)
    {                             //该区间是当前扫描线段的一部分,则该区间直接更新
        tree[rt].cnt += d;        //更新标记值
        push_up(rt, left, right); //更新覆盖长度
        return;
    }
    int mid = (left + right) >> 1;
    if (L <= mid)
        Update(L, R, d, rt << 1, left, mid);
    if (R > mid)
        Update(L, R, d, rt << 1 | 1, mid + 1, right);
    push_up(rt, left, right);
}

int search(int key, int *x, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (x[mid] == key)
            return mid;
        if (x[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int x1, x2, y1, y2;
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        Hash[k] = x1;
        s[k++] = seg(x1, x2, y1, 1);
        Hash[k] = x2;
        s[k++] = seg(x1, x2, y2, -1);
    }
    sort(Hash, Hash + k);
    sort(s, s + k);
    int m = 1;
    for (int i = 1; i < k; ++i) //去重复端点 已先排序
        if (Hash[i] != Hash[i - 1])
            Hash[m++] = Hash[i];
    int ans = 0;
    for (int i = 0; i < k; ++i)
    { //扫描线段
        int L = search(s[i].l, Hash, m);
        int R = search(s[i].r, Hash, m) - 1;
        Update(L, R, s[i].d, 1, 0, m - 1);          //扫描线段时更新标记值
        ans += tree[1].sum * (s[i + 1].h - s[i].h); //新增加面积
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

/*
这里注意下扫描线段时r-1:int R=search(s[i].l,Hash,m)-1;
计算底边长时r+1:if(mark[n])sum[n]=Hash[right+1]-Hash[left];
解释:假设现在有一个线段左端点是l=0,右端点是r=m-1
则我们去更新的时候,会算到sum[1]=Hash[mid]-Hash[left]+Hash[right]-Hash[mid+1]
这样的到的底边长sum是错误的,why?因为少算了mid~mid+1的距离,由于我们这利用了
离散化且区间表示线段,所以mid~mid+1之间是有长度的,比如hash[3]=1.2,Hash[4]=5.6,mid=3
所以这里用r-1,r+1就很好理解了 
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define N 10010
int n;
int scnt;
int xcnt;
struct segment
{
    int left;
    int right;
    int height;
    int dir;
    segment(int li = 0, int ri = 0, int hi = 0, int di = 0) : left(li), right(ri), height(hi), dir(di) {}
};
segment segs[2 * N];
int xpos[2 * N];
bool cmp(segment &s1, segment &s2)
{
    return s1.height < s2.height;
}
int sum[N << 2];
int cnt[N << 2];
void push_up(int left, int right, int rt)
{
    if (cnt[rt])
    {
        sum[rt] = xpos[right + 1] - xpos[left];
        //cout << xpos[right + 1] << " " << xpos[left] << endl;
        //cout << sum[rt] << endl;
    }
    else if (left == right)
    {
        sum[rt] = 0;
    }
    else
    {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
}
void update(int start, int end, int left, int right, int rt, int dir)
{
    if (left >= start && right <= end)
    {
        cnt[rt] += dir;
        push_up(left, right, rt);
        return;
    }
    int mid = (left + right) >> 1;
    if (start <= mid)
        update(start, end, left, mid, rt << 1, dir);
    if (end > mid)
        update(start, end, mid + 1, right, rt << 1 | 1, dir);
    push_up(left, right, rt); //向上更新
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int x1, y1, x2, y2;
    scnt = 0;
    xcnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (x1 > x2)
        {
            swap(x1, x2);
            //调整顺序到左-右
        }
        if (y1 > y2)
        {
            swap(y1, y2);
            //调整顺序到下-上
        }
        
        segs[scnt++] = segment(x1, x2, y1, 1);  //下边
        segs[scnt++] = segment(x1, x2, y2, -1); //上边
        xpos[xcnt++] = x1;
        xpos[xcnt++] = x2;
    }
    sort(segs, segs + scnt, cmp);
    sort(xpos, xpos + xcnt);
    xcnt = unique(xpos, xpos + xcnt) - xpos;
    //高度排序扫描线
    long long ans = 0;
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < scnt - 1; i++)
    {
        int left = lower_bound(xpos, xpos + xcnt, segs[i].left) - xpos;
        int right = lower_bound(xpos, xpos + xcnt, segs[i].right) - xpos;
        update(left, right - 1, 0, xcnt, 1, segs[i].dir);
        ans += (segs[i + 1].height - segs[i].height) * sum[1];
    }
    cout << ans << endl;
    //system("pause");
    //return 0;
}
