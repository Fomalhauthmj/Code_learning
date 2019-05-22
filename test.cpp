#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 110;
const int INF = 10000000;

struct Node
{
    int s[9];
    Node()
    {
        memset(s, 0, sizeof(s));
    }
    bool operator==(const Node &a) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (s[i] != a.s[i])
                return false;
        }
        return true;
    }
    bool operator<(const Node &a) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (s[i] < a.s[i])
                return true;
            else if (s[i] > a.s[i])
                return false;
        }
        return false;
    }
};

int n, s, ls, n1s, n2s, sta, des, cnt, G[MAXN][MAXN], dis[MAXN][MAXN];
map<Node, int> mp;

int floyd()
{
    int ans = INF;
    memcpy(dis, G, sizeof(G));
    for (int k = 1; k <= cnt; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
            {
                ans = min(ans, dis[i][j] + G[i][k] + G[k][j]);
            }
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = 1; j <= cnt; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return ans;
}

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        fill(G[i], G[i] + MAXN, INF);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Node f1, f2;
        cin >> s >> ls >> n1s >> n2s;
        f1.s[8] = f2.s[8] = s;
        while (n1s--)
            cin >> f1.s[n1s];
        sort(f1.s, f1.s + 9);
        if (mp[f1] == 0)
            mp[f1] = ++cnt;
        while (n2s--)
            cin >> f2.s[n2s];
        sort(f2.s, f2.s + 9);
        if (mp[f2] == 0)
            mp[f2] = ++cnt;
        sta = mp[f1];
        des = mp[f2];
        G[sta][des] = G[des][sta] = ls;
    }
    cout << floyd() << endl;
    system("pause");
    return 0;
}