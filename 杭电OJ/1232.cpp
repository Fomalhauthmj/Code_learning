#include<iostream>
#include<stdio.h>
using namespace std;
#define max 1010
int pre[max];
int answer;
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        pre[i]=i;
    }
    answer=0;
}
int find(int x)
{
    if(pre[x]==x) return x;
    else return pre[x]=find(pre[x]);
}
void myunion(int x,int y)
{
    int pre1=find(x);
    int pre2=find(y);
    if(pre1!=pre2)
    {
        pre[pre1]=pre2;
        answer++;
    }
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            cin>>m;
            init(n);
            for(int i=1;i<=m;i++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                myunion(a,b);
            }
            if(answer>n-1) cout<<0<<endl;
            else cout<<n-1-answer<<endl;
        }
    }

}