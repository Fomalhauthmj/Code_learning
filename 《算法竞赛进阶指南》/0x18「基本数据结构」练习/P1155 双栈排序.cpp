/*
 * File Created: Friday, 19th July 2019 8:00:08 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Saturday, 20th July 2019 11:21:41 am
 * Copyright (c) 2019 北落师门
 */
// 此为错误做法 正解需要二分图染色
#include<iostream>
#include<stack>
#include<cstring>
#define inf 0x3f3f3f3f
#define N 1010
int ans[N*2],a[N],n;
using namespace std;
stack<int> s1,s2,s3;
bool Judge(int pos)
{
    if(s2.top()==inf) return true;
    int i;
    for(i=pos+1;i<n;i++)
    {
        if(a[i]>a[pos]&&a[i]>s2.top()) break;
    }
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[pos]) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));
        s1=s2=s3;
        cin>>n;
        for(int i=0;i<n;i++)    cin>>a[i];
        bool flag=true;
        s1.push(inf),s2.push(inf);
        int cur=1,pos=0;
        for(int i=0;i<2*n;i++)
        {
            if(s1.top()==cur)
            {
                s1.pop();
                ans[i]=1;
                cur++;
            }
            else if(s2.top()==cur)
            {
                s2.pop();
                ans[i]=3;
                cur++;
            }
            else if(pos<n&&a[pos]<s1.top()&&Judge(pos))
            {
                s1.push(a[pos++]);
                ans[i]=0;
            }
            else if(pos<n&&a[pos]<s2.top())
            {
                s2.push(a[pos++]);
                ans[i]=2;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<2*n;i++)
                cout<<char('a'+ans[i])<<' ';
            cout<<endl;
        }
        else cout<<0<<endl;
    }
    system("pause");
    return 0;
}