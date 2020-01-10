#include <iostream>
using namespace std;
#define ll long long
const int N = 1e5 + 50;
int a[N], n;
int pre[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    pre[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            int j = pre[i - 1];
            while (a[j] <= a[i])
                j = pre[j];
            pre[i] = j;
        }
        else if (a[i] == a[i - 1])
            pre[i] = pre[i - 1];
        else if (a[i] < a[i - 1])
            pre[i] = i - 1;
        ans += i - pre[i];
    }
    //for (int i = 1; i <= n; i++)
    //cout << pre[i] << " ";
    //cout << endl;
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
8
9 1 3 5 2 7 6 3
5
5 4 3 2 1
5
5 1 2 3 4
*/