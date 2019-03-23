#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#define N 100010
using namespace std;
int n;
struct seg
{
    long long x;
    int flag;
    long long height;
    seg(long long xi = 0, int f = 0, long long hi = 0) : x(xi), flag(f), height(hi) {}
};
seg segs[2 * N];
bool cmp(seg &s1, seg &s2)
{
    return s1.x < s2.x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    long long hi, li, ri;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> hi >> li >> ri;
        segs[cnt++] = seg(li, 1, hi);
        segs[cnt++] = seg(ri, -1, hi);
        //seg[2i] seg[2i+1]
    }
    sort(segs, segs + cnt, cmp);
    //按x轴排序
    multiset<long long> S;
    //h高度
    S.insert(0);
    vector<pair<long long, long long>> V;
    long long pre_max, cur_max;
    pre_max = 0;
    int i, j;
    for (i = 0; i < cnt; i = j)//注意这个循环
    {
        for (j = i; j < cnt && segs[i].x == segs[j].x; j++)
        {
            if (segs[j].flag == 1) //左线加入
            {
                S.insert(segs[j].height);
            }
            else //右线删除
            {
                S.erase(S.lower_bound(segs[j].height)); //指针去掉此高度
            }
        }
        cur_max = *(S.rbegin());
        //默认从小到大排序
        if (cur_max != pre_max)
        {
            V.push_back(make_pair(segs[i].x, pre_max));
            V.push_back((make_pair(segs[i].x, cur_max)));
        }
        pre_max = cur_max;
    }
    cout << V.size() << endl;
    for (auto ele : V)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    //system("pause");
    return 0;
}