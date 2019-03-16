#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
string a = "012345678";
string b = "087654321";
set<string> s;
struct node
{
    string str;
    int p;
    int t;
    node(string s, int i1, int i2)
    {
        str = s;
        p = i1;
        t = i2;
    }
};
int mod(int x)
{
    while (x < 0)
        x += 9;
    return x % 9;
}
//todo  BFS???
int find_0(string str)
{
    for (int i = 0; i < 9; i++)
    {
        if (str[i] == '0')
            return i;
    }
}
string change(string s, int pos, int kind)
{
    switch (kind)
    {
    case 0:
        swap(s[pos], s[mod(pos + 2)]);
        break;
    case 1:
        swap(s[pos], s[mod(pos + 1)]);
        break;
    case 2:
        swap(s[pos], s[mod(pos - 1)]);
        break;
    case 3:
        swap(s[pos], s[mod(pos - 2)]);
        break;
    }
    return s;
}
int BFS()
{
    queue<node> q;
    q.push(node(a, 0, 0));
    s.insert(a);
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        //cout << "Cur:" << now.str << " " << now.p << " " << now.t << endl;
        if (now.str == b)
        {
            return now.t;
        }
        for (int i = 0; i < 4; i++)
        {
            string temp = change(now.str, now.p, i);
            if (s.count(temp) == 0)
            {
                q.push(node(temp, find_0(temp), now.t + 1));
                s.insert(temp);
            }
        }
        //ans=20
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << BFS() << endl;
    system("pause");
}