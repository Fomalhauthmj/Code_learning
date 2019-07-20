/*
 * File Created: Saturday, 20th July 2019 3:03:32 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Saturday, 20th July 2019 3:05:57 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<queue>
#include<set>
using namespace std; 
#define pii pair<int,int>
int n;
priority_queue<pii,vector<pii>,greater<pii> > pq;
//优先队列 结束时间早的释放 (结束时间,内存起点)
set<pii> mem;
//内存占用 (内存起点,长度)
queue<pii> wait;
//等待队列 (内存长度,占用时间)
bool push(int t,int m,int p)
{
    set<pii>::iterator i,j;
    for(i=mem.begin();i!=mem.end();i++)
    {
        j=i;
        j++;
        if(j!=mem.end())
        {
            int start=i->first+i->second;
            if(start+m<=j->first)
            {
                mem.insert({start,m});
                pq.push({t+p,start});
                return true;
            }
        }
    }
    return false;
}
int ans;
void pop(int t)
{
    while(pq.size()&&pq.top().first<=t)
    {
        int finish_time=pq.top().first;
        while(pq.size()&&pq.top().first==finish_time)
        {
            pii now=pq.top();
            pq.pop();
            set<pii>::iterator it=mem.lower_bound({now.second,0});
            mem.erase(it);
        }
        ans=finish_time;
        while(wait.size())
        {
            pii front=wait.front();
            if(push(finish_time,front.first,front.second))
            {
                wait.pop();
            }
            else break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    mem.insert({-1,1});
    mem.insert({n,1});
    int t,m,p;
    int cnt=0;
    while(cin>>t>>m>>p,t+m+p)
    {
        pop(t);
        if(!push(t,m,p))
        {
            cnt++;
            wait.push({m,p});
        }
    }
    pop(0x3f3f3f3f);
    cout<<ans<<endl;
    cout<<cnt<<endl;
    //system("pause");
    return 0;
}