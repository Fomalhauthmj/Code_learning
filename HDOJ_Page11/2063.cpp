#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int line[maxn][maxn];
bool used[maxn];
int boys[maxn];
int K,M,N;
bool finding(int x)
{
    for(int i=1;i<=N;i++)
    {
        if(line[x][i]==1&&used[i]==0)
        {
            used[i]=1;
            if(boys[i]==0||finding(boys[i])==true)
            {
                boys[i]=x;
                return true;
            }
        }
    }
    return false;
}
int matching()
{
    int sum=0;
    for(int i=1;i<=M;i++)
    {
        memset(used,0,sizeof(used));
        if(finding(i)==true) sum++;
        else continue;
    }
    return sum;
}
int main()
{
    while(cin>>K)
    {
        if(K==0) break;
        else{
            cin>>M>>N;
            memset(line,0,sizeof(line));
            memset(boys,0,sizeof(boys));
            while(K--)
            {
                int a,b;
                cin>>a>>b;
                line[a][b]=1;
            }
            cout<<matching()<<endl;
        }
    }
    return 0;
}
