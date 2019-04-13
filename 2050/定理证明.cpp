#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define N 1010
vector<int> G[N];
map<int, pair<int, int>> kv;
bool vis[N];
bool DFS(int start, int end)
{
    if (start == end)
        return true;
    for (auto ele : G[start])
    {
        if (!vis[ele])
        {
            vis[ele] = 1;
            if (DFS(ele, end))
                return true;
            vis[ele] = 0;
        }
    }
    return false;
}
void disp(vector<pair<int, int>> v)
{
    for (auto ele : v)
    {
        cout << ele.first << "->" << ele.second << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        vector<int> order;
        for (int i = 0; i < n * (n - 1); i++)
        {
            order.push_back(i);
        }
        //原始顺序
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    kv[cnt++] = make_pair(i, j);
                }
            }
        }
        //建立映射
        vector<pair<int, int>> best;
        int best_size = 0;
        do
        {
            for (auto ele : order)
            {
                cout << ele << " ";
            }
            cout << endl;
            vector<pair<int, int>> temp;
            for (auto ele : G)
                ele.clear(); //清空有向图
            for (auto ele : order)
            {
                cout << "test:" << kv[ele].first << "->" << kv[ele].second << endl;
                cout << "before:";
                disp(temp);
                memset(vis, 0, sizeof(vis));
                vis[kv[ele].first] = 1;
                if (!DFS(kv[ele].first, kv[ele].second)) //测试
                {
                    temp.push_back(kv[ele]);
                    G[kv[ele].first].push_back(kv[ele].second);
                    //补充图
                }
                else
                {
                    cout << "after:";
                    disp(temp);
                    cout << endl;
                    break;
                }
                cout << "after:";
                disp(temp);
                cout << endl;
            }
            if (temp.size() > best_size)
            {
                best_size = temp.size();
                best = temp;
            }
        } while (next_permutation(order.begin(), order.end()));
        cout << best_size << endl;
        for (auto ele : best)
        {
            cout << ele.first << "->" << ele.second << endl;
        }
    }
    system("pause");
}