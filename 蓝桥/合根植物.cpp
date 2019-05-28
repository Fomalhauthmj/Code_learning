#include <iostream>
#include <set>
using namespace std;
#define N 1010
int n, m, k;
int fa[N * N];
void init()
{
    for (int i = 1; i <= n * m; i++)
    {
        fa[i] = i;
    }
}
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    cin >> k;
    int u, v;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        Union(u, v);
    }
    set<int> s;
    for (int i = 1; i <= n * m; i++)
        if (fa[i] == i)
            s.insert(fa[i]);
    /*
    for (auto ele : s)
    {
        cout << ele << " ";
    }
    cout << endl;
    */
    cout << s.size() << endl;
    //system("pause");
    return 0;
}