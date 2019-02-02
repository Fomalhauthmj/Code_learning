/*
#include<iostream>
using namespace std;
#define N 200010
int a[N];
int n,m,k;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        int cur_size=k;
        m--;
        for(int i=n;i>=1;i--)
        {
            if(cur_size>=a[i])
            {
                cur_size-=a[i];
                ans++;
            }
            else
            {
                m--;
                if(m<0) break;
                cur_size=k;
                cur_size-=a[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
*/
#include<iostream>
using namespace std;
#define N 200010
int a[N];
int n,m,k;
bool judge(int mid)
{
    int cur=k;
    int temp=m-1;
    for(int i=mid;i<=n;i++)
    {
        if(cur>=a[i])
        {
            cur-=a[i];
        }
        else
        {
            cur=k-a[i];
            temp--;
            if(temp<0) return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        int left=1;
        int right=n;
        int mid;
        int ans;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(judge(mid))
            {
                right=mid-1;
                ans=n-mid+1;
                //cout<<mid<<" "<<ans<<endl;
            }
            else left=mid+1;
        }
        cout<<ans<<endl;
    }
}