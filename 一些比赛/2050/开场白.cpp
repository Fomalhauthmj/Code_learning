#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    string str;
    long long mod = 2050;
    while (T--)
    {
        cin >> str;
        long long res = 0;
        for (int i = 0; i < str.length(); i++)
        {
            res = ((res * 10) % mod + (str[i] - '0') % mod) % mod;
        }
        //大数求余
        if (res == 0)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    //system("pause");
    return 0;
}