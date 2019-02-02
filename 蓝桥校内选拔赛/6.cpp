#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
int n,m;
int a[N];
int b[N];
bool vis[N];
vector<int> V;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        V.clear();
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            vis[b[i]]=1;
        }
        bool flag=true;
        int num=n;
        for(int i=1;i<=m;i++)
        {
            if(b[i]==num) 
            {
                num--;
                continue;
            }
            else 
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(int i=1;i<=num;i++)
            {
                cout<<i<<endl;
            }
            for(int i=1;i<=m;i++)
            {
                cout<<b[i]<<endl;
            }
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                V.push_back(i);
                vis[i]=1;
            }
        }
        vector<int>::iterator pre=V.begin();
        vector<int>::iterator it;
        for(int i=1;i<=m;i++)
        {
            it=lower_bound(V.begin(),V.end(),b[i]);
            if(it<pre)
            {
                V.insert(++pre,b[i]);
            }
            else V.insert(it,b[i]);
            pre=it;
        }
        int len=V.size();
        for(int i=0;i<len;i++)
        {
            cout<<V[i]<<endl;
        }
    }
    return 0;
}