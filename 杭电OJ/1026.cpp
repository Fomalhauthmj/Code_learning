#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
char array[101][101]={'0'};
bool visit[101][101];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int path[101][101]={0};
int n,m,mintime,time;
struct node
{
    int x;
    int y;
    int time;
    node(int i1,int i2,int i3)
    {
        x=i1;y=i2;time=i3;
    }
    bool operator<(const node &n) const
    {
        return time>n.time;
    }
};
void walking()
{
    memset(visit,0,sizeof(visit));
    priority_queue<node> Q;
    Q.push(node(0,0,0));
    visit[0][0]=1;
    mintime=0;
    while(!Q.empty())
    {
        node now=Q.top();
        if(now.x==n-1&&now.y==m-1) mintime=now.time;
        Q.pop();
        for(int i=1;i<=4;i++)
        {
            int x=now.x+dx[i];
            int y=now.y+dy[i];
            if(array[x][y]!='X'&&x>=0&&x<=n-1&&y>=0&&y<=m-1&&visit[x][y]==0)
            {
                visit[x][y]=1;
                path[x][y]=i;
                if(array[x][y]>='1'&&array[x][y]<='9')
                {
                    node next(x,y,now.time+array[x][y]-47);
                    Q.push(next);
                }
                else
                {
                    node next(x,y,now.time+1);
                    Q.push(next);
                } 
            }    
        }
    }
}
void print(int xpos,int ypos)
{
    if(path[xpos][ypos]==0) return;
    int x=xpos-dx[path[xpos][ypos]];
    int y=ypos-dy[path[xpos][ypos]];
    print(x,y);
    cout<<time++<<"s:("<<x<<","<<y<<")->("<<xpos<<","<<ypos<<")"<<endl;
    if(array[xpos][ypos]>='1'&&array[xpos][ypos]<='9')
    {
        int temp=array[xpos][ypos]-'0';
        while(temp--)
        {
            cout<<time++<<"s:FIGHT AT ("<<xpos<<","<<ypos<<")"<<endl;
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        string waste;
        getline(cin,waste);
        for(int i=0;i<n;i++)
        {
            string str;
            getline(cin,str);
            for(int j=0;j<m;j++)
            {
                array[i][j]=str[j];
            }  
        }
        walking();
         if(mintime) 
        {
            cout<<"It takes "<<mintime<<" seconds to reach the target position, let me show you the way."<<endl;
            time=1;
            print(n-1,m-1);
            cout<<"FINISH"<<endl;
        }
        else
        {
            cout<<"God please help our poor hero."<<endl;
            cout<<"FINISH"<<endl;
        }
    }

}