#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e6 + 50;
const int M = 7E5 + 20;
#define ll long long
int n;
struct node
{
    ll t;
    ll score;
    bool operator<(const node &n) const
    {
        if (score != n.score)
            return score > n.score;
        else
            return t < n.t;
    }
};
node ns[N];
int fa[M];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ns[i].t >> ns[i].score;
    }
    sort(ns, ns + n);
    ll ans = 0;
    for (int i = 0; i < M; i++)
        fa[i] = i;
    for (int i = 0; i < n; i++)
    {
        int par = Find(ns[i].t);
        if (par)
        {
            ans += ns[i].score;
            fa[par] = Find(par - 1);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}