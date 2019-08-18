#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 205;
int sg[N][N];
int n, m;
int SG(int x, int y)
{
    if (sg[x][y] != -1)
        return sg[x][y];
    bool f[N];
    memset(f, 0, sizeof(f));
    for (int i = 2; i <= x - i; i++)//这里边界条件的限制易错
        f[SG(i, y) ^ SG(x - i, y)] = 1;
    for (int i = 2; i <= y - i; i++)
        f[SG(x, i) ^ SG(x, y - i)] = 1;
    int t = 0;
    while (f[t])
        t++;
    return sg[x][y] = t;
}
int main()
{
    memset(sg, -1, sizeof(sg));
    sg[2][2] = sg[2][3] = sg[3][2] = 0;
    while (scanf("%d%d", &n, &m) != EOF)
        cout << (SG(n, m) ? "WIN" : "LOSE") << endl;
    //system("pause");
    return 0;
}