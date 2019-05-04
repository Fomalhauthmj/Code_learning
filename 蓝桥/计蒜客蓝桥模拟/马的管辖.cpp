#include <cstring>
#include <iostream>
#include <set>
using namespace std;
//两部分
//先求出5x5最少管辖马的数量A 然后确定方案数B
int board[5][5]; //0空   1马   2被管辖
int dir1[4][2][2] = {{{1, 2}, {-1, 2}}, {{1, -2}, {-1, -2}}, {{2, 1}, {2, -1}}, {{-2, -1}, {-2, 1}}};
int dir2[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool legal(int r, int c)
{
    if (r < 0 || r >= 5)
        return false;
    if (c < 0 || c >= 5)
        return false;
    return true;
}
bool control()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}
void print()
{
    int horse_num = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << board[i][j];
            if (board[i][j] == 1)
                horse_num++;
        }
        cout << endl;
    }
    cout << "horse of this plan:" << horse_num << endl;
}
void DFS(int depth)
{
    if (control() || depth >= 25)
    {
        if (control())
        {
            print();
        }
        return;
    }
    int i = depth / 5;
    int j = depth % 5;
    set<pair<int, int>> s;
    if (board[i][j] == 0)
    {
        for (int k = 0; k < 4; k++)
        {
            int jr = i + dir2[i][0];
            int jc = j + dir2[i][1];
            if (legal(jr, jc) && board[jr][jc] == 0)
            {
                int r1 = i + dir1[i][0][0];
                int c1 = j + dir1[i][0][1];
                if (legal(r1, c1) && !board[r1][c1])
                {
                    board[r1][c1] = 2;
                    s.insert(make_pair(r1, c1));
                }
                int r2 = i + dir1[i][1][0];
                int c2 = j + dir1[i][1][1];
                if (legal(r2, c2) && !board[r2][c2])
                {
                    board[r2][c2] = 2;
                    s.insert(make_pair(r2, c2));
                }
            }
        }
        board[i][j] = 1;
        s.insert(make_pair(i, j));
    }
    DFS(depth + 1);
    for (auto ele : s)
    {
        board[ele.first][ele.second] = 0;
    }
    DFS(depth + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    DFS(0);
    system("pause");
}