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
    //system("pause");
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