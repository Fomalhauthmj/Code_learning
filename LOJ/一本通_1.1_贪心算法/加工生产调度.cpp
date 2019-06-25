#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1050;
int n;
#define A 0
#define B 1
struct node
{
    int id, tag, time;
    node(int i1, int i2, int i3) : id(i1), tag(i2), time(i3)
    {
    }
    node()
    {
    }
    bool operator<(const node &n) const
    {
        return time < n.time;
    }
};
node ns[N];
int a[N], b[N];
int ans[N];
int sum[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            ns[i] = node(i, B, b[i]);
        }
        else
            ns[i] = node(i, A, a[i]);
    }
    sort(ns, ns + n);
    int lpos = 0;
    int rpos = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (ns[i].tag == A)
        {
            ans[lpos++] = ns[i].id;
        }
        else
        {
            ans[rpos--] = ns[i].id;
        }
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[ans[i - 1]];
    int answer = sum[1] + b[ans[0]];
    for (int i = 2; i <= n; i++)
    {
        answer = max(answer, sum[i]) + b[ans[i - 1]];
    }
    cout << answer << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << ans[i] + 1 << endl;
        else
            cout << ans[i] + 1 << " ";
    }
    //system("pause");
    return 0;
}