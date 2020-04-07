#include <bits/stdc++.h>
using namespace std;
struct node
{
    double c;
    int e;
    bool operator<(const node &n) const
    {
        return e > n.e;
    }
} a[15], b[15], c[40];
int main()
{
    int k1, k2, k3;
    cin >> k1;
    for (int i = 0; i < k1; i++)
        cin >> a[i].e >> a[i].c;
    cin >> k2;
    for (int i = 0; i < k2; i++)
        cin >> b[i].e >> b[i].c;
    k3 = 0;
    int i = 0, j = 0;
    while (i < k1 && j < k2)
    {
        if (a[i].e == b[j].e)
        {
            c[k3].e = a[i].e;
            c[k3].c = a[i].c + b[j].c;
            i++, j++;
            if (c[k3].c != 0)
                k3++;
        }
        else if (a[i].e > b[j].e)
        {
            c[k3] = a[i];
            i++;
            if (c[k3].c != 0)
                k3++;
        }
        else if (a[i].e < b[j].e)
        {
            c[k3] = b[j];
            j++;
            if (c[k3].c != 0)
                k3++;
        }
    }
    while (i < k1)
    {
        c[k3] = a[i];
        i++;
        if (c[k3].c != 0)
            k3++;
    }
    while (j < k2)
    {
        c[k3] = b[j];
        j++;
        if (c[k3].c != 0)
            k3++;
    }
    cout << k3;
    cout.precision(1);
    for (int i = 0; i < k3; i++)
        cout << " " << c[i].e << " " << fixed << c[i].c;
    cout << endl;
    //system("pause");
    return 0;
}