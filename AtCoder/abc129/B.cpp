#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w[105];
    int sum[105];
    int n;
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum[i] = sum[i - 1] + w[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, abs(sum[n] - sum[i] - sum[i]));
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}