#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        int val = i;
        while (val)
        {
            temp += (val % 10) * (val % 10);
            val /= 10;
        }
        if (temp == m)
            ans++;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}