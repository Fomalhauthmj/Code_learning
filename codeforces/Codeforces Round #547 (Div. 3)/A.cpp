#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    if (m % n != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int temp1 = 0;
        //获得m的2 3因子指数
        while (m % 2 == 0)
        {
            temp1++;
            m /= 2;
        }
        while (m % 3 == 0)
        {
            temp1++;
            m /= 3;
        }
        int temp2 = 0;
        //获得n的2 3 因子指数
        while (n % 2 == 0)
        {
            temp2++;
            n /= 2;
        }
        while (n % 3 == 0)
        {
            temp2++;
            n /= 3;
        }
        if (m != n)
        {
            cout << -1 << endl;
        }
        else
            cout << temp1 - temp2 << endl;
    }
    system("pause");
    //return 0;
}