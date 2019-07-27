#include <iostream>
#include <map>
using namespace std;
#define pii pair<int, int>
pii a[55], b[55], target;
int n, m, k,ans;
map<pii, bool> no;
bool Search(int apos, int bpos, int cnt, int x, int y)
{
    if (cnt >= ans)
        return false;
    if (no[make_pair(x, y)])
        return false;
    if (x == target.first && y == target.second)
    {
        ans = min(ans, cnt);
        return true;
    }
    if (apos > n && bpos > m)
    {
        if (x == target.first && y == target.second)
        {
            ans = min(ans, cnt);
            return true;
        }
        return false;
    }
    //两个都放
    Search(apos + 1, bpos + 1, cnt + 1, x + a[apos].first + b[bpos].first, y + a[apos].second + b[bpos].second);
    //两个都不放
    Search(apos + 1, bpos + 1, cnt, x, y);
    //普通放
    Search(apos + 1, bpos + 1, cnt, x + a[apos].first, y + a[apos].second);
    //稀有放
    Search(apos + 1, bpos + 1, cnt + 1, x + b[bpos].first, y + b[bpos].second);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++)
        cin >> b[i].first >> b[i].second;
    pii cnt;
    for (int i = 1; i <= k; i++)
        cin >> cnt.first >> cnt.second, no[cnt] = 1;
    cin >> target.first >> target.second;
    ans = 100;
    if (Search(1, 1, 0, 0, 0))
        cout << ans << endl;
    else
        cout << "impossible!" << endl;
    system("pause");
    return 0;
}