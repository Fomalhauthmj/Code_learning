#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
string str;
ll k;
int chs[26];
ll fac[17];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 16; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
}
ll get_num()
{
    ll a = 0;
    ll b = 1;
    for (int i = 0; i < 26; i++)
    {
        a += chs[i], b *= fac[chs[i]];
    }
    return fac[a] / b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while (cin >> str >> k)
    {
        memset(chs, 0, sizeof(chs));
        for (auto ch : str)
        {
            chs[ch - 'A']++;
        }
        int len = str.length();
        ll cur_k = 0;
        int ans[16];
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (chs[j]) //枚举
                {
                    chs[j]--;
                    ll t = get_num();
                    if (cur_k + t >= k)
                    {
                        ans[i] = j;
                        break;
                    }
                    chs[j]++;
                    cur_k += t;
                }
            }
        }
        for (int i = 0; i < len; i++)
            cout << (char)(ans[i] + 'A');
        cout << endl;
    }
    return 0;
}