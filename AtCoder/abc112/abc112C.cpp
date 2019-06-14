#include<iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
int x[N];
int y[N];
int h[N];
int cx,cy,H;
int n;
bool judge(int temp_h,int cx,int cy)
{
    int temp;
    for(int i=1;i<=n;i++)
    {
        temp=max(temp_h-abs(cx-x[i])-abs(cy-y[i]),0);
        if(temp!=h[i]) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>h[i];
        bool flag=false;
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                int temp_h;
                for(int k=1;k<=n;k++)
                {
                    if(h[k]!=0)
                    {
                        temp_h=h[k]+abs(i-x[k])+abs(j-y[k]);
                        break;
                    }
                }
                if(judge(temp_h,i,j))
                {
                    flag=true;
                    H=temp_h;
                    cx=i;cy=j;
                    break;
                }
            }
            if(flag) break;
        }
        cout<<cx<<" "<<cy<<" "<<H<<endl;
    }
}