#include <iostream>
using namespace std;
#define inf 1e16
long long n, m, k;
long long a, b, c;
long long two_or_three(int p)
{
    long long ans = inf;
    for (int i = 0; i <= p / 3 + 1; i++)
    {
        int rest = p - 3 * i;
        int add = 0;
        long long temp = i * b;
        if (temp > ans)
            continue;
        if (rest > 0)
        {
            add = rest / 2 + ((rest % 2 != 0) ? 1 : 0);
            temp += add * a;
        }
        //cout << "3:" << i << " 2:" << add <<" temp:"<<temp<<endl;
        ans = min(ans, temp);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        cin >> a >> b >> c;
        long long ans = inf;
        for (int i = 0; i <= k; i++)
        {
            long long temp = c * i;
            if (temp > ans)
                continue;
           // cout << "p:" << i << " pt:" << temp << endl;
            temp += two_or_three(n + k - i);
            temp += two_or_three(m + k - i);
            ans = min(ans, temp);
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}