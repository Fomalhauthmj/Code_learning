#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define N 200050
vector<pair<int, long long>> V[N];
int n, m;
long long u, v, k, w;
vector<long long> dis;
vector<long long> temp;
map<pair<int, int>, vector<long long>> M;
bool DFS(int start, int pre)
{
    pair<int, int> p = make_pair(start, v);
    if (M[p].size() > 0)
    {
        /*
        cout << "short:" << endl;
        cout << "before:";
        for (auto ele : dis)
        {
            cout << ele << " ";
        }
        cout << endl;
        */
        temp = dis;
        dis = M[p];
        /*
        for (auto ele : temp)
        {
            cout << ele << " / ";
        }
        cout << endl;
        for (auto ele : dis)
        {
            cout << ele << " / ";
        }
        cout << endl;
        */
        /*
        cout << "after:";
        for (auto ele : dis)
        {
            cout << ele << " ";
        }
        cout << endl;
        */
        return true;
    }
    if (start == v)
    {
        M[make_pair(u, v)] = dis;
        /*
        cout << "insert:";
        for (auto ele : M[make_pair(u, v)])
        {
            cout << ele<<" ";
        }
        cout << endl;
        */
        return true;
    }
    for (auto ele : V[start])
    {
        if (ele.first != pre)
        {
            dis.push_back(ele.second);
            if (DFS(ele.first, start))
                return true;
            dis.pop_back();
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        V[u].push_back(make_pair(v, w));
        V[v].push_back(make_pair(u, w));
        //建立无向图
    }
    while (m--)
    {
        cin >> u >> v >> k;
        dis.clear();
        temp.clear();
        DFS(u, -1);
        sort(dis.begin(), dis.end());
        sort(temp.begin(), temp.end());
        int num1 = upper_bound(dis.begin(), dis.end(), k) - dis.begin();
        int num2 = upper_bound(temp.begin(), temp.end(), k) - temp.begin();
        //cout << num1 << " " << num2 << endl;
        cout << num1 + num2 << endl;
    }
    //system("pause");
    return 0;
}