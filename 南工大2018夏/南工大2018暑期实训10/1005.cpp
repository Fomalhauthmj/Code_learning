#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 200
struct node
{
    int x;
    int y;
    int z;
};
node blocks[size];
int n;
bool cmp(const node &n1,const node &n2)
{
    if(n1.x!=n2.x) return n1.x<n2.x;
    return n1.y<n2.y;
}
int answer;
int dp[size];
int LIS()
{
    answer=0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<6*n;i++)
    {
        dp[i]=blocks[i].z;
        for(int j=0;j<i;j++)
        {
            if(blocks[j].x<blocks[i].x&&blocks[j].y<blocks[i].y&&(dp[j]+blocks[i].z)>dp[i])
                dp[i]=dp[j]+blocks[i].z;
        }
        if(answer<dp[i]) answer=dp[i];
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    int xi,yi,zi;
    int casenum=0;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<6*n;i+=6) 
        {
            cin>>xi>>yi>>zi;
            blocks[i].x=xi;blocks[i].y=yi;blocks[i].z=zi;
            blocks[i+1].x=yi;blocks[i+1].y=xi;blocks[i+1].z=zi;
            blocks[i+2].x=yi;blocks[i+2].y=zi;blocks[i+2].z=xi;
            blocks[i+3].x=zi;blocks[i+3].y=yi;blocks[i+3].z=xi;
            blocks[i+4].x=xi;blocks[i+4].y=zi;blocks[i+4].z=yi;
            blocks[i+5].x=zi;blocks[i+5].y=xi;blocks[i+5].z=yi;
        }
        sort(blocks,blocks+6*n,cmp);
        cout<<"Case "<<++casenum<<": maximum height = "<<LIS()<<endl;
    }
}