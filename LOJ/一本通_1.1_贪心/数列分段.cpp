#include <iostream>
using namespace std;
long long n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long ans = 0;
    long long cur = 0;
    long long num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (cur + num > m)
        {
            ans++;
            cur = num;
        }
        else
            cur += num;
    }
    if (cur)
        ans++;
    cout << ans << endl;
    //system("pause");
    return 0;
}