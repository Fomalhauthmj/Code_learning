#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int M = 105;
int n, m, t[M], b1[M], b2[M], f1[M], f2[M];
int dis[1 << 20];
bool vis[1 << 20];
int SPFA(int S)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[S] = 0;
    vis[S] = 1;
    q.push(S);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = 1; i <= m; i++)
        {
            if (((x | b1[i]) == x) && ((x & b2[i]) == 0))
            {
                int temp = x & f1[i];
                int y = (x ^ temp) | f2[i];
                if (dis[y] > dis[x] + t[i])
                {
                    dis[y] = dis[x] + t[i];
                    if (!vis[y])
                        q.push(y), vis[y] = 1;
                }
            }
        }
    }
    if(dis[0]>=0x3f3f3f3f) return 0;
    return dis[0];
}
int main()
{
    scanf("%d%d", &n, &m);
    char s[25];
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &t[i]);
        scanf("%s", s);
        for (int j = 0; j < n; j++)
        {
            int k = n - 1 - j;
            if (s[j] == '+')
                b1[i] += (1 << k);
            else if (s[j] == '-')
                b2[i] += (1 << k);
        }
        //cout << "b " << b1[i] << " " << b2[i] << endl;
        scanf("%s", s);
        for (int j = 0; j < n; j++)
        {
            int k = n - 1 - j;
            if (s[j] == '-')
                f1[i] += (1 << k);
            else if (s[j] == '+')
                f2[i] += (1 << k);
        }
        //cout << "f " << f1[i] << " " << f2[i] << endl;
    }
    printf("%d\n", SPFA((1 << n) - 1));
    //system("pause");
    return 0;
}