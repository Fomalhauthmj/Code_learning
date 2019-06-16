#include <iostream>
#include <string>
using namespace std;
#define N 2020
string s[N];
int L[N][N];
int R[N][N];
int U[N][N];
int D[N][N];
int h, w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++)
    {
        int cur = 0;
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
                cur = 0;
            else
                cur++;
            L[i][j] = cur;
        }
    }
    for (int i = 0; i < h; i++)
    {
        int cur = 0;
        for (int j = w - 1; j >= 0; j--)
        {
            if (s[i][j] == '#')
                cur = 0;
            else
                cur++;
            R[i][j] = cur;
        }
    }
    for (int j = 0; j < w; j++)
    {
        int cur = 0;
        for (int i = 0; i < h; i++)
        {
            if (s[i][j] == '#')
                cur = 0;
            else
                cur++;
            U[i][j] = cur;
        }
    }
    for (int j = 0; j < w; j++)
    {
        int cur = 0;
        for (int i = h - 1; i >= 0; i--)
        {
            if (s[i][j] == '#')
                cur = 0;
            else
                cur++;
            D[i][j] = cur;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '.')
                ans = max(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}