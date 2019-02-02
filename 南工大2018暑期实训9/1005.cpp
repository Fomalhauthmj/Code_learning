#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 25
int n,sum;
int len[size];
bool vis[size];
int target;
bool DFS(int k,int cur_len,int start)
{
    int pre=0;
    if(k>=3) return true;
    for(int i=start;i<n;i++)
    {
        if(!vis[i]&&pre!=len[i])
        {
            pre=0;
            if(cur_len+len[i]==target)
            {
                vis[i]=1;
                if(DFS(k+1,0,0)) return true;
                vis[i]=0;
                pre=len[i];
                return false;
            }
            else if(cur_len+len[i]<target)
            {
                vis[i]=1;
                if(DFS(k,cur_len+len[i],i+1)) return true;
                vis[i]=0;
                pre=len[i];
                if(cur_len==0) return false; //TODO:强剪枝
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(int i=0;i<n;i++) 
        {
            cin>>len[i];
            sum+=len[i];
        }
        if(sum%4!=0)
        {
            cout<<"no"<<endl;
            continue;
        }
        else
        {
            sort(len,len+n,greater<int>());
            memset(vis,0,sizeof(vis));
            target=sum/4;
            if(DFS(0,0,0)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
}