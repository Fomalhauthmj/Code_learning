#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define pii pair<int, int>
#define inf 0x3f3f3f3f
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    inline bool judge(int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }
    vector<vector<int>> bfs(vector<string> &maze, pii start)
    {
        //cout<<"start:"<<start.first<<" "<<start.second<<endl;
        vector<vector<int>> dis(n, vector<int>(m, inf));
        queue<pii> q;
        dis[start.first][start.second] = 0, q.push(start);
        while (q.size())
        {
            pii cur = q.front();
            q.pop();
            //cout<<"cur:"<<cur.first<<" "<<cur.second<<endl;
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dir[i][0], ny = cur.second + dir[i][1];
                if (judge(nx, ny) && maze[nx][ny] != '#' && dis[nx][ny] == inf)
                {
                    dis[nx][ny] = dis[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dis;
    }
    int minimalSteps(vector<string> &maze)
    {
        n = maze.size(), m = maze[0].size();
        vector<pii> O, M;
        pii start, target;
        vector<vector<int>> mto[20], dis;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'S')
                    start = {i, j};
                else if (maze[i][j] == 'T')
                    target = {i, j};
                else if (maze[i][j] == 'O')
                    O.push_back({i, j});
                else if (maze[i][j] == 'M')
                    M.push_back({i, j});
            }
        }
        int mlen = M.size(), olen = O.size();
        dis = bfs(maze, start);

        if (!mlen)
            return dis[target.first][target.second] >= inf ? -1 : dis[target.first][target.second];

        vector<int> starttoo(olen, -1);
        for (int i = 0; i < olen; i++)
            starttoo[i] = dis[O[i].first][O[i].second];

        for (int i = 0; i < mlen; i++)
        {
            mto[i] = bfs(maze, M[i]);
            if (mto[i][start.first][start.second] >= inf || mto[i][target.first][target.second] >= inf)
                return -1;
        }
        vector<vector<int>> mtom(mlen, vector<int>(mlen, inf));

        for (int i = 0; i < mlen; i++)
            for (int j = i + 1; j < mlen; j++)
                for (int k = 0; k < olen; k++)
                    mtom[j][i] = mtom[i][j] = min(mtom[i][j], mto[i][O[k].first][O[k].second] + mto[j][O[k].first][O[k].second]);

        vector<vector<int>> dp(1 << mlen, vector<int>(mlen, inf));

        for (int i = 0; i < mlen; i++)
            for (int j = 0; j < olen; j++)
                dp[1 << i][i] = min(dp[1 << i][i], starttoo[j] + mto[i][O[j].first][O[j].second]);

        for (int mask = 0; mask < (1 << mlen); mask++)
        {
            for (int i = 0; i < mlen; i++)
            {
                if (!(mask & (1 << i)))
                {
                    for (int j = 0; j < mlen; j++)
                    {
                        if (mask & (1 << j))
                        {
                            dp[mask | (1 << i)][i] = min(dp[mask][j] + mtom[i][j], dp[mask | (1 << i)][i]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < mlen; i++)
            ans = min(ans, dp[(1 << mlen) - 1][i] + mto[i][target.first][target.second]);
        return ans >= inf ? -1 : ans;
    }
};