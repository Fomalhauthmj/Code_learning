//0-1背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2010
int n,m,k;
struct node
{
    int left;
    int right;
};
bool cmp(const node &n1,const node &n2)
{
    if(n1.left==n2.left) return n1.right<n2.right;
    else n1.left<n2.left;
}
node each[N];
int dp[N][N];//dp[i][j] !:在1-i范围内 选择j个不同邮票集 可获得的最大不同邮票种类
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int casenum=1;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++) cin>>each[i].left>>each[i].right;
        sort(each+1,each+1+m,cmp);
        memset(dp,0,sizeof(dp));//init 初始值
        int add_len=0;
        int pos=1;
        for(int i=1;i<=n;i++)
        {
            while(pos<=m&&each[pos].left==i)
            {
                add_len=max(add_len,each[pos].right-i+1);
                pos++;//寻找同起点下的区间最右点
            }
            for(int j=1;j<=k;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                dp[i+add_len-1][j+1]=max(dp[i+add_len-1][j+1],dp[i][j]+add_len);
            }
            if(add_len) add_len--;
        }
        cout<<"Case #"<<casenum++<<": "<<dp[n][k]<<endl;
    }
}