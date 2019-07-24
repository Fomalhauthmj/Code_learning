
#include<bits/stdc++.h>
using namespace std;
#define N 20
#define inf 0x3f3f3f3f
int n;
double dp[1<<N];
struct node
{
    int x;
    int y;
};
node start;
node ps[N];
double distance(node n1,node n2)
{
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));//返回两点的距离
}
double Dp(int S)
{
    if(dp[S]>=0) return dp[S];//记忆化搜索 直接返回
    double ans=inf;
    int i=0;//固定一个点
    while((S&(1<<i))==0) i++;
    //例如 有 a b   c d 两次射击 那么 先a b再c d  和先c d 再a b 效果一样
    for(int j=i+1;j<n;j++)//  先选取i之前的点导致 !:内存超限  例如1-2  2-1 重复搜索了
    {
        //确定两个相异点 并且S中包含i,j 
        //cout<<"cur:"<<S<<" "<<i<<" "<<j<<endl;
        if(S&(1<<j))//S状态中必须还有此状态
        {
            int temp=S-(1<<i)-(1<<j);//新状态
            //cout<<"will dp:"<<temp<<endl;
            double better_dis=min(distance(start,ps[i]),distance(start,ps[j]))+distance(ps[i],ps[j]);
            ans=min(ans,Dp(temp)+better_dis);
        }
    }
    return dp[S]=ans;
}
bool cmp(node &n1,node &n2)
{
    return distance(n1,start)<distance(n2,start);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    int casenum=1;
    while(T--)
    {
        cin>>start.x>>start.y>>n;
        n*=2;
        for(int i=0;i<n;i++)
        {
            cin>>ps[i].x>>ps[i].y;
        }
        memset(dp,-1,sizeof(dp));
        //排序
        dp[0]=0;
        sort(ps,ps+n,cmp);
        cout<<"Case #"<<casenum++<<": "<<fixed<<setprecision(2)<<Dp((1<<n)-1)<<endl;
        //https://blog.csdn.net/lxglbk/article/details/6674270 为什么要倒推 正推出现重复dp[0]->dp[end]
    }
}


/*
//!:正推 TLE
#include<bits/stdc++.h>
using namespace std;
#define N 20
#define inf 0x3f3f3f3f
int n;
double dp[1<<N];
struct node
{
    int x;
    int y;
};
node start;
node ps[N];
double distance(node n1,node n2)
{
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));//返回两点的距离
}
bool cmp(node &n1,node &n2)
{
    return distance(n1,start)<distance(n2,start);
}
bool even_1(int x)
{
    if(x==0) return true;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i)) cnt++;
    }
    if(cnt&1) return false;
    else return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    int casenum=1;
    while(T--)
    {
        cin>>start.x>>start.y>>n;
        n*=2;
        for(int i=0;i<n;i++)
        {
            cin>>ps[i].x>>ps[i].y;
        }
        memset(dp,-1,sizeof(dp));
        //排序
        dp[0]=0;
        sort(ps,ps+n,cmp);
        for(int i=0;i<(1<<n)-1;i++)
        {
            if(dp[i]!=-1&&even_1(i))
            {
                //cout<<"cur i:"<<i<<endl;
                for(int j=0;j<n;j++)
                {
                    if(i&(1<<j)) continue;
                    //cout<<"cur j:"<<j<<endl;
                    for(int k=j+1;k<n;k++)
                    {
                        if(i&(1<<k)) continue;
                        //cout<<"cur k:"<<k<<endl;
                        int temp=i|(1<<j)|(1<<k);//新状态
                        //cout<<"temp:"<<temp<<endl;
                        double better_dis=min(distance(start,ps[j]),distance(start,ps[k]))+distance(ps[j],ps[k]);
                        //cout<<"better_dis:"<<better_dis<<endl;
                        if(dp[temp]>-1)    
                        {
                            dp[temp]=min(dp[temp],dp[i]+better_dis);
                        }
                        else dp[temp]=dp[i]+better_dis;
                        //cout<<"after:"<<dp[temp]<<endl;
                    }
                }            
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            cout<<dp[i]<<endl;
        }
        */
        cout<<"Case #"<<casenum++<<": "<<fixed<<setprecision(2)<<dp[(1<<n)-1]<<endl;
        //https://blog.csdn.net/lxglbk/article/details/6674270 为什么要倒推 正推出现重复dp[0]->dp[end]
    }
}
*/