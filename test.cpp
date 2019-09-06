#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll str, inte, exp;
        cin >> str >> inte >> exp;
        if (exp == 0)
        {
            if (str > inte)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }
        ll key = str - inte;
        ll a1 = (exp - key) / 2 ;
        if(exp-key>=0) a1++;
        if (a1 <= exp)
        {
            if (a1 < 0)
                a1 = 0;
            cout << exp - a1 + 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    //system("pause");
    return 0;
}