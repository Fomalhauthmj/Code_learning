#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> > p2; //小根堆
priority_queue<int> p1;                            //大根堆
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p;
    cin >> p;
    int num, cnt, x, temp, mid;
    while (p--)
    {
        cin >> num >> cnt;
        cout << num << " " << cnt / 2 + 1 << endl;
        while (!p1.empty())
            p1.pop();
        while (!p2.empty())
            p2.pop();
        ans.clear();
        for (int i = 1; i <= cnt; i++)
        {
            cin >> x;
            if (!p2.empty())
                mid = p2.top();
            if (p2.empty())
                p2.push(x);
            else if (x < mid)
                p1.push(x);
            else if (x >= mid)
                p2.push(x);
            while (p1.size() > i / 2)
            {
                temp = p1.top();
                p1.pop();
                p2.push(temp);
            }
            while (p2.size() > i - i / 2)
            {
                temp = p2.top();
                p2.pop();
                p1.push(temp);
            }
            /*
            if (!p1.empty())
                cout << "cur p1 top " << p1.top() << endl;
            if (!p2.empty())
                cout << "cur p2 top " << p2.top() << endl;
            cout << endl;
            */
            if (i & 1)
            {
                ans.push_back(p2.top());
            }
        }
        int len = ans.size();
        for (int i = 0; i < len; i++)
        {
            if (i % 10 == 9 || i == len - 1)
                cout << ans[i] << endl;
            else
                cout << ans[i] << " ";
        }
    }
    //system("pause");
    return 0;
}