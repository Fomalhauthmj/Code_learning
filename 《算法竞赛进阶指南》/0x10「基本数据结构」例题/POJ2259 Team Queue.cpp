/*
 * File Created: Sunday, 14th July 2019 11:20:04 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Monday, 15th July 2019 9:56:28 am
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int N=1E6+50;
int a[N];
queue<int> q[1010],init;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int casenum=0;
    while(cin>>t&&t)
    {
        for(int i=0;i<=1000;i++) q[i]=init;
        int cnt,ele;
        for(int i=1;i<=t;i++)
        {
            cin>>cnt;
            for(int j=0;j<cnt;j++)
            {
                cin>>ele,a[ele]=i;
            }
        }
        cout<<"Scenario #"<<++casenum<<endl;
        string str;
        while(cin>>str)
        {
            if(str[0]=='E')
            {
                cin>>ele;
                int temp=a[ele];
                if(q[temp].empty())
                {
                    q[0].push(temp);
                }
                q[temp].push(ele);
            }
            else if(str[0]=='D')
            {
                int now=q[0].front();
                cout<<q[now].front()<<endl;
                q[now].pop();
                if(q[now].empty())
                {
                    q[0].pop();
                }
            }
            else break;
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}