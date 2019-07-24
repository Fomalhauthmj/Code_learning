//http://codeforces.com/contest/821/problem/C
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int N = 3E5 + 50;
int n;
stack<int> s;
// 模拟排序 n^2logn TLE
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, num;
    cin >> n;
    string str;
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> str;
        if (str[0] == 'a')
        {
            cin >> num;
            s.push(num);
        }
        else
        {
            if (s.size() && s.top() == cur)
            {
                s.pop();
                cur++;
            }
            else if (s.size())
            {
                while (!s.empty())
                    s.pop();
                ans++;
                cur++;
            }
            else if (s.empty())
                cur++;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}