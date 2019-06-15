#include <cstring>
#include <iostream>
using namespace std;
#define N 100050
const long long mod = 1e9 + 7;
/*
ways[i]=way[i-1]+way[i-2]
 */
int n, m;
bool broken[N];
long long ways[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int pos;
    memset(broken, 0, sizeof(broken));
    for (int i = 0; i < m; i++)
    {
        cin >> pos;
        broken[pos] = 1;
    }
    memset(ways, 0, sizeof(ways));
    if (!broken[1])
        ways[1] = 1;
    if (!broken[2])
        ways[2] = ways[1] + 1;
    for (int i = 3; i <= n; i++)
    {
        if (!broken[i])
            ways[i] = (ways[i - 1] + ways[i - 2]) % mod;
    }
    cout << ways[n] << endl;
    //system("pause");
    return 0;
}