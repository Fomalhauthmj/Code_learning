#include<iostream>
#include<cstring>
using namespace std;
const int N=1010;
#define ll long long
int city[N][N];
int V,E,S,K,C;
bool has_team[N],vis[N];
int d[N][N];
void Init()
{
    memset(has_team,0,sizeof(has_team));
    memset(city,0x3f,sizeof(city));
    for(int i=1;i<=V;i++) city[i][i]=0;
}
void Floyd()
{
    memcpy(d,city,sizeof(city));
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int dis[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&V,&E,&S,&K,&C);
        Init();
        for(int i=1,p;i<=K;i++) scanf("%d",&p),has_team[p]=true;
        for(int i=1;i<=E;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            city[u][v]=city[v][u]=min(city[u][v],w);
        }
        Floyd();
        int hero=0;
        for(int i=1;i<=V;i++) hero=max(hero,d[S][i]);
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=V;i++)
        {
            if(!has_team[i])
            {
                for(int j=1;j<=V;j++)
                    if(has_team[j]) dis[i]=min(dis[i],d[i][j]);
            }
        }
        int ret=0;
        for(int i=1;i<=V;i++)
            if(!has_team[i]) ret=max(ret,dis[i]);
        double key=hero*1.0/C;
        if(key<=ret)
            printf("%d\n",hero);
        else printf("%d\n",ret);
    }
    //system("pause");
    return 0;
}
