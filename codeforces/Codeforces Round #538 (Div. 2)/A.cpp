#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z, a, b, c;
    //a green b purple c black
    //x green y green/purple z all
    while (cin >> x >> y >> z >> a >> b >> c)
    {
        if (a < x)
        {
            cout << "NO" << endl;
            continue;
        }
        else
            a -= x;
        int remain;
        if (a + b < y)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            remain = a + b - y;
        }
        if (remain + c < z)
        {
            cout << "NO" << endl;
            continue;
        }
        else
            cout << "YES" << endl;
    }
}