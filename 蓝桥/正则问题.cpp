/*
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
void Disp(stack<char> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    stack<char> s;
    vector<int> v;
    cin >> str;
    int len = str.length();
    char ele;
    for (int i = 0; i < len; i++)
    {
        ele = str[i];
        if (ele == ')')
        {
            v.clear();
            char ch = s.top();
            s.pop();
            int temp = 0;
            while (ch != '(')
            {
                if (ch == '|')
                {
                    v.push_back(temp);
                    temp = 0;
                }
                else
                {
                    temp++;
                }
                ch = s.top();
                s.pop();
            }
            v.push_back(temp);
            sort(v.begin(), v.end());
            int temp_max = v[v.size() - 1];
            for (int j = 0; j < temp_max; j++)
                s.push('x');
        }
        else
        {
            s.push(ele);
        }
    } //去括号优先级
    //37%->75%
    //重解析
    v.clear();
    int temp = 0;
    char ch;
    while (!s.empty())
    {
        ch = s.top();
        s.pop();
        if (ch == '|')
        {
            v.push_back(temp);
            temp = 0;
        }
        else if (ch == 'x') //注意强判定 可能会有()
            temp++;
    }
    v.push_back(temp);
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << endl;
    system("pause");
    return 0;
}
*/

//! 递归
/*
#include <iostream>
#include <string>
using namespace std;
string str;
int p = 0;
int func()
{
    int a = 0;
    int b = 0;
    while (p < str.length())
    {
        if (str[p] == 'x')
        {
            p++;
            b++;
        }
        else if (str[p] == '|')
        {
            p++;
            a = max(a, b);
            b = 0;
        }
        else if (str[p] == '(')
        {
            p++;
            b += func();
        }
        else if (str[p] == ')')
        {
            p++;
            break;
        }
    }
    return max(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    cout << func() << endl;
    //system("pause");
    return 0;
}
*/

//!  双栈？
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int xnum = 0;
    stack<char> op;
    stack<int> num;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'x')
        {
            xnum++;
        }
        else if (str[i] == '|')
        {
            num.push(xnum);
            xnum = 0;
            op.push(str[i]);
        }
        else if (str[i] == '(')
        {
            if (xnum)
            {
                num.push(xnum);
                xnum = 0;
            }
            op.push(str[i]);
        }
        else if (str[i] == ')')
        {
            num.push(xnum);
            xnum = 0;
            while (op.top() != '(')
            {
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(max(n1, n2));
            }
            op.pop();
            xnum = num.top();
            num.pop();
            if (num.empty())
            {
                num.push(xnum);
            }
            else
            {
                int temp = num.top();
                num.pop();
                num.push(temp + xnum);
            }
            xnum = 0;
        }
    }
    if (xnum)
        num.push(xnum);
    char ch;
    while (!op.empty())
    {
        ch = op.top();
        op.pop();
        switch (ch)
        {
        case '|':
            int n1 = num.top();
            num.pop();
            int n2 = num.top();
            num.pop();
            num.push(max(n1, n2));
            break;
        }
    }
    cout << num.top() << endl;
    system("pause");
}