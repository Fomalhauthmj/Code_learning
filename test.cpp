#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
#define ll long long
const int mod = 1e9 + 7;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("data.in", "r", stdin);
    freopen("data.ans", "w", stdout);
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == 'A')
            a[i + 1] = true;
    while (q--)
    {
        int c, l, r;
        ll A, B;
        cin >> c >> l >> r;
        if (c == 1)
        {
            for (int i = l; i <= r; i++)
                a[i] ^= 1;
        }
        else
        {
            cin >> A >> B;
            for (int i = l; i <= r; i++)
            {
                if (a[i])
                    A += B, A %= mod;
                else
                    B += A, B %= mod;
            }
            cout << A << " " << B << endl;
        }
    }
    //system("pause");
    return 0;
}