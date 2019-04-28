#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    long long n, a, b;
    long long ans;
    while(q--)
    {
        cin >> n >> a >> b;
        ans = 0;
        if(b<=2*a)
        {
            ans += n / 2 * b;
            n %= 2;
            ans += a*n;
        }
        else
        {
            ans = n * a;
        }
        cout << ans << endl;
    }
}