#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 500050
int a[N];
bool vis[N];
//1000ms  nlogn
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        memset(vis,0,sizeof(vis));
        int ans=0;
        int k;
        for(int i=n-1;i>=0;i--)
        {
            if(!vis[i])
            {
                k=upper_bound(a,a+n,a[i]/2)-a;//>a[i]/2
                k-=1;
                if(k<0) continue;
                while(vis[k]) 
                {
                    k--;
                    if(k<0) break;
                }
                if(k<0) continue;
                vis[i]=1;
                vis[k]=1;
                ans++;//贪心
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) ans++;
        }
        cout<<ans<<endl;
    }
}//https://blog.csdn.net/mikchy/article/details/86729083