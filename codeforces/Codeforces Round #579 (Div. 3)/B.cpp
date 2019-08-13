#include <algorithm>
#include <iostream>
using namespace std;
const int N = 105;
int a[N * 4], q, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= 4 * n; i++)
            cin >> a[i];
        bool flag = true;
        sort(a + 1, a + 1 + 4 * n);
        int pre = 0;
        for (int i = 1; i <= n; i++)
        {
            int t1 = a[i * 2 - 1], t2 = a[i * 2], t3 = a[4 * n - (i - 1) * 2 - 1], t4 = a[4 * n - (i - 1) * 2];
            if (t1 * t4 != t2 * t3 || (t1 * t4 != pre && pre) || (t2 * t3 != pre && pre))
            {
                flag = false;
                break;
            }
            else
            {
                if(t1!=t2||t3!=t4)
                {
                    flag=false;
                    break;
                }
                else pre=t1*t4;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    //system("pause");
    return 0;
}