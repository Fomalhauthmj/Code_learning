/*
 * File Created: Wednesday, 17th July 2019 10:45:51 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 7:53:53 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1E4+50;
struct node
{
    int p,d;
    bool operator<(const node &n) const
    {
        return d<n.d;
    }
};
node ns[N];
priority_queue<int,vector<int>,greater<int> > q;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>ns[i].p>>ns[i].d;
        }
        sort(ns,ns+n);
        for(int i=0;i<n;i++)
        {
            if(ns[i].d>q.size()) q.push(ns[i].p);
            else if(ns[i].d==q.size())
                if(ns[i].p>q.top())
                    q.pop(),q.push(ns[i].p);
        }
        int ans=0;
        while(!q.empty()) ans+=q.top(),q.pop();
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}