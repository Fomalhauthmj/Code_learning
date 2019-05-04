#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define N 500050
int a[N];
bool vis[N];
//1000ms   upper_bound 超时
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        //最佳情况是两两配对 一个体重为 x 的人可以和体重至少为 2x 配对
        int pos = 0;
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n / 2; i++) //由小到大匹配
        {
            if (n / 2 + pos >= n)
                break;
            if (a[n / 2 + pos] >= 2 * a[i])
            {
                vis[i] = vis[n / 2 + pos] = 1;
                pos++;
                ans++;
            }
            else
            {
                while ((n / 2 + pos < n) && a[n / 2 + pos] < 2 * a[i])
                    pos++;
                if (n / 2 + pos >= n)
                    break;
                vis[i] = vis[n / 2 + pos] = 1;
                ans++;
                pos++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                ans++;
        }
        cout << ans << endl;
    }
} //https://blog.csdn.net/mikchy/article/details/86729083
/*
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
*/