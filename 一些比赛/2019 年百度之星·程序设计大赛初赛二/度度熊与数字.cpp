#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int v;
        cin >> v;
        int sum = 0;
        int temp = v;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        int cnt = 0;
        vector<int> ans;
        for (int i = 1; i <= sum; i++)
        {
            if (sum % i == 0 && v % i == 0)
                cnt++, ans.push_back(i);
        }
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
            if (i != cnt - 1)
                cout << ans[i] << " ";
            else
                cout << ans[i] << endl;
    }
    //system("pause");
    return 0;
}