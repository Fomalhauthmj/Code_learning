#include<iostream>
#include<cstring>
using namespace std;
const int N=1010;
int fa[N],num[N],nxt[N],lst[N];
double tot[N],c[N],d[N];
bool vis[N];
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v1,v2,n,r;
    while(cin>>n>>r&&n+r)
    {   
        for(int i=1;i<=n;i++) 
        {
            cin>>c[i];
            d[i]=c[i];
            num[i]=1;
            tot[i]=c[i];
            lst[i]=i;//last node
            nxt[i]=i;//next node
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>v1>>v2;
            fa[v2]=v1;
        }
        memset(vis,0,sizeof(vis));
        int cnt=n-1;
        while(cnt--)
        {
            int p=0;//cur max id
            double k=0;//cur max c
            for(int j=1;j<=n;j++)
            {
                if(j!=r&&!vis[j]&&c[j]>k)
                    k=c[j],p=j;
            }
            int father=fa[p];
            while(vis[father]) fa[p]=father=fa[father];
            // if father has visited,backward
            num[father]+=num[p];
            tot[father]+=tot[p];
            c[father]=tot[father]/num[father];
            vis[p]=true;
            //update 
            nxt[lst[father]]=p;
            lst[father]=lst[p];

        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<"cur "<<r<<endl;
            ans+=i*d[r];
            r=nxt[r];// get next color node
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}