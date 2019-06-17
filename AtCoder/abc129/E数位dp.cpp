#include <iostream>
#include <string>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll N = 1e5 + 5;
ll dp1[N]; //dp1[i] 已经确定前k位 同时已知A+B<=L
ll dp2[N]; //dp2[i] 已经确定前k位 同时未知是否符合
string l;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l;
    int len = l.length();
    dp1[0] = 0;
    dp2[0] = 1;
    for (int i = 0; i < len; i++)
    {
        if (l[i] == '0')
        {
            dp1[i + 1] = 3 * dp1[i] % mod;
            dp2[i + 1] = dp2[i];
        }
        else
        {
            dp1[i + 1] = (3 * dp1[i] + dp2[i]) % mod; // + 0 0
            dp2[i + 1] = (2 * dp2[i]) % mod;          //0 1  1 0
        }
    }
    cout << (dp1[len] + dp2[len]) % mod << endl;
    system("pause");
    return 0;
}