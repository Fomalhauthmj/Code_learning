#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x=10;
    long long y=89;
    for(int i=1;i<=120;i++)
    {
        if(y<=0) y=0;
        if(i==1) y-=x;
        else if(i&1) y-=x;
        if(i%6==0) x*=2;
        if(i%4==0) y*=2;
    }
    cout<<x<<" "<<y<<endl;

    x=10;
    y=90;
    for(int i=1;i<=120;i++)
    {
        if(y<=0) y=0;
        if(i==1) y-=x;
        else if(i&1) y-=x;
        if(i%6==0) x*=2;
        if(i%4==0) y*=2;
    }
    cout<<x<<" "<<y<<endl;
    system("pause");
    //10485760 0
    //10485760 94371840
}