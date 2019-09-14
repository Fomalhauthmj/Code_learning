#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e5 + 50;
const int M = 4e5 + 50;
int n, m, k;
int sze[N], fa[N];
bool monster[N];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
vector<int> V[N];
void Init()
{
    memset(monster, 0, sizeof(monster));
    for (int i = 1; i <= n; i++)
        fa[i] = i, sze[i] = 1, V[i].clear();
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        Init();
        for (int i = 0, x, y; i < m; i++)
            scanf("%d%d", &x, &y), V[x].push_back(y), V[y].push_back(x);
        for (int i = 0, pos; i < k; i++)
            scanf("%d", &pos), monster[pos] = true, sze[pos] = 0;
        for (int x = 1; x <= n; x++)
        {
            for (int y : V[x])
            {
                if (!monster[x] && !monster[y])
                {
                    int fx = Find(x), fy = Find(y);
                    if (fx != fy)
                    {
                        fa[fx] = fy;
                        sze[fy] += sze[fx];
                    }
                }
            }
        }
        //for (int i = 1; i <= n; i++)
        //cout << i << " " << Find(i) << " " << sze[Find(i)] << endl;
        int start = Find(1);
        double ans = sze[start];
        sze[start] = 0;
        double temp = 0;
        for (int x = 1; x <= n; x++)
        {
            if (monster[x])
            {
                int connect = 0;
                int sum = 0;
                for (int y : V[x])
                {
                    int fy = Find(y);
                    if (fy == start)
                        connect++;
                    sum += sze[fy];
                }
                if (connect)
                    temp = max(temp, sum * 1.0 / V[x].size());
            }
        }
        printf("%.6f\n", ans + temp);
    }
    //system("pause");
    return 0;
}
