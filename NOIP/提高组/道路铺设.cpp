#include <iostream>
using namespace std;
const int N = 1E5 + 50;
#define ll long long
int n;
ll d[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (i == 0)
            ans = d[0];
        else if (d[i] > d[i - 1])
            ans += d[i] - d[i - 1];
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}