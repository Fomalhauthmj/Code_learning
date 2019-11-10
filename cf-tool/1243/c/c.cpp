/* 
 * Author: Hemengjie
 * Time: 2019-11-09 09:38:25
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
vector<pii> p;
void Prime(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            pii temp = {i, 0};
            while (n % i == 0)
                n /= i, temp.second++;
            p.push_back(temp);
        }
    }
    if (n > 1)
        p.push_back({n, 1});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    Prime(n);
    if (p.size() == 1)
    {
        cout << p[0].first << endl;
    }
    else
        cout << 1 << endl;
    //system("pause");
    return 0;
}