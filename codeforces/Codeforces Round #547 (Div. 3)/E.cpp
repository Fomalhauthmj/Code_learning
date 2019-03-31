#include <iostream>
using namespace std;
#define N 200020
long long d[N];
int n;
long long H;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> n;
    long long min_pre = 0;
    long long temp = H;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sum += d[i];
        temp += d[i];
        if (temp <= 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
        min_pre = min(min_pre, sum);
    }
    if (sum >= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    long long count = (H + min_pre) / -sum;
    //这里要预留出一部分H给负最大的前缀和
    //而不是负最大的d[i]
    long long ans = count * n;
    H += count * sum;
    for (int i = 0;; i++)
    {
        H += d[i % n];
        ans++;
        if (H <= 0)
        {
            break;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}