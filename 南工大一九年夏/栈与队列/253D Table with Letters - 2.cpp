//http://codeforces.com/contest/253/problem/D
#include<iostream>
#include<cstring>
using namespace std;
const int N=405;
#define ll long long
int n,m,k;
char p[N][N];
int sum[N][N];
ll cnt[150];
inline bool Judge(int x1,int y1,int x2,int y2)
{
    if(sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]>k) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(p[i][j]=='a');
    ll ans=0;
    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=i1+1;i2<=n;i2++)
        {
            int j2=1;
            memset(cnt,0,sizeof(cnt));
            for(int j1=1;j1<=m;j1++)
            {
                if(p[i1][j1]!=p[i2][j1]) continue;
                cnt[p[i1][j1]]--;
                while(j2<=m&&Judge(i1,j1,i2,j2))
                {
                    if(p[i1][j2]==p[i2][j2]) cnt[p[i1][j2]]++;
                    j2++;
                }
                //cout<<i1<<" "<<i2<<" "<<" "<<j1<<" "<<p[i1][j1]<<cnt[p[i1][j1]]<<endl;
                if(cnt[p[i1][j1]]>0) ans+=cnt[p[i1][j1]];
            }
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}