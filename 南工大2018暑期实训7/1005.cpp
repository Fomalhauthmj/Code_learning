#include<iostream>
using namespace std;
#define max 10010
int pre[max];
int answer;
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
        answer++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        answer=0;
        for(int i=0;i<=n;i++)
        {
            pre[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            myunion(a,b);
        }
        cout<<n-answer<<endl;
    }
}