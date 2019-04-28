#include <iostream>
using namespace std;
#define N 100010
int n;
long long a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        long long max_value = -1;
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
            if(a[i]>max_value)
                max_value = a[i];//寻找最大值
        }
        int ans = 1;
        int temp = 1;
        long long pre = -1;
        for (int i = 0; i < n; i++)
        {
            if(a[i]==max_value&&pre!=max_value)
            {
                ans = max(ans, temp);
                temp=1;
            }
            else if(a[i]==max_value&&pre==max_value)
            {
                temp++;
            }
            pre = a[i];
        }
        ans = max(ans, temp);
        cout << ans << endl;
    }
}