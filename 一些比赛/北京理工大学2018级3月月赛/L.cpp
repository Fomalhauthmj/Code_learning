#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1E5 + 50;
int n, m;
#define pii pair<int, int>
pii task[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int casenum = 0;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> task[i].first;
        for (int i = 1; i <= n; i++)
            cin >> task[i].second;
        sort(task + 1, task + 1 + n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (m >= task[i].second)
            {
                cnt++;
                m -= task[i].second;
            }
            else
                break;
        }
        cout << "Case " << ++casenum << ": " << cnt << endl;
    }
    //system("pause");
    return 0;
}