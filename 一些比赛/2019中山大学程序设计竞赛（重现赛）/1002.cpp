#include <algorithm>
#include <iostream>
using namespace std;
#define N 5000005
#define LL long long
int n, a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, flag;
    LL num1, num2, num3;
    while (cin >> n)
    {
        flag = 0;
        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        for (i = n - 1; i >= 2; --i)
        {
            num1 = a[i], num2 = a[i - 1];
            if (num1 >= (num2 << 1))
                continue;
            num3 = a[i - 2];
            if (num1 < num2 + num3)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}