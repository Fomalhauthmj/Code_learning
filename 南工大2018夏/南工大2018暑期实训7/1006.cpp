#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
#define max 100010
int link;
bool visit[max]={0};
int count;
int pre[max];
void init(int size)
{
    for(int i=0;i<size;i++)
    {
      pre[i]=i;
    }
    link=0;
    count=0;
    memset(visit,0,sizeof(visit));
}
int find(int x)
{
    if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}
void myunion(int x,int y)
{
    int pre1=find(x);
    int pre2=find(y);
    if(pre1!=pre2)
    {
        pre[pre1]=pre2;
    }
}
int main()
{
    int a,b;
    init(max);
    while(scanf("%d%d",&a,&b))
    {
        if(a==-1&&b==-1) break;
        if(a==0&&b==0)
        {
            if(link+1==count)
            {
                int sum=0;
                for(int i=1;i<max;i++)
                {
                    if(visit[i]&&pre[i]==i) sum++;//判断根结点 
                }
                if(sum==1) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else if(link==0&&count==0) cout<<"Yes"<<endl; 
            else cout<<"No"<<endl;
            init(max);
        }
        else
        {
            if(visit[a]==false)
            {
                visit[a]=true;
                count++;
            }
            if(visit[b]==false)
            {
                visit[b]=true;
                count++;
            }
            link++;
            myunion(a,b);
        }
    }
    return 0;
}