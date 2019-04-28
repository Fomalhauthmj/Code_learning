#include <cstring>
#include <iostream>
using namespace std;
#define N 200020
int n;
int q[N];
long long pres[N];
bool vis[N];
int a[N];
/* TLE
int a[N];
bool vis[N];
bool DFS(int step)
{
    if (step >= n)
    {
        return true;
    }
    if (step == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 1;
            a[step] = i;
            if (DFS(step + 1))
                return true;
            vis[i] = 0;
        }
    }
    else
    {
        a[step] = a[step - 1] + q[step - 1];
        if (a[step] < 1 || a[step] > n || vis[a[step]])
            return false;
        vis[a[step]] = 1;
        if (DFS(step + 1))
            return true;
        vis[a[step]] = 0;
    }
    return false;
}
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    pres[0] = 0;
    long long min_pres = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> q[i];
        pres[i + 1] = pres[i] + q[i];
        min_pres = min(min_pres, pres[i + 1]);
    }
    long long x = 1 - min_pres;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        a[i] = pres[i] + x;
        if (a[i] < 1 || a[i] > n)
        {
            cout << -1 << endl;
            return 0;
        }
        if (!vis[a[i]])
        {
            vis[a[i]] = 1;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
    //system("pause");
}