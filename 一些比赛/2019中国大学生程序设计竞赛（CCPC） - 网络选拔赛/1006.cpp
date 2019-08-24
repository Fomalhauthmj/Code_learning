#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
int a[N], n, m, b[N];
bool vis[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (int i = m; i >= 1; i--)
    {
        if (!vis[b[i]])
        {
            printf("%d ", b[i]), vis[b[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[a[i]])
        {
            printf("%d ", a[i]);
            vis[a[i]] = true;
        }
    }
    //system("pause");
    return 0;
}