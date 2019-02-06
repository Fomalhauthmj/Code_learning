#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#define N 510
using namespace std;
int picture[N][N];
//1->0 BFS
int h, w;
bool vis[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool legal(int r, int c)
{
    if (r < 0 || r >= h)
        return false;
    if (c < 0 || c >= w)
        return false;
    if (vis[r][c] || !picture[r][c])
        return false;
    return true;
}
void BFS(int sr, int sc)
{
    queue<pair<int, int>> Q;
    vis[sr][sc] = 1;
    picture[sr][sc] = 0;
    Q.push(make_pair(sr, sc));
    while (!Q.empty())
    {
        pair<int, int> now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = now;
            next.first += dir[i][0];
            next.second += dir[i][1];
            if (legal(next.first, next.second))
            {
                vis[next.first][next.second] = 1;
                picture[next.first][next.second] = 0;
                Q.push(next);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> h >> w;
        set<pair<int, int>> s;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> picture[i][j];
                if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && picture[i][j])
                    s.insert(make_pair(i, j));
            }
        }
        memset(vis, 0, sizeof(vis));
        for (auto ele : s)
        {
            BFS(ele.first, ele.second);
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cout << picture[i][j];
                if (j == w - 1)
                    cout << endl;
                else
                    cout << " ";
            }
        }
    }
}