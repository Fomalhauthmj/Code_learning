#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 200020
vector<int> V[N];
int n, m;
vector<pair<int, int>> E;
vector<int> color;
bool flag;
void DFS(int v, int c)
{
    color[v] = c;
    for (auto to : V[v])
    {
        if (color[to] == -1)
        {
            DFS(to, c ^ 1);
        }
        else
        {
            //画图理解
            if (color[to] == color[v])
            {
                flag = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        E.push_back(make_pair(u, v)); //记录原始边序
        V[u].push_back(v);
        V[v].push_back(u); //建立无向图
    }
    color = vector<int>(n + 1, -1);
    //初始化
    flag = true;
    DFS(1, 0);
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        return 0;
    }
    for (auto ele : E)
    {
        cout << (color[ele.first] < color[ele.second]);
        //0<1  1
        //1<0  0  
    }
    cout << endl;
    //system("pause");
    return 0;
}