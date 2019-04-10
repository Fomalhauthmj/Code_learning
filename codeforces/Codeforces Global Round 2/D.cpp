#include <algorithm>
#include <iostream>
using namespace std;
#define N 100010
long long s[N];
int n;
long long counting(long long left, long long right)
{
    //cout << left << " " << right << endl;
    long long mid = (left + right) >> 1;
    if ()
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n);
    int cnt = unique(s, s + n) - s;
    int q;
    cin >> q;
    long long l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
    }
    cout << endl;
    system("pause");
    return 0;
}