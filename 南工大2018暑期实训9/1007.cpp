#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define size1 100010
#define size2 15
long long  n,m; //n:cakes  m:sodas
long long target;
bool vis[size1];
vector<long long> V[size2];
bool DFS(int k,long long cur,int start)
{
    if(k>=m) return true;
    for(int i=start;i>=1;i--)
    {
        if(!vis[i])
        {
            if(cur+i==target)
            {
                V[k].push_back(i);
                vis[i]=1;
                if(DFS(k+1,0,n)) return true;
                vis[i]=0;
                V[k].pop_back();
                return false;
            }
            else if(cur+i<target)
            {
                V[k].push_back(i);
                vis[i]=1;
                if(DFS(k,cur+i,i-1)) return true;
                vis[i]=0;
                V[k].pop_back();
                if(cur==0) return false;     
            }
        }
    }
    return false;
}
void print()
{
    vector<long long>::iterator it;
    for(int i=0;i<m;i++)
    {
        cout<<V[i].size();
        //int temp=0;
        for(it=V[i].begin();it!=V[i].end();it++)
        {
            cout<<" "<<*it;//temp+=*it;
        }
        //cout<<"sum:"<<temp;
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long sum=(1+n)*n/2;
        if(sum%m!=0||n<2*m-1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            memset(vis,0,sizeof(vis));
            for(int i=0;i<m;i++) V[i].clear();
            target=sum/m;
            if(DFS(0,0,n))
            {
                cout<<"YES"<<endl;
                print();
            }
            else cout<<"NO"<<endl;
        }
    }
}