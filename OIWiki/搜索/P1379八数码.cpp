#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int N = 3;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool judge(int r, int c)
{
    if (r < 0 || r >= N)
        return false;
    if (c < 0 || c >= N)
        return false;
    return true;
}
struct Matrix
{
    int a[N][N];
    bool operator<(Matrix m) const
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (m.a[i][j] != a[i][j])
                    return a[i][j] < m.a[i][j];
            }
        }
        //?? ??false
        return false;
    }
};
set<Matrix> s;
Matrix target;
int h(Matrix m)
{
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m.a[i][j] != target.a[i][j])
                ret++;
        }
    }
    return ret;
}
struct node
{
    Matrix matrix;
    int g;
    bool operator<(node n) const
    {
        return g + h(matrix) > n.g + h(n.matrix);
    }
};
priority_queue<node> q;
void init()
{
    //123804765
    target.a[0][0] = 1;
    target.a[0][1] = 2;
    target.a[0][2] = 3;
    target.a[1][0] = 8;
    target.a[1][1] = 0;
    target.a[1][2] = 4;
    target.a[2][0] = 7;
    target.a[2][1] = 6;
    target.a[2][2] = 5;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    Matrix start;
    char ch;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ch;
            start.a[i][j] = ch - '0';
        }
    }
    q.push({start, 0});
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        if (!h(now.matrix))
        {
            cout << now.g << endl;
            break;
        }
        int r, c;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!now.matrix.a[i][j])
                {
                    r = i;
                    c = j;
                }
            }
        }
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if (judge(nr, nc))
            {
                swap(now.matrix.a[r][c], now.matrix.a[nr][nc]);
                if (!s.count(now.matrix))
                {
                    s.insert(now.matrix);
                    q.push({now.matrix, now.g + 1});
                }
                swap(now.matrix.a[r][c], now.matrix.a[nr][nc]);
            }
        }
    }
    //system("pause");
    return 0;
}