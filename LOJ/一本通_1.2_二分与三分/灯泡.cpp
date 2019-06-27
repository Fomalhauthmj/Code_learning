#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    double H, h, D;
    while (t--)
    {
        cin >> H >> h >> D;
        double x = sqrt(D * (H - h));
        if (x > (H - h) * D / H && x < D)
            cout << fixed << setprecision(3) << D + H - 2.0 * x << endl;
        else
        {
            if (x >= D)
                cout << fixed << setprecision(3) << h << endl;
            else
                cout << fixed << setprecision(3) << D * h / H << endl;
        }
    }
    //system("pause");
    return 0;
}