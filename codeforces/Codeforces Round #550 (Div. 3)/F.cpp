#include <iostream>
#include <vector>
using namespace std;
#define N 200020
vector<pair<int, int>> V[N];
int n, m;
vector<pair<int, int>> E;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        E.push_back(make_pair(u, v));
        V[u].push_back(make_pair(v, 0));
        V[v].push_back(make_pair(u, 0));
    }
}