#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define pii pair<int, int>
int n, m;
int d[27][27], temp[27][27];
int Judge()
{
    memcpy(temp, d, sizeof(temp));
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                temp[i][j] |= temp[i][k] & temp[k][j];
                if (temp[i][j] && temp[j][i])
                    return 0;
                //WA  放在这里判断
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (!temp[i][j] && !temp[j][i])
                return 1; //未确定
        }
    }
    return 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a, b, c;
    while (cin >> n >> m && n + m)
    {
        bool flag = true;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b >> c;
            d[a - 'A' + 1][c - 'A' + 1] = 1;
            if (flag)
            {
                int ret = Judge();
                if (ret == 0)
                {
                    cout << "Inconsistency found after " << i << " relations." << endl;
                    flag = false;
                }
                else if (ret == 2)
                {
                    cout << "Sorted sequence determined after " << i << " relations: ";
                    pii cnt[27];
                    for (int i = 1; i <= n; i++)
                    {
                        cnt[i].second = i - 1;
                        for (int j = i + 1; j <= n; j++)
                        {
                            if (temp[i][j])
                                cnt[j].first++;
                            else if (temp[j][i])
                                cnt[i].first++;
                        }
                    }
                    sort(cnt + 1, cnt + 1 + n);
                    for (int i = 1; i <= n; i++)
                        cout << char(cnt[i].second + 'A');
                    cout << '.' << endl;
                    flag = false;
                }
            }
        }
        if (flag)
            cout << "Sorted sequence cannot be determined." << endl;
    }
    //system("pause");
    return 0;
}