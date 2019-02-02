//模拟
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define N 1010
long long dis[2*N][2*N];
void init()
{
    memset(dis,0,sizeof(dis));
    int cur_x,cur_y;
    int step=1;
    cur_x=1000,cur_y=1000;
    bool cur_dir=false;
    while(abs(cur_x)<N&&abs(cur_y)<N)
    {
        if(!cur_dir)
        {
        for(int i=1;i<=step;i++) 
        {
            dis[cur_x-i][cur_y]=dis[cur_x][cur_y]+i;//向左
            cout<<"left"<<cur_x-i<<" "<<cur_y<<" "<<dis[cur_x-i][cur_y]<<endl;
        }
        cur_x=cur_x-step;
        for(int i=1;i<=step;i++) 
        {
            dis[cur_x][cur_y-i]=dis[cur_x][cur_y]+i;//向上
            cout<<"up"<<cur_x<<" "<<cur_y-i<<" "<<dis[cur_x][cur_y-i]<<endl;
        }
        cur_y=cur_y-step;
        cur_dir=true;
        }
        else
        {
        for(int i=1;i<=step;i++) 
        {
            dis[cur_x+i][cur_y]=dis[cur_x][cur_y]+i;//向右
            cout<<"right"<<cur_x+i<<" "<<cur_y<<" "<<dis[cur_x+i][cur_y]<<endl;

        }
        cur_x=cur_x+step;
        for(int i=1;i<=step;i++) 
        {
            dis[cur_x][cur_y+i]=dis[cur_x][cur_y]+i;//向下
            cout<<"down"<<cur_x<<" "<<cur_y+i<<" "<<dis[cur_x][cur_y+i]<<endl;
        }
        cur_y=cur_y+step;
        cur_dir=false;
        }
        step++;
    }
}
//对于拐点（x,y) |x|==|y|
//右上角 4x^2
//左上角 4x^2-
//左下角 4x^2-  
//右下角 4x^2+2x
//上线 y>0 -y<=x<=y
//下线 y<0 -y<=x<=y
//左线 x<0 -x<=y<=x
//右线 x>0 -x<=y<=x
long long solve(long long x,long long y)
{
    if(y>0&&x>=-y&&y>=x)
    {
        //找右上点
        long long dis=4*y*y-(y-x);
        return dis;
    }
    else if(y<0&&x<=-y&&y<=x)
    {
        //找右下点
        long long dis=4*y*y-2*y+(-y-x);
        return dis;
    }
    else if(x<0&&-x>=y&&y>=x)
    {
        //找左上点
        long long dis=4*x*x+2*x-(-x-y);
        return dis;

    }
    else if(x>0&&-x<=y&&y<=x)
    {
        //找右上点
        long long dis=4*x*x+(x-y);
        return dis;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //init();
    int x,y;
    while(cin>>x>>y)
    {
        //cout<<dis[x+1000][1000-y]
        cout<<" "<<solve(x,y)<<endl;
    }
}