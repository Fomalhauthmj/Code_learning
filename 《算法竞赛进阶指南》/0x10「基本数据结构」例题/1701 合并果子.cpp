/*
 * File Created: Wednesday, 17th July 2019 10:46:30 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 18th July 2019 6:26:33 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<queue>
using namespace std;
#define ll long long
priority_queue<ll,vector<ll>,greater<ll>> q;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll num;
    for(int i=0;i<n;i++)
        cin>>num,q.push(num);
    ll ans=0,first,second;
    while(q.size()>1)
    {
        first=q.top(),q.pop();
        second=q.top(),q.pop();
        ans+=first+second;
        q.push(first+second);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}