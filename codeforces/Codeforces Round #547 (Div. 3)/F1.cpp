#include <iostream>
using namespace std;
#define N 55
long long a[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    //找出最大的区块数
}