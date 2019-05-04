#include<iostream>
#include<cstring>
using namespace std;
long long l,r,diff;
int n;
int a[20];
bool vis[20];
int target;
int each_max;
int each_min;
int each_ans;
int ans;
long long cur_sum;
void DFS(int k,int start)
{
    if(k>=target)
    {
        if(cur_sum>=l&&r>=cur_sum&&(each_max-each_min)>=diff)
        {
            each_ans++;
        }
        return;
    }
    for(int i=start;i<n;i++)
    {
        if(!vis[i])
        {
            int premax=each_max;
            int premin=each_min;
            if(each_max<a[i]) each_max=a[i];
            if(each_min>a[i]) each_min=a[i];
            vis[i]=1;
            cur_sum+=a[i];
            DFS(k+1,i+1);
            vis[i]=0;
            each_max=premax;
            each_min=premin;
            cur_sum-=a[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>l>>r>>diff;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int k=1;k<=n;k++)
        {
            target=k;
            each_ans=0;
            each_max=0;
            each_min=1e8;
            cur_sum=0;
            memset(vis,0,sizeof(vis));
            DFS(0,0);
            ans+=each_ans;
        }
        cout<<ans<<endl;
    }
}
