#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define N 100010
int n,m;
bool vis[2*N];
pair<int,int> p[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>p[i].first>>p[i].second;
        }
        //暴力
        //寻找是否有相同的manhattan_dis
        bool flag=false;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               int temp=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
               //为什么？
               //!:WA |p1x-p2x|+|p1y-p2y|不等于|p1x+p1y-p2x-p2y|
               //例如 1 3  3 1 实际是4 错误为0
               if(vis[temp])
               {
                   flag=true;
                   break;
               }
               else vis[temp]=1;
            }
            if(flag) break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        /*
        表面上这道题复杂度是O(n^2)会超时的，
        而实际上这些坐标差绝对值的和最大是2*10^5，所以复杂度不是O(n^2)，而是O(min(n^2,m))，这就是著名的鸽笼原理。
        */
    }
}