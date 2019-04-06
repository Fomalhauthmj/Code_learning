#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define N 1550
long long a[N];
long long sum[N];
int n;
map<long long, vector<pair<int, int>>> m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //找出最大的区块数
    //固定区块和值?
    for (int r = 0; r < n; r++)
    {
        long long sum = 0;
        for (int l = r; l >= 0; l--)
        {
            sum += a[l];
            m[sum].push_back(make_pair(l, r));
        }
    }
    //处理方式 预先排序
    int result = 0;
    vector<pair<int, int>> best;
    for (auto group : m)
    {
        vector<pair<int, int>> temp;
        int cur = 0;
        int r = -1;
        //贪心
        for (auto p : group.second)
        {
            if (p.first > r)
            {
                cur++;
                temp.push_back(p);
                r = p.second;
            }
        }
        if (cur > result)
        {
            result = cur;
            best = temp;
        }
    }
    cout << result << endl;
    for (auto p : best)
    {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    //system("pause");
    return 0;
}