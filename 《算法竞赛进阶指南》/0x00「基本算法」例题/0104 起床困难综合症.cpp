#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
const ll N = 1E5 + 50;
ll n, m;
struct node
{
    int op;
    ll t;
    node(int i1, ll i2) : op(i1), t(i2) {}
    node() {}
};
node ns[N];
ll calc(int bit, int now)
{
    for (int i = 0; i < n; i++)
    {
        int x = (ns[i].t >> bit) & 1;
        if (ns[i].op == -1)
            now &= x;
        else if (ns[i].op == 0)
            now |= x;
        else
            now ^= x;
    }
    return now;
}
ll Solve()
{
    ll val, ans;
    val = 0;
    ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        int t0 = calc(i, 0);
        int t1 = calc(i, 1);
        if ((val + (1 << i)) <= m && t0 < t1)
        {
            /*
            注意这里的t0<t1
            当t0=t1=1时 对于后续选择来说 更优的是给当前位赋0 给后续选择留出更大的空间
            */
            ans += (1 << i);
            val += (1 << i);
        }
        else
            ans += (t0 << i);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    string str;
    ll num;
    for (int i = 0; i < n; i++)
    {
        cin >> str >> num;
        if (str[0] == 'A')
            ns[i] = node(-1, num);
        else if (str[0] == 'O')
            ns[i] = node(0, num);
        else if (str[0] == 'X')
            ns[i] = node(1, num);
    }
    cout << Solve() << endl;
    //system("pause");
    return 0;
}