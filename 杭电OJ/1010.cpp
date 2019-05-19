#include<iostream>
#include<cstring>
using namespace std;
int N,M,T;
char maze[60][10];
bool visit[60][10];
int dx[5]={0,1,0,-1,0};//!:增量数组
int dy[5]={0,0,1,0,-1};
int startx,starty,endx,endy;
int walls;
bool running(int x,int y,int time)
{
    if(x==endx&&y==endy&&time==T) return true;//达到目标点
    if(x<1||x>N||y<1||y>M) return false;
    if(time>T) return false;
    int temp=T-time-abs(endx-x)-abs(endy-y);//!:欧几里得距离
    if(temp<0||temp&1) return false;//!:奇偶剪枝
    for(int i=1;i<=4;i++)
    {
        int tempx=x+dx[i];
        int tempy=y+dy[i];
        if(tempx>=1&&tempx<=N&&tempy>=1&&tempy<=M&&maze[tempx][tempy]!='X'&&visit[tempx][tempy]==0)
        {
                visit[tempx][tempy]=1;
                if(running(tempx,tempy,time+1)) return true;
                else visit[tempx][tempy]=0;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N>>M>>T)
    {
        walls=0;
        if(N==0&&M==0&&T==0) break;
        else{
            memset(visit,0,sizeof(visit));
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=M;j++)
                {
                    cin>>maze[i][j];
                    if(maze[i][j]=='S')
                    {
                        startx=i;
                        starty=j;
                    }
                    if(maze[i][j]=='D')
                    {
                        endx=i;
                        endy=j;
                    }
                    if(maze[i][j]=='X')
                    {
                        walls++;
                    }
                }
            }
            if(N*M-walls-1<T) 
            {
                cout<<"NO"<<endl;
                continue;
            }
            visit[startx][starty]=1;
            if(running(startx,starty,0)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}