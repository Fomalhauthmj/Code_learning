#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int n, m, p, k, s;
int maze[15][15], limit[15][15][15][15];
bool vis[15][15][1 << 10];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node
{
    int x, y, key, t;
};
bool Judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &k);
    memset(limit, -1, sizeof(limit));
    for (int i = 1; i <= k; i++)
    {
        int x1, y1, x2, y2, g;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
        limit[x1][y1][x2][y2] = limit[x2][y2][x1][y1] = g;
    }
    scanf("%d", &s);
    for (int i = 1; i <= s; i++)
    {
        int x, y, q;
        scanf("%d%d%d", &x, &y, &q), maze[x][y] |= (1 << (q - 1));
    }
    queue<node> q;
    int ans = -1;
    q.push({1, 1, 0, 0});
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        vis[now.x][now.y][now.key] = true;
        //cout<<now.x<<" "<<now.y<<" "<<now.t<<" "<<now.key<<endl;
        if (now.x == n && now.y == m)
        {
            ans = now.t;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            if (Judge(nx, ny))
            {
                if (limit[now.x][now.y][nx][ny] == -1)
                {
                    int temp = now.key | maze[nx][ny];
                    if (!vis[nx][ny][temp])
                        q.push({nx, ny, temp, now.t + 1});
                }
                else if (limit[now.x][now.y][nx][ny] >= 1)
                {
                    int need_key = limit[now.x][now.y][nx][ny] - 1;
                    if ((now.key >> need_key) & 1)
                    {
                        int temp = now.key | maze[nx][ny];
                        if (!vis[nx][ny][temp])
                            q.push({nx, ny, temp, now.t + 1});
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}