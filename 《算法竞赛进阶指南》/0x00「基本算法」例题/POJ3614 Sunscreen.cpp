#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N=2505;
int c,l;
struct cow
{
    int minSPF,maxSPF;
    bool operator<(const cow &c) const
    {
        return minSPF>c.minSPF;
    }
};
cow cs[N];
struct node
{
    int SPF,cover;
    bool operator<(const node &n) const
    {
        return SPF>n.SPF;
    }
};
node ns[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>l;
    for(int i=0;i<c;i++)
        cin>>cs[i].minSPF>>cs[i].maxSPF;
    for(int i=0;i<l;i++)
        cin>>ns[i].SPF>>ns[i].cover;
    int ans=0;
    sort(cs,cs+c);
    sort(ns,ns+l);
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(ns[j].SPF<=cs[i].maxSPF&&ns[j].SPF>=cs[i].minSPF&&ns[j].cover)
            {
                ns[j].cover--,ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}