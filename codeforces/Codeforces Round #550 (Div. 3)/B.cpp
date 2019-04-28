#include <algorithm>
#include <iostream>
using namespace std;
#define N 2020
long long a[N];
int n;
long long oa[N];
long long ea[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int even = 0;
    int odd = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
        if (a[i] & 1)
        {
            oa[odd++] = a[i];
        }
        else
            ea[even++] = a[i];
    }
    sort(oa, oa + odd, greater<long long>());
    sort(ea, ea + even, greater<long long>());
    int cnt = min(odd, even);
    for (int i = 0; i < cnt; i++)
    {
        ans -= oa[i];
        ans -= ea[i];
    }
    if (odd > even)
    {
        ans -= oa[cnt];
    }
    else
    {
        ans -= ea[cnt];
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}