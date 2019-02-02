#include<iostream>
using namespace std;
int q;
long long n,m,k;
long long ans;
long long tempans;
int dir[8][2]={{1,0},{-1,0},{1,1},{-1,-1},{0,1},{0,-1},{1,-1},{-1,1}};
bool DFS(int cur,int x,int y)
{
    if(cur==k)
    {
        if(x!=n||y!=m) return false;
    }
    if(cur<k)
    {
        if(x==n&&y==m)
        {
            if((k-cur)%2==0)
            {
                tempans+=k-cur;
                if(tempans>ans) ans=tempans;
                return true;
            }
            else return false;
        }
        for(int i=0;i<8;i++)
        {
            if(i==2||i==3) tempans++;
            if(DFS(cur+1,x+dir[i][0],y+dir[i][1])) return true;
            if(i==2||i==3) tempans--;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        tempans=0;
        if(DFS(0,0,0)) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}