#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1010;
int n, d;
struct node
{
    double left, right;
    node() {}
    node(int xx, int yy)
    {
        double temp = sqrt(d * d - yy * yy);
        left = xx - temp;
        right = xx + temp;
    }
    bool operator<(const node &n) const
    {
        if (left != n.left)
            return left < n.left;
        return right < n.right;
    }
};
node p[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("New10.in", "r", stdin);
    //freopen("output", "w", stdout);
    int casenum = 0;
    while (cin >> n >> d && n + d)
    {
        int x, y;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if(y>d)
            {
                flag = false;
            }
            p[i] = node(x, y);
        }
        if(!flag)
        {
            cout << "Case " << ++casenum << ": " << -1 << endl;
            continue;
        }
        sort(p, p + n);
        int ans = 0;
        double cur = -inf;
        for (int i = 0; i < n; i++)
        {
            if (p[i].left > cur)
            {
                cur = p[i].right;
                ans++;
            }
            else
                cur = min(p[i].right, cur);
        }
        cout << "Case " << ++casenum << ": " << ans << endl;
    }
    //system("pause");
    return 0;
}