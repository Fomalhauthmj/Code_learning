/*
 * File Created: Tuesday, 16th July 2019 12:01:53 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Tuesday, 16th July 2019 9:35:20 am
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <set>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
int n;
set<pair<ll, int>> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll num, ans, p;
    cin>>num;
    s.insert(make_pair(num,1));
    for (int i = 2; i <= n; i++)
    {
        cin >> num;
        ans=inf;
        s.insert(make_pair(num, i));
        auto pos = s.find(make_pair(num, i));
        auto it1 = pos, it2 = pos;
        if (it1-- != s.begin())
        {
            if (pos->first - it1->first < ans)
            {
                ans = pos->first - it1->first;
                p = it1->second;
                //cout<<"pre:"<<ans<<" "<<p<<endl;
            }
        }
        if (++it2 != s.end())
        {
            if (it2->first - pos->first < ans)
            {
                ans = it2->first - pos->first;
                p = it2->second;
                //cout<<"next:"<<ans<<" "<<p<<endl;
            }
        }
        cout << ans << " " << p << endl;
    }
    //system("pause");
    return 0;
}