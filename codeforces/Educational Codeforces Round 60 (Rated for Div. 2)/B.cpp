#include<iostream>
#include<algorithm>
using namespace std;
#define N 200020
long long n, m, k;
long long a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m>>k)
    {
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long max_value = a[n - 1];
        long long sub_value = a[n - 2];
        long long sum = 0;
        sum = m / (k + 1) * (max_value * k + sub_value) + m % (k + 1) * max_value;
        cout << sum << endl;
    }
}