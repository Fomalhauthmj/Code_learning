#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
#define ll long long
#define pii pair<int, int>
int n, m;
int x[N];
int Pos(int i, int x)
{
    if (x == i)
        return 1;
    else if (x < i)
        return x + 1;
    return x;
}
ll ans[N];
map<pii, int> c;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i < m; i++)
    {
        int a = x[i], b = x[i + 1];
        if (x[i] > x[i + 1])
            swap(a, b);
        c[make_pair(a, b)]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto it : c)
        {
            ans[i] += it.second * abs(Pos(i, it.first.first) - Pos(i, it.first.second));
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    printf("\n");
    //system("pause");
    return 0;
}