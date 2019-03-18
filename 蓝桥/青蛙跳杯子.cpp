#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
struct node
{
    string str;
    int pos;
    int step;
    node(string s, int p, int n) : str(s), pos(p), step(n) {}
};
int mod(int len, int i)
{
    while (i < 0)
        i += len;
    return i % len;
}
int findpos(string &str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '*')
            return i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    set<string> s;
    queue<node> q;
    q.push(node(a, findpos(a), 0));
    s.insert(a);
    int ans = 0;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        if (now.str == b)
        {
            ans = now.step;
            break;
        }
        for (int i = -3; i <= 3; i++)
        {
            if (i != 0)
            {
                int now_pos = now.pos + i;
                if (now_pos < 0 || now_pos >= now.str.length())
                    continue;
                swap(now.str[now.pos], now.str[mod(now.str.length(), now.pos + i)]);
                string temp = now.str;
                if (s.count(temp) == 0)
                {
                    //cout << "next:" << temp << " " << now.step + 1 << endl;
                    q.push(node(temp, findpos(temp), now.step + 1));
                    s.insert(temp);
                }
                swap(now.str[now.pos], now.str[mod(now.str.length(), now.pos + i)]);
            }
        }
    }
    cout << ans << endl;
    //system("pause");
}