#include<iostream>
#include<algorithm>
using namespace std;
#define size 500050
long long L;
int n;
int m;
long long dis[size];
bool judge(long long mid)
{
    if(mid*m<L) return false;
    long long temp=0;
    int jumptime=0;
    for(int i=0;i<=n;i++)
    {
        if(dis[i]-temp>mid) return false;
        int j;
        for(j=i;j<=n;j++)
        {
            if(dis[j]-temp>mid) break;
        }
        jumptime++;
        temp=dis[j-1];
        i=j-1;
    }
    if(jumptime>m) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>L>>n>>m)
    {
        long long max_space=0;
        for(int i=0;i<n;i++) 
        {
            cin>>dis[i];
        }
        dis[n]=L;
        sort(dis,dis+n+1);
        for(int i=1;i<=n;i++)
        {
            if(dis[i]-dis[i-1]>max_space) max_space=dis[i]-dis[i-1];
        }
        max_space=max(dis[0],max_space);
        long long left=max_space;//跳跃最短距离
        long long right=L;//跳跃最大距离
        long long mid;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(judge(mid)==true) right=mid-1;
            else left=mid+1;
        }
        cout<<left<<endl;
    }   
}