#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
#define N 105
int n;
char tri[N][N];
struct node
{
    char a, b, c;
    node(char aa, char bb, char cc)
    {
        char temp[3];
        temp[0] = aa;
        temp[1] = bb;
        temp[2] = cc;
        sort(temp, temp + 3);
        a = temp[0];
        b = temp[1];
        c = temp[2];
    }
    bool operator<(node n) const
    {
        if (a != n.a)
            return a > n.a;
        if (b != n.b)
            return b > n.b;
        if (c != n.c)
            return c > n.c;
        return false;
    };
};
set<node> S;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(tri, 0, sizeof(tri));
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    //int cnt = 0;
    for (int d = 1; d <= n; d++)
    {
        for (int start = 1; start <= d; start++)
        {
            for (int r = 1; d + r <= n + 1; r++)
            {
                //cout << tri[d][start] << " " << tri[d + r][start] << " " << tri[d + r][start + r] << endl;
                S.insert(node(tri[d + r][start + r], tri[d][start], tri[d + r][start]));
                //cnt++;
            }
        }
    }
    for (int d = 2; d <= n; d++)
    {
        for (int start = d; start >= 1; start--)
        {
            for (int r = 1; d + r <= n + 1 && r < start; r++)
            {
                //cout << tri[d][start - r] << " " << tri[d][start] << " " << tri[d + r][start] << endl;
                S.insert(node(tri[d][start - r], tri[d][start], tri[d + r][start]));
                //cnt++;
            }
        }
    }
    //cout << cnt << endl;
    cout << S.size() << endl;
    /*
    for (auto ele : S)
    {
        cout << ele.a << ele.b << ele.c << endl;
    }
    */
    //system("pause");
    return 0;
}
/*
2
a
bb
cac
*/