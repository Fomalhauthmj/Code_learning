#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 10000; i >= 2; i--)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "ans:" << i << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
//9973