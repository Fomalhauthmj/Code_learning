#include <iostream>
#include <map>
using namespace std;
#define N 1010
int n;
int a[N]; //各不相同
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                m[a[i] + a[j]]++;
            }
        }
        int ans = 0;
        for (auto ele : m)
        {
            //cout << ele.first << " " << ele.second << endl;
            ans = max(ans, ele.second); //为什么？
        }
        cout << ans << endl;
    }
}