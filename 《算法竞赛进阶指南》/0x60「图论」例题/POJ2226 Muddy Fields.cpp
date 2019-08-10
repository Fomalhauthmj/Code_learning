#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 55;
vector<int> v[N * N];
bool vis[N * N];
int n, m, match[N * N];
char ground[N][N];
int belong_row_block[N][N], belong_col_block[N][N];
bool DFS(int x)
{
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        if (!vis[y])
        {
            vis[y] = 1;
            if (!match[y] || DFS(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ground[i][j];
        }
    }
    int row_block = 0, col_block = 0;
    //行泥泞块
    for (int i = 1; i <= n; i++)
    {
        char pre = '.';
        for (int j = 1; j <= m; j++)
        {
            if (ground[i][j] == '*')
            {
                if (pre == '*')
                    belong_row_block[i][j] = row_block;
                else
                    belong_row_block[i][j] = ++row_block;
            }
            pre = ground[i][j];
        }
    }
    //列泥泞块
    for (int j = 1; j <= m; j++)
    {
        char pre = '.';
        for (int i = 1; i <= n; i++)
        {
            if (ground[i][j] == '*')
            {
                if (pre == '*')
                    belong_col_block[i][j] = col_block;
                else
                    belong_col_block[i][j] = ++col_block;
            }
            pre = ground[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ground[i][j] == '*')
                v[belong_row_block[i][j]].push_back(belong_col_block[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= row_block; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}
/*
5 5
**.**
.*.*.
.****
.*.*.
***..
*/