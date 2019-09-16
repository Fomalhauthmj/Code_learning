#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define ui unsigned int
ui seed, lastans;
ui a[16][16 << 1], rev[16][16];
ui A[16][16], R[16][16];
ui base1[16], base2[16];
ui ret[16][16];
struct node
{
    ui matrix[16][16];
};
deque<node> q;
inline ui qpow(ui x, ui k)
{
    ui ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * x % 2;
        x = x * x % 2;
        k >>= 1;
    }
    return ans % 2;
}
inline void Gauss_j()
{
    for (int i = 0, r; i < 16; ++i)
    {
        r = i;
        for (int j = i + 1; j < 16; ++j)
            if (a[j][i] > a[r][i])
                r = j;
        if (r != i)
            swap(a[i], a[r]);
        int kk = qpow(a[i][i], 2 - 2); //求逆元
        for (int k = 0; k < 16; ++k)
        {
            if (k == i)
                continue;
            int p = a[k][i] * kk % 2;
            for (int j = i; j < (16 << 1); ++j)
                a[k][j] = ((a[k][j] - p * a[i][j]) % 2 + 2) % 2;
        }
        for (int j = 0; j < (16 << 1); ++j)
            a[i][j] = (a[i][j] * kk % 2);
        //更新当前行 如果放在最后要再求一次逆元,不如直接放在这里
    }
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 16; j < (16 << 1); ++j)
            rev[i][j - 16] = a[i][j];
    }
}
void Init()
{
    base1[0] = base2[0] = 1;
    for (int i = 1; i < 16; i++)
        base1[i] = base1[i - 1] * 17;
    for (int i = 1; i < 16; i++)
        base2[i] = base2[i - 1] * 19;
}
void Build()
{
    seed ^= lastans;
    for (int i = 0; i < 16; i++)
    {
        seed ^= seed * seed + 15;
        for (int j = 0; j < 16; j++)
            A[i][j] = (seed >> j) & 1;
    }
}
void Mul(ui m1[16][16], ui m2[16][16])
{
    memset(R, 0, sizeof(R));
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            for (int k = 0; k < 16; k++)
            {
                R[i][j] = (R[i][j] + m1[i][k] * m2[k][j]) % 2;
            }
        }
    }
}
ui Ret()
{
    ui ans = 0;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            ans += ret[i][j] * base1[i] * base2[j];
    }
    return ans;
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output1", "w", stdout);
    int T;
    scanf("%d", &T);
    Init();
    while (T--)
    {
        while (q.size())
            q.pop_front();
        int n;
        scanf("%d", &n);
        ui t;
        lastans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> seed;
            if (t == 1)
            {
                Build();
                node add;
                if (q.empty())
                    memcpy(ret, A, sizeof(ret));
                else
                {
                    Mul(A, ret);
                    memcpy(ret, R, sizeof(ret));
                }
                memcpy(add.matrix, A, sizeof(add.matrix));
                q.push_back(add);
            }
            else
            {
                if (q.size())
                {
                    memset(a, 0, sizeof(a));
                    for (int i = 0; i < 16; ++i)
                        for (int j = 0; j < 16; ++j)
                            a[i][j] = q.front().matrix[i][j], a[i][i + 16] = 1;
                    Gauss_j();
                    q.pop_front();
                    if (q.size() > 1)
                    {
                        Mul(ret, rev);
                        memcpy(ret, R, sizeof(ret));
                    }
                    else if (q.size() == 1)
                    {
                        memcpy(ret, q.back().matrix, sizeof(ret));
                    }
                }
            }
            ui ans = 0;
            if (q.size())
                ans = Ret();
            lastans = ans;
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}
