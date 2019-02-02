#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int dx,dy;
    while(cin>>x1>>y1>>x2>>y2)
    {
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        dx=abs(x1-x2);
        dy=abs(y1-y2);
        if(x1<=x2&&y1>=y2)
        {
            x3=x2+dy;
            y3=y2+dx;
            x4=x1+dy;
            y4=y1+dx;
        }
        else if(x2>=x1&&y2>=y1)
        {
            x3=x2-dy;
            y3=y2+dx;
            x4=x1-dy;
            y4=y1+dx;
        }
        else if(x1>=x2&&y1>=y2)
        {
            x3=x2+dy;
            y3=y2-dx;
            x4=x1+dy;
            y4=y1-dx;
        }
        else if(x1>=x2&&y2>=y1)
        {
             x3=x2-dy;
             y3=y2-dx;
             x4=x1-dy;
             y4=y1-dx;
        }
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    }
}