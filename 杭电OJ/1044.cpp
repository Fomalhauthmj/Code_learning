#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char dungeon[51][51];
bool visit[51][51];
int value[11]={0};
int w,h,l,m;
int startx,starty;
struct node
{
    int x;
    int y;
    int time;
    node(int x1,int x2,int x3)
    {
        x=x1,y=x2,time=x3;
    }
};
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>w>>h>>l>>m;
        for(int j=1;j<=m;j++) cin>>value[j];
        for(int j=1;j<=h;j++)
        {
            for(int k=1;k<=w;k++)
            {
                char ch=getchar();
                dungeon[j][k]=ch;
                if(ch=='@')
                {
                    startx=j;
                    starty=k;
                }
            }
        }
        for(int j=1;j<=h;j++)
        {
            for(int k=1;k<=w;k++)
            {
                cout<<dungeon[j][k];
            }
            cout<<endl;
        }
    }
}