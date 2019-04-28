#include <iostream>
#include <vector>
using namespace std;
#define N 300030
int a[N];
vector<int> V[N];
int n;
int redp;
int bluep;
int ans;
pair<int, int> DFS(int start, int pre = -1)
{
    int red = (a[start] == 1);//以start点为起点 先初始化颜色点数量
    int blue = (a[start] == 2);
    for (auto ele : V[start])
    {
        if(ele!=pre)//向子结点DFS
        {
            auto temp = DFS(ele, start);
            //如果子结点的蓝色数量为0 且 子结点的红色数量最大
            ans += (temp.second == 0) && (temp.first == redp);
            //如果子结点的红色数量为0 且 子结点的蓝色数量最大
            ans += (temp.first == 0) && (temp.second == bluep);
            red += temp.first;//更新颜色点数量
            blue += temp.second;
        }
    }
    return make_pair(red, blue);//返回颜色点数量
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            V[i].clear();
        redp = bluep = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            redp += (a[i] == 1);
            bluep += (a[i] == 2);
        }
        int u, v;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u); //建图
        }
        ans = 0;
        DFS(1);
        cout << ans << endl;
    }
}