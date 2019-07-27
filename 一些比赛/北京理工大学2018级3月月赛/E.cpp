#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 105
#define pii pair<int, int>
int n, m;
char a[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pii> enemy;
pii start, target;
bool vis[N][N];
struct node
{
    int x, y, step;
    node(int xx, int yy, int ss) : x(xx), y(yy), step(ss) {}
};
bool Judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || a[x][y] == 'T')
        return false;
    return true;
}
int BFS(pii s, pii t)
{
    queue<node> q;
    q.push({s.first, s.second, 0});
    memset(vis, 0, sizeof(vis));
    vis[s.first][s.second] = 1;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            if (Judge(nx, ny))
            {
                vis[nx][ny] = 1;
                q.push({nx, ny, now.step + 1});
                if (nx == target.first && ny == target.second)
                    return now.step + 1;
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        enemy.clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                    start.first = i, start.second = j;
                else if (a[i][j] == 'E')
                    target.first = i, target.second = j;
                else if (a[i][j] >= '1' && a[i][j] <= '9')
                    enemy.push_back({i, j});
            }
        }
        int std_step = BFS(start, target);
        //cout << "std:" << std_step << endl;
        int ans = 0;
        for (auto it : enemy)
        {
            int temp = BFS(it, target);
            //cout << "cur: " << temp << endl;
            if (temp != -1 && temp <= std_step)
                ans += a[it.first][it.second] - '0';
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}