#include <iostream>
#include <vector>
using namespace std;
#define N 1e6 + 5
int n;
void Test()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vector<int> a(n + 1);
        for (int left = 1; left <= i; left++)
        {
            for (int right = left; right <= i; right++)
            {
                int pos = left;
                for (int len = right - left + 1; len >= 1; len--)
                {
                    a[pos++] += len;
                }
            }
        }
        cout << "Cur:" << i << endl;
        vector<int> b(i + 1);
        for (int k = 1; k <= i; k++)
        {
            //等差求和  (i-k+1)(i-k+2)/2
            b[k] = k * (i - k + 1) * (i - k + 2) / 2;
            //O(n)
            /*
            for (int kk = 1; kk <= i - k + 1; kk++)
            {
                b[k] += k * kk;
            }
            */
        }
        cout << "right:" << endl;
        for (int k = 1; k <= i; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
        cout << "guess:" << endl;
        for (int k = 1; k <= i; k++)
        {
            cout << b[k] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    long long ai;
    long long ans = 0;
    long long mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        cin >> ai;
        ans += ai * i * (n - i + 1) * (n - i + 2) / 2;
        //ans %= mod;
        //取模与溢出 预处理？
    }
    cout << ans << endl;
    system("pause");
}