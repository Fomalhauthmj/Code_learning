/*
 * File Created: Monday, 15th July 2019 8:04:37 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Monday, 15th July 2019 8:05:32 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N=2E5+50;
struct node
{
    int idx;
    ll val;
    bool operator <(const node &n) const
    {
        return val>n.val;
    }
};
node a[N];
int n;
vector<int> p[N];
int cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].val;
        a[i].idx=i+1;
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        p[++cnt].push_back(a[i].idx);
        while(a[i].val==a[i+1].val) p[cnt].push_back(a[i+1].idx),i++;
    }
    for(int i=1;i<=cnt;i++) sort(p[i].begin(),p[i].end());
    int ans=1;
    bool flag=0;//递减
    ll pre_idx=inf;
    for(int i=1;i<=cnt;i++)
    {
        int tot=p[i].size();
        if(!flag)
        {
            if(pre_idx>p[i][tot-1])
            {
                //满足递减
                pre_idx=p[i][0];
                //相同值 idx可以互换 为了构造更多单谷 递减完后我们将最小idx放在谷底 
            }
            else
            {
                pre_idx=p[i][tot-1];
                flag=1;//开始递增
            }
        }
        else
        {
            if(pre_idx<p[i][0])
            {
                //满足递增
                pre_idx=p[i][tot-1];
            }
            else
            {
                ans++;
                pre_idx=p[i][0];
                flag=0;//开始递减
            }
            
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
/*
6
3 6 0 9 6 3
 */