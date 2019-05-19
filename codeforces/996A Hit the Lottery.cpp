//!:http://codeforces.com/problemset/problem/996/A
#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int a[] = {1, 5, 10, 20, 100};
    while(cin>>n)
    {
        long long ans = 0;
        for (int i = 4; i >= 0;i--)
        {
            while (n / a[i])
            {
                ans += n / a[i];
                n = n - a[i] * (n / a[i]);
            }
        }
        cout << ans << endl;
    }
}