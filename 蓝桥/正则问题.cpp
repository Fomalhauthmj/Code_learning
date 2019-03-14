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
    //system("pause");
    return 0;
}