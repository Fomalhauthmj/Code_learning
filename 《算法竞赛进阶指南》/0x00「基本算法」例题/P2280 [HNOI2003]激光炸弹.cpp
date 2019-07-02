#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int N=5050;
int sum[N][N];
int n,r;
int GetArea(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x2][y1]-sum[x1][y2]+sum[x1][y1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>r;
    int xi,yi,vi;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
    {
        cin>>xi>>yi>>vi;
        sum[xi+1][yi+1]+=vi;
    }
    for(int i=1;i<=5001;i++)
    {
        for(int j=1;j<=5001;j++)
        {
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=0;i+r<=5001;i++)
    {
        for(int j=0;j+r<=5001;j++)
        {
            ans=max(ans,GetArea(i,j,i+r,j+r));
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}