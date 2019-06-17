#include <iostream>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll n, p, m;
const ll N = 505;
ll m1[N][N];
ll m2[N][N];
ll m3[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            cin >> m1[i][j];
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> m2[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                m3[i][j] = (m3[i][j] + m1[i][k] * m2[k][j]) % mod;
                if (m3[i][j] < 0)
                    m3[i][j] += mod;
            }
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}