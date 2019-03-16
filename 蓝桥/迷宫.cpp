#include <iostream>
using namespace std;
#define N 4
char maze[N][N];
bool DFS(int r, int c, int step)
{
    if (step > 150)
        return false;
    if (r < 0 || c < 0 || r >= N || c >= N)
        return true;
    switch (maze[r][c])
    {
    case 'U':
        if (DFS(r - 1, c, step + 1))
            return true;
        break;
    case 'D':
        if (DFS(r + 1, c, step + 1))
            return true;
        break;
    case 'L':
        if (DFS(r, c - 1, step + 1))
            return true;
        break;
    case 'R':
        if (DFS(r, c + 1, step + 1))
            return true;
        break;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maze[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (DFS(i, j, 0))
                ans++;
    }
    cout << ans << endl;
    system("pause");
}