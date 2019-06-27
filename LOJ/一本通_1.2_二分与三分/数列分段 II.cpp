#include<iostream>
using namespace std;
#define ll long long
const ll N=1E5+10;
ll n,m;
ll a[N];
bool judge(ll mid)
{
    ll temp_m=0;
    ll temp_sum=0;
    for(int i=0;i<n;i++)
    {
        if(temp_sum+a[i]>mid)
        {
            temp_m++;
            if(a[i]>mid)
            {
                return false;
            }
            else if(a[i]==mid)
            {
                temp_m++;
                temp_sum=0;
            }
            else
            {
                temp_sum=a[i];
            }
            
        }
        else if(temp_sum+a[i]==mid)
        {
            temp_m++;
            temp_sum=0;
        }
        else temp_sum+=a[i];
    }
    if(temp_sum) temp_m++;
    if(temp_m<=m) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll left=0;
    ll right=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        right+=a[i];
    }
    ll ans,mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        //cout<<"cur:"<<mid<<endl;
        if(judge(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}