#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9;
int random(int n)
{
    return (ll)rand() * rand() % n;
}
int main()
{
    freopen("data.in", "w", stdout);
    srand((unsigned)time(0));
    int n = 100000;
    int cases = 100000;
    cout << n << " " << cases << endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%c", 'A' + random(2));
    }
    cout << endl;
    for (int i = 1; i <= cases; i++)
    {
        int casenum = random(2);
        if (casenum)
        {
            int rdm1 = random(n) + 1;
            int rdm2 = random(n) + 1;
            if (rdm1 > rdm2)
                swap(rdm1, rdm2);
            cout << 1 << " " << rdm1 << " " << rdm2 << endl;
        }
        else
        {
            int rdm1 = random(n) + 1;
            int rdm2 = random(n) + 1;
            if (rdm1 > rdm2)
                swap(rdm1, rdm2);
            int A = random(inf);
            int B = random(inf);
            cout << 2 << " " << rdm1 << " " << rdm2 << " " << A << " " << B << endl;
        }
    }
    //system("pause");
    return 0;
}