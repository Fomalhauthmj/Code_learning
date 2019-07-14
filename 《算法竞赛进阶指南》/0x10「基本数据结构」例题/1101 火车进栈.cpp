/*
 * File Created: Sunday, 14th July 2019 8:31:02 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 8:33:27 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
using namespace std;
int n;
int a[25],b[25],top = 0,cur=0,cnt=0;
void Search(int step)
{
    //cout<<"cur:"<<step<<endl;
    if (step >= n+1)
    {
        if(++cnt>20) exit(0);
        for(int i=1;i<=cur;i++) cout<<b[i];
        for(int i=top;i>=1;i--) cout<<a[i];
        cout << endl;
        return;
    }
    if(top)
    {
        //当前栈顶出栈
        b[++cur]=a[top--];
        Search(step);
        a[++top]=b[cur--];
    }
    //当前数入栈
    a[++top]=step;
    Search(step+1);
    top--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    Search(1);
    //system("pause");
    return 0;
}