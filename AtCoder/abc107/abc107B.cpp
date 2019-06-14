#include<iostream>
using namespace std;
#define size 105
string a[105];
int lookingr(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        int flag1=0;
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!='.') 
            {
                flag1=1;
                break;
            }
        }
        if(flag1==0) return i;
    }
    return -1;
}
int lookingc(int r,int c)
{
    for(int j=0;j<c;j++)
    {
        int flag2=0;
        for(int i=0;i<r;i++)
        {
            if(a[i][j]!='.')
            {
                flag2=1;
                break;
            }
        }
        if(flag2==0) return j;
    }
    return -1;
}
void DFS(int r,int c)
{
    int targetr=lookingr(r,c);
    int targetc=lookingc(r,c);
    if(targetr>=0||targetc>=0)
    {
        if(targetc<0&&targetr>=0)
        {
            for(int i=targetr;i<r-1;i++)
            {
                a[i]=a[i+1];
            }
            DFS(r-1,c);
        }
        else if(targetc>=0&&targetr<0)
        {
            for(int i=0;i<r;i++)
            {
                a[i].erase(targetc,1);
            }
            DFS(r,c-1);
        }
        else
        {
            for(int i=targetr;i<r-1;i++)
            {
                a[i]=a[i+1];
            }
            for(int i=0;i<r-1;i++)
            {
                a[i].erase(targetc,1);
            }
            DFS(r-1,c-1);
        }
    }
    else
    {
        for(int i=0;i<r;i++) cout<<a[i]<<endl;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int h,w;
    while(cin>>h>>w)
    {
        for(int i=0;i<h;i++)
        {
            cin>>a[i];
        }
        DFS(h,w);
    }
}