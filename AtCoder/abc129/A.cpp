#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, q, r;
    cin >> p >> q >> r;
    /*
    p:a->b
    q:b->c
    r:c->a
    */
    cout << min(p + q, min(p + r, q + r)) << endl;
    //system("pause");
    return 0;
}