#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1E6 + 10;
struct node
{
    int a, b;
    node(int aa, int bb) : a(aa), b(bb) {}
    bool operator<(const node &n) const
    {
        if (b != n.b)
            return b < n.b;
    }
};
vector<node> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(node(a, b));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cur = 0;
    for (auto it : v)
    {
        if (cur == 0)
        {
            cur = it.b;
            ans++;
        }
        else
        {
            if (it.a >= cur)
            {
                ans++;
                cur = it.b;
            }
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}