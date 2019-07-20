/*
 * File Created: Saturday, 20th July 2019 11:53:10 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Saturday, 20th July 2019 11:54:12 am
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<deque>
using namespace std;
const int N=1E6+50;
int n,k;
int a[N],minval[N],maxval[N];
deque<int> q1,q2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(q1.size()&&q1.front()<=i-k) q1.pop_front();
        while(q2.size()&&q2.front()<=i-k) q2.pop_front();
        while(q1.size()&&a[i]<=a[q1.back()]) q1.pop_back();
        while(q2.size()&&a[i]>=a[q2.back()]) q2.pop_back();
        q1.push_back(i),q2.push_back(i);
        minval[i]=a[q1.front()];
        maxval[i]=a[q2.front()];
    }
    for(int i=k;i<=n;i++)
        cout<<minval[i]<<' ';
    cout<<endl;
    for(int i=k;i<=n;i++)
        cout<<maxval[i]<<' ';
    cout<<endl;
    //system("pause");
    return 0;
}