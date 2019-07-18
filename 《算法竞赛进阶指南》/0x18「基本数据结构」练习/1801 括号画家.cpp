/*
 * File Created: Thursday, 18th July 2019 7:16:51 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 18th July 2019 7:18:11 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> s;
string str;
bool Match(char ch)
{
    char match=str[s.top()];
    if (match == '(' && ch == ')')
        return true;
    if (match == '[' && ch == ']')
        return true;
    if (match == '{' && ch == '}')
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    cin >> str;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        char ch=str[i];
        if(s.size())
        {
            if(Match(ch)) s.pop();
            else s.push(i);
        }
        else s.push(i);
        if(s.empty()) ans=max(ans,i+1);
        else ans=max(ans,i-s.top());
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}