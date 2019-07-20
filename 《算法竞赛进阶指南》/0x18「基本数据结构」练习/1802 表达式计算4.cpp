/*
 * File Created: Thursday, 18th July 2019 8:26:38 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 18th July 2019 11:22:55 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
using namespace std;
int pri[150];
void init()
{
    pri['+'] = 1;
    pri['-'] = 1;
    pri['*'] = 2;
    pri['/'] = 2;
    pri['^'] = 3;
}
string convert(string &str)
{
    string ret;
    stack<char> op;
    int len = str.length();
    char ch;
    for (int i = 0; i < len; i++)
    {
        ch = str[i];
        if (ch >= '0' && ch <= '9')
            ret += ch;
        else
        {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
                ret += '#';
            if (ch == '(')
                op.push(ch);
            else if (ch == ')')
            {
                while (op.size() && op.top() != '(')
                {
                    ret += op.top();
                    op.pop();
                }
                if (op.size())
                    op.pop();
            }
            else
            {
                while (op.size() && pri[op.top()] >= pri[ch])
                {
                    ret += op.top();
                    op.pop();
                }
                op.push(ch);
            }
        }
    }
    if(ret.back()>='0'&&ret.back()<='9') ret+='#';
    while (op.size())
        ret += op.top(), op.pop();
    return ret;
}
int calc(string str)
{
    //cout<<str<<endl;
    stack<int> num;
    int val = 0;
    char ch;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        ch = str[i];
        if (ch >= '0' && ch <= '9')
            val = val * 10 + ch - '0';
        else if (ch == '#')
            num.push(val), val = 0;
        else
        {
            if(ch=='('||ch==')') continue;
            int left = 0, right = 0;
            if (num.size())
                right = num.top(), num.pop();
            if (num.size())
                left = num.top(), num.pop();
            switch (ch)
            {
            case '+':
                num.push(left + right);
                break;
            case '-':
                num.push(left - right);
                break;
            case '*':
                num.push(left * right);
                break;
            case '/':
                num.push(left / right);
                break;
            case '^':
                num.push(pow(left, right));
                break;
            }
        }
    }
    return num.top();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    init();
    cout << calc(convert(str)) << endl;
    system("pause");
    return 0;
}