#include<iostream>
using namespace std;
int dx[9]={0,1,0,-1,0,1,1,-1,-1};
int dy[9]={0,0,1,0,-1,1,-1,1,-1};
char board[9][9];
bool visit[9][9]={0};
struct point
{
    int x;
    int y;
    point(int n1,int n2){
        x=n1,y=n2;
    }
};
int walking(int startx,int starty)
{
    int sum=0;
    queue<point> Q;
    Q.push(point(startx,starty));
    memset(visit,0,sizeof(visit));
    while(Q.empty()==false)
    {
        point now=Q.front();
        Q.pop();
        visit[now.x][now.y]=1;
        for(int i=1;i<=8;i++)
        {
            if(visit[now.x+dx[i]][now.y+dy[i]]==0&&board[now.x+dx[i]][now.y+dy[i]]=='.'&&now.x+dx[i]>=1&&now.x+dx[i]<=8&&now.y+dy[i]>=1&&now.y+dy[i]<=8)
            {
                Q.push(point(now.x+dx[i],now.y+dy[i]));
            }
        }
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++)
            if(visit[i][j]==1) sum++;
    }
    return sum;
}
int main()
{
    ifstream cin("test.txt");
    int n;
    cin>>n;
    string waste;
    getline(cin,waste);
    int startx,starty;
    while(n--)
    {
        for(int i=1;i<=8;i++){
            string str;
            getline(cin,str);
            for(int j=1;j<=8;j++){
                board[i][j]=str[j-1];
                if(str[j-1]=='K'){
                    startx=i;
                    starty=j;
                }
            }
        }
        getline(cin,waste);
        cout<<walking(startx,starty)<<endl;
    }
    return 0;
}
