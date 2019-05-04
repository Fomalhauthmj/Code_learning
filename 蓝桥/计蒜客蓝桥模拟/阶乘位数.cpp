#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double ans = 0;
    for (int i = 1;; i++)
    {
        ans += log10(i);
        if (ans > 10000)
        {
            cout << i << endl; //log10(n!)=log10(1)+log10(2)+...+log10(n);
            break;
        }
    }
    //斯特林公式
    /*
    log10(n!) 
    =log10(sqrt(2∗pi∗n))+n∗log10(n/e)
    */
    double pi = acos(-1);
    double e = 2.7182818284590452354;
    for (int i = 1;; i++)
    {
        double ans = log10(sqrt(2 * pi * i)) + i * log10(i * 1.0 / e);
        if (ans >= 10000)
        {
            cout << i << endl;
            break;
        }
    }
    system("pause"); //3249
}