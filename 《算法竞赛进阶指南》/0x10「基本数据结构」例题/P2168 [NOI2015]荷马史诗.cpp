/*
 * File Created: Thursday, 18th July 2019 6:35:44 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 18th July 2019 6:36:14 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<queue>
using namespace std;
#define ll long long
const int N=1e5+50;
int n,k;
struct node
{
    ll w;
    int merge_cnt;
    node(ll ww=0,int mm=0):w(ww),merge_cnt(mm){}
    bool operator<(const node &n) const
    {
        if(w!=n.w) return w>n.w;
        return merge_cnt>n.merge_cnt;
    }
};
priority_queue<node> q;
node GetkMin()
{
    node ret;
    for(int i=0;i<k;i++)
    {
        ret.w+=q.top().w;
        ret.merge_cnt=max(ret.merge_cnt,q.top().merge_cnt);
        q.pop();
    }
    ret.merge_cnt++;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    ll num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        q.push(node(num));
    }
    while((n-1)%(k-1))
    {
        q.push(node(0));
        n++;
    }
    ll ans=0;
    while(q.size()>1)
    {
        node now=GetkMin();
        //cout<<now.w<<" "<<now.merge_cnt<<endl;
        ans+=now.w;
        q.push(now);
    }
    cout<<ans<<endl;
    cout<<q.top().merge_cnt<<endl;
    system("pause");
    return 0;
}