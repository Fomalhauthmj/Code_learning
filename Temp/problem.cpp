#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int N=3e5+50;
#define ll long long
#define pii pair<ll,int>
ll a[N],b[N];
int n;
priority_queue<pii,vector<pii>,greater<pii>> pq;
ll Solve()
{
    ll ans=0;
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();
        //cout<<x.second<<" "<<x.first<<endl;
        int cost=x.first,pos=x.second;
        if(pos-1>=1)
        {
            if(a[pos-1]==a[pos])
            {
                ans+=cost;
                a[pos]++;
                if(pos+1<=n&&a[pos+1]==a[pos])
                {
                    pq.push({b[pos+1],pos+1});
                    pq.push({b[pos],pos});
                }
            }
        }
        if(pos+1<=n)
        {
            if(a[pos+1]==a[pos])
            {
                ans+=cost;
                a[pos]++;
                if(pos-1>=1&&a[pos-1]==a[pos])
                {
                    pq.push({b[pos-1],pos-1});
                    pq.push({b[pos],pos});
                }
            }
        }
    }
    return ans;
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        while(!pq.empty()) pq.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&a[i],&b[i]);
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                pq.push({b[i+1],i+1});
                pq.push({b[i],i});
            }
        }
        printf("%lld\n",Solve());
    }
    //system("pause");
    return 0;
}