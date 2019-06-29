#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int t_mat[5][5];
int mat[5][5];
int n;
void Change(int i, int j)
{
    if (i < 0 || i >= 5)
        return;
    if (j < 0 || j >= 5)
        return;
    t_mat[i][j] = t_mat[i][j] ^ 1;
}
int Solve(int s)
{
    int temp = 0;
    memcpy(t_mat, mat, sizeof(mat));
    for (int i = 0; i < 5; i++)
    {
        if (((s >> i) & 1))
        {
            Change(0, i);
            Change(1, i);
            Change(0, i + 1);
            Change(0, i - 1);
            temp++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!t_mat[i][j])
            {
                temp++;
                Change(i, j);
                Change(i + 1, j);
                Change(i + 1, j - 1);
                Change(i + 1, j + 1);
                Change(i + 2, j);
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if (!t_mat[4][j])
            return -1;
    }
    return temp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string str;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> str;
            for (int j = 0; j < 5; j++)
                mat[i][j] = str[j] - '0';
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 32; i++)
        {
            int temp = Solve(i);
            //cout << i << " " << temp << endl;
            if (temp != -1)
                ans = min(ans, temp);
        }
        if (ans > 6)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    //system("pause");
    return 0;
}