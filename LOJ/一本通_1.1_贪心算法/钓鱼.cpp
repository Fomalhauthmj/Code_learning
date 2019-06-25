#include <iostream>
#include <queue>
using namespace std;
const int N = 105;
int n, h;
int f[N];
int d[N];
int t[N];
int sum_t[N];
void Input()
{
    cin >> n >> h;
    h *= 60;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sum_t[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> t[i];
        sum_t[i + 1] = sum_t[i] + t[i];
    }
}
struct node
{
    int f;
    int d;
    node(int ff, int dd) : f(ff), d(dd)
    {
    }
    bool operator<(const node &n) const
    {
        return f < n.f;
    }
};
priority_queue<node> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Input();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp_h = h - sum_t[i] * 5;
        while (!q.empty())
            q.pop();
        for (int j = 0; j <= i; j++)
        {
            q.push(node(f[j], d[j]));
        }
        int temp_ans = 0;
        int cnt = temp_h / 5;
        while (cnt > 0 && !q.empty())
        {
            node now = q.top();
            if (now.f <= 0)
                break;
            temp_ans += now.f;
            q.pop();
            q.push(node(now.f - now.d, now.d));
            cnt--;
        }
        ans = max(ans, temp_ans);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}