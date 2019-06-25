#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int N = 15050;
int n, l, w;
struct node
{
    int o, r;
    double line;
    double left, right;
    node(int oo, int rr) : o(oo), r(rr)
    {
        line = sqrt(1.0 * r * r - 1.0 * w * w / 4.0);
        left = o - line;
        if (left < 0)
            left = 0;
        right = o + line;
        if (right > l)
            right = l;
        //cout << "calc:" << left << " " << right << " " << line << endl;
    }
    bool operator<(const node &n) const
    {
        if (left != n.left)
            return left < n.left;
        return right > n.right;
    }
};
vector<node> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int o, r;
    while (T--)
    {
        cin >> n >> l >> w;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> o >> r;
            if (2 * r > w)
                v.push_back(node(o, r));
        }
        sort(v.begin(), v.end());
        bool can_finish = true;
        int ans = 1;
        double cur = v.front().right;
        int len = v.size();
        double temp = 0;
        for (int i = 1; i < len; i++)
        {
            if (v[i].left < cur)
            {
                temp = max(temp, v[i].right);
            }
            else
            {
                cur = temp;
                ans++;
                if (cur < v[i].left)
                {
                    can_finish = false;
                    break;
                }
                else
                    temp = v[i].right;
            }
            //cout << "cur " << cur << " " << ans << endl;
        }
        if (temp < l || !can_finish)
        {
            cout << -1 << endl;
        }
        else if (cur >= l)
            cout << ans << endl;
        else if (cur < l)
            cout << ans + 1 << endl;
    }
    //system("pause");
    return 0;
}