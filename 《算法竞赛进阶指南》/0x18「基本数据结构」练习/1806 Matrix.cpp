/*
 * File Created: Saturday, 20th July 2019 4:56:05 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Saturday, 20th July 2019 5:00:15 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <map>
using namespace std;
#define P 131
#define Q 13331
#define ull unsigned long long
const int N = 1010;
int m, n, a, b;
ull p[N], q[N];
ull Hash_a[N][N], Hash_b[N][N];
map<ull, bool> M;
void Init()
{
    p[0] = q[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P, q[i] = q[i - 1] * Q;
}
ull Hash()
{
    char ch;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> ch, Hash_b[i][j] = Hash_b[i][j - 1] * P+ch;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            Hash_b[i][j] += Hash_b[i - 1][j] * Q;
    return Hash_b[a][b];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Init();
    cin >> m >> n >> a >> b;
    char ch;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> ch, Hash_a[i][j] = Hash_a[i][j - 1] * P+ch;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            Hash_a[i][j] += Hash_a[i - 1][j] * Q;
    for (int i = a; i <= m; i++)
        for (int j = b; j <= n; j++)
        {
            ull temp = Hash_a[i][j] - Hash_a[i - a][j] * q[a] - Hash_a[i][j - b] * p[b] + Hash_a[i - a][j - b] * q[a] * p[b];
            M[temp] = 1;
        }
    int test;
    cin >> test;
    while (test--)
    {
        ull key = Hash();
        if (M.count(key))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    //system("pause");
    return 0;
}