#include <iostream>
#include <set>
using namespace std;
#define N 100010
long long s[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int q;
    cin >> q;
    long long l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        set<long long> s;
        for (int j = 0; j < n; j++)
        {
            s.insert(s[j] + l);
            s.insert(s[j] + r);
        }
    }
    cout << endl;
    system("pause");
    return 0;
}