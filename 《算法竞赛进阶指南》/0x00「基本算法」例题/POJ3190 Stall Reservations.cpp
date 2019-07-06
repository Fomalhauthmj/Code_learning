#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define ll long long
const int N = 5E4 + 50;
struct cow
{
    int start, end, id;
    bool operator<(const cow &n) const
    {
        return start < n.start;
    }
};
int ans[N];
cow cs[N];
int n;
struct node
{
    int cur_cow;
    node(int i) : cur_cow(i) {}
    node(){}
    bool operator<(const node &n) const
    {
        return cs[cur_cow].end > cs[n.cur_cow].end;
    }
};
priority_queue<node> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cs[i].start >> cs[i].end;
        cs[i].id = i;
    }
    sort(cs, cs + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        node cur;
        if (!q.empty())
        {
            cur = q.top();
            q.pop();
            //cout<<"cur top id"<<cs[cur.cur_cow].id<<endl;
            if (cs[i].start > cs[cur.cur_cow].end)
            {
                ans[cs[i].id] = ans[cs[cur.cur_cow].id];
                //cout<<cs[v[j].cur_cow].id<<"->"<<cs[i].id<<endl;
                cur.cur_cow = i;
                flag = true;
            }
            q.push(cur);
        }
        if (!flag)
        {
            q.push(node(i));
            ans[cs[i].id] = ++cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    //system("pause");
    return 0;
}