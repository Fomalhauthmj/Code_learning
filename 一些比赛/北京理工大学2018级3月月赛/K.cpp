#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define P 131
#define Q 13331
#define N 1010
#define M 105
#define ull unsigned long long
int a, b, c, d;
char ori[N][N], key[M][M];
ull p[N], q[N], Hash_ori[N][N], Hash_key[M][M];
map<ull, bool> exist;
void Init()
{
    p[0] = q[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P, q[i] = q[i - 1] * Q;
    memset(Hash_ori, 0, sizeof(Hash_ori));
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            Hash_ori[i][j] = Hash_ori[i][j - 1] * P + ori[i][j];
    for (int j = 1; j <= b; j++)
        for (int i = 1; i <= a; i++)
            Hash_ori[i][j] += Hash_ori[i - 1][j] * Q;
    for (int i = c; i <= a; i++)
    {
        for (int j = d; j <= b; j++)
        {
            ull temp = Hash_ori[i][j] - q[c] * Hash_ori[i - c][j] - p[d] * Hash_ori[i][j - d] + Hash_ori[i - c][j - d] * p[d] * q[c];
            exist[temp] = 1;
        }
    }
}
ull Hash()
{
    memset(Hash_key, 0, sizeof(Hash_key));
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= d; j++)
            Hash_key[i][j] = Hash_key[i][j - 1] * P + key[i][j];
    for (int j = 1; j <= d; j++)
        for (int i = 1; i <= c; i++)
            Hash_key[i][j] += Hash_key[i - 1][j] * Q;
    return Hash_key[c][d];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> ori[i][j];
    Init();
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= d; j++)
                cin >> key[i][j];
        ull k = Hash();
        if (exist[k] == 1)
        {
            cout << "known" << endl;
        }
        else
            cout << "new" << endl;
    }
    //system("pause");
    return 0;
}