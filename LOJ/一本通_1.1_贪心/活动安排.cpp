#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N=1010;
int n;
pair<ll,ll> p[N];
bool cmp(pair<ll,ll> p1,pair<ll,ll> p2)
{
    if(p1.second!=p2.second) return p1.second<p2.second;
    return p1.first<p2.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,cmp);
    ll ans=0;
    int cur_time=0;
    for(int i=0;i<n;i++)
    {
        //cout<<p[i].first<<" "<<p[i].second<<endl;
        if(i==0) 
        {
            cur_time=p[i].second;
            ans++;
        }
        else
        {
            if(cur_time<=p[i].first)
            {
                ans++;
                cur_time=p[i].second;
            }
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}