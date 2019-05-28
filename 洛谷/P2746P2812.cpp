//https://www.luogu.org/problemnew/show/P2746
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 10500;
vector<int> V[N];
set<int> S[N];
int n;
bool vis[N];
int dfn[N];
int low[N];
int color[N];
int outdegree[N];
int indegree[N];
stack<int> s;
int cnt;
int sum;
void Init()
{
    cnt = 0;
    sum = 0;
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
}
void Tarjan(int cur)
{
    dfn[cur] = low[cur] = ++cnt;
    vis[cur] = 1;
    s.push(cur);
    for (auto ele : V[cur])
    {
        if (!dfn[ele])
        {
            Tarjan(ele);
            low[cur] = min(low[cur], low[ele]);
        }
        else if (vis[ele])
        {
            low[cur] = min(low[cur], dfn[ele]);
        }
    }
    if (dfn[cur] == low[cur])
    {
        ++sum;
        while (1)
        {
            int now = s.top();
            s.pop();
            color[now] = sum;
            vis[now] = 0;
            //cout << now << " ";
            if (now == cur)
                break;
        }
        //cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        while (num)
        {
            V[i + 1].push_back(num);
            cin >> num;
        }
    }
    Init();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            Tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto ele : V[i])
        {
            if (color[i] != color[ele] && !S[color[i]].count(color[ele]))
            {
                S[color[i]].insert(color[ele]);
                outdegree[color[i]]++;
                indegree[color[ele]]++;
            }
        }
    }
    /*
    for (int i = 1; i <= sum; i++)
    {
        cout << "color" << i << ":";
        for (auto ele : S[i])
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    */
    int ansA = 0;
    int ansB = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (!indegree[i])
            ansA++;
        if (!outdegree[i])
            ansB++;
    }
    if (sum == 1)
    {
        //特判
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << ansA << endl;
    cout << max(ansA, ansB) << endl;
    //这里为什么是入度出度为0的最大值？
    //system("pause");
    return 0;
}