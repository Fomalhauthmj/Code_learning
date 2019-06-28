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
    system("pause");
    return 0;
}