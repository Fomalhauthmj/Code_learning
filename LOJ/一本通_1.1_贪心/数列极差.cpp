#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
priority_queue<ll, vector<ll>, greater<ll> > q1;
priority_queue<ll, vector<ll>, less<ll> > q2;
ll Solve()
{
    ll MAX, MIN;
    while (!q1.empty())
    {
        ll e1 = q1.top();
        q1.pop();
        if (q1.empty())
        {
            MAX = e1;
            break;
        }
        else
        {
            ll e2 = q1.top();
            q1.pop();
            q1.push(e1 * e2 + 1);
        }
    }
    while (!q2.empty())
    {
        ll e1 = q2.top();
        q2.pop();
        if (q2.empty())
        {
            MIN = e1;
            break;
        }
        else
        {
            ll e2 = q2.top();
            q2.pop();
            q2.push(e1 * e2 + 1);
        }
    }
    return MAX - MIN;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        q1.push(num);
        q2.push(num);
    }
    cout << Solve() << endl;
    //system("pause");
    return 0;
}