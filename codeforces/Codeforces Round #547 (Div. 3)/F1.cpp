#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define N 55
long long a[N];
long long sum[N];
int n;
map<long long, vector<pair<int, int>>> m;
bool vis[N];
void setUsed(int left, int right)
{
    for (int i = left; i <= right; i++)
        vis[i] = 1;
}
bool judge(int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (vis[i])
            return false;
    }
    return true;
}
int find(int key)
{
    for (int r = 0; r < n; r++) //区块单元数
    {
        if (sum[r] == key && judge(0, r))
        {
            m[key].push_back(make_pair(1, r + 1));
            setUsed(0, r);
        }
        for (int i = 0; i + r + 1 < n; i++)
        {
            if ((sum[i + r + 1] - sum[i]) == key && judge(i + 1, i + r + 1))
            {
                m[key].push_back(make_pair(i + 2, i + r + 2));
                setUsed(i + 1, i + r + 1);
            }
        }
    }
    return m[key].size();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i != 0)
            sum[i] = sum[i - 1] + a[i];
        else
            sum[i] = a[i];
    }
    //找出最大的区块数
    //固定区块和值?
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(sum[i]);
        for (int j = i + 1; j < n; j++)
        {
            s.insert(sum[j] - sum[i]);
        }
    }
    int ans = 0;
    int ans_sum;
    for (auto ele : s)
    {
        memset(vis, 0, sizeof(vis));
        int temp = find(ele);
        if (temp > ans)
        {
            ans = temp;
            ans_sum = ele;
        }
    }
    cout << ans << endl;
    for (auto ele : m[ans_sum])
    {
        cout << ele.first << " " << ele.second << endl;
    }
    //system("pause");
    return 0;
}