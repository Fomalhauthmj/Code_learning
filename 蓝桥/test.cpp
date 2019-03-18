#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int MAX = 210;
int N;
double x[MAX << 2];
struct Node
{
    double l, r;
    double h;
    int flag;
} node[MAX << 2];
int cmp(Node a, Node b)
{
    return a.h < b.h;
}
struct Tree
{
    int l, r;
    int cnt;
    double len;
} tree[MAX << 2];
int findPos(int l, int r, double val)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (x[mid] > val)
            r = mid - 1;
        else if (x[mid] < val)
            l = mid + 1;
        else
            break;
    }
    return mid;
}
void build(int rt, int left, int right)
{
    tree[rt].l = left;
    tree[rt].r = right;
    tree[rt].len = 0;
    tree[rt].cnt = 0;
    if (left == right)
        return;
    int mid = (left + right) >> 1;
    build(rt << 1, left, mid);
    build(rt << 1 | 1, mid + 1, right);
}
void pushUp(int rt)
{
    if (tree[rt].cnt) //非0，整段覆盖
        tree[rt].len = x[tree[rt].r + 1] - x[tree[rt].l];
    else if (tree[rt].l == tree[rt].r) //叶子
        tree[rt].len = 0;
    else //部分覆盖
        tree[rt].len = tree[rt << 1].len + tree[rt << 1 | 1].len;
}
void update(int rt, int left, int right, int val)
{
    if (left <= tree[rt].l && tree[rt].r <= right) //全部包含
    {
        tree[rt].cnt += val;
        pushUp(rt);
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (left <= mid)
        update(rt << 1, left, right, val);
    if (right > mid)
        update(rt << 1 | 1, left, right, val);
    pushUp(rt); //计算该区间被覆盖的总长度
}
int main()
{
    int K = 0;
    int l, r;
    double x1, x2, y1, y2;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N))
    {
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            x[++cnt] = x1;
            node[cnt].l = x1;
            node[cnt].r = x2;
            node[cnt].h = y1;
            node[cnt].flag = 1; //下边
            x[++cnt] = x2;
            node[cnt].l = x1;
            node[cnt].r = x2;
            node[cnt].h = y2;
            node[cnt].flag = -1; //上边
        }
        sort(x + 1, x + cnt + 1); //排序
        sort(node + 1, node + cnt + 1, cmp);
        /*
        int M=1;
        for(int i=1; i<cnt; i++)//去重  可去可不去
            if(x[i]!=x[i-1])
                x[M++]=x[i];
        */
        build(1, 1, cnt);
        double ans = 0;
        for (int i = 1; i <= cnt; i++) //拿出每条横线并且更新
        {
            l = findPos(1, cnt, node[i].l);
            r = findPos(1, cnt, node[i].r) - 1;
            update(1, l, r, node[i].flag);
            ans += tree[1].len * (node[i + 1].h - node[i].h); //求面积
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++K, ans);
    }
    return 0;
}
