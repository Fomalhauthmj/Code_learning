#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define N 2020
int s[N][N];
int h, w;
bool judge(int r, int c)
{
    if (r < 0 || r >= h)
        return false;
    if (c < 0 || c >= w)
        return false;
    return true;
}
int Solve(int r, int c)
{
    int left = c - 1;
    int right = c + 1;
    int up = r - 1;
    int down = r + 1;
    while (judge(r, left) && !s[r][left])
        left--;
    while (judge(r, right) && !s[r][right])
        right++;
    while (judge(up, c) && !s[up][c])
        up--;
    while (judge(down, c) && !s[down][c])
        down++;
    //cout << c - 1 - left << endl;
    //cout << right - c - 1 << endl;
    //cout << r - 1 - up << endl;
    //cout << down - r - 1 << endl;
    return c - 1 - left + right - c - 1 + r - 1 - up + down - r - 1 + 1;
}
int rows[N];
int cols[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    string str;
    memset(s, 0, sizeof(s));
    int max_row_num = 0;
    int max_col_num = 0;
    for (int i = 0; i < h; i++)
    {
        cin >> str;
        rows[i] = 0;
        for (int j = 0; j < w; j++)
            if (str[j] == '#')
                s[i][j] = 1;
            else
                rows[i]++;
        if (rows[i] > max_row_num)
        {
            max_row_num = rows[i];
        }
    }
    for (int j = 0; j < w; j++)
    {
        cols[j] = 0;
        for (int i = 0; i < h; i++)
        {
            if (!s[i][j])
                cols[j]++;
        }
        if (cols[j] > max_col_num)
        {
            max_col_num = cols[j];
        }
    }
    vector<int> vh, vw;
    for (int i = 0; i < h; i++)
    {
        if (rows[i] > max_row_num / 2)
            vh.push_back(i);
    }
    for (int j = 0; j < w; j++)
    {
        if (cols[j] > max_col_num / 2)
            vw.push_back(j);
    }
    int ans = 0;
    for (auto i : vh)
    {
        for (auto j : vw)
        {
            int temp = Solve(i, j);
            //cout << i << " " << j << " " << temp << endl;
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}