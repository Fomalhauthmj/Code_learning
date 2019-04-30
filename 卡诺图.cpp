#include <iostream>
using namespace std;
bool fun(bool a, bool b, bool c, bool d)
{
    //return !b * !d + !a * !d + !c * !d + a * c * !d;
    //return !b * d + c * d + !a * !c * d + a * b * d;
    return (a * !b + !a * b) * !c + !((a * !b + !a * b) * c);
    //return !(a * b + b * c + a * c) * (a + b + c) + a * b * c;
}
int b[16] = {0, 4, 12, 8, 1, 5, 13, 9, 3, 7, 15, 11, 2, 6, 14, 10};
int main()
{
    int a[4][4];
    for (int i = 0; i < 16; i++)
    {
        a[i / 4][i % 4] = fun((i >> 3)&1, (i >> 2)&1, (i >> 1)&1, i&1);
    }
    for (int i = 0; i < 16; i++)
    {
        cout << a[b[i] / 4][b[i] % 4] << " ";
        if(i%4==3)
            cout << endl;
    }
}