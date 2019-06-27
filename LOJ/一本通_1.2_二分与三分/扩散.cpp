#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
const ll N = 55;
struct node
{
    ll first;
    ll second;
};
node ps[N];
ll n;
ll fa[N];
void Init()
{
    for(int i=0;i<n;i++)
    {
        fa[i]=i;
    }
}
ll Find(ll x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
bool judge(ll mid)
{
    Init();
    ll temp1,temp2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                temp1 = abs(ps[i].first - ps[j].first);
                temp2 = abs(ps[i].second - ps[j].second);
                if(temp1+temp2<=2*mid)
                {
                    ll fi,fj;
                    fi=Find(i);
                    fj=Find(j);
                    fa[fi]=fj;
                }
            }   
        }
    }
    set<ll> s;
    for(int i=0;i<n;i++)
    {
        s.insert(Find(i));
    }
    return s.size()==1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i].first >> ps[i].second;
    }
    ll left = 0;
    ll right = 1 << 30;
    ll mid;
    ll ans;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        //cout<<"cur:"<<mid<<endl;
        if (judge(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}