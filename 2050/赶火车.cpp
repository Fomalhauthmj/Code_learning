#include <iostream>
#include <math.h>
using namespace std;
#define N 15
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n, m;
    double y;
    double ai;
    double bi;
    while (T--)
    {
        cin >> n >> m >> y;
        double sa = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ai;
            sa += ai;
        }
        double sb = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> bi;
            sb += bi;
        }
        int t = 30;
        double k = m * 1.0 / (n + m);
        double e = sa / (n + m);
        for (int i = 2; i < t; i++)
        {
            e += sb / (n + m) * i * pow(k, i - 1);
        }
        //cout << e << endl;
        if (e <= y)
        {
            cout << "Go" << endl;
        }
        else
            cout << "Wait" << endl;
    }
    //system("pause");
    return 0;
}