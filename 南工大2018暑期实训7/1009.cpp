#include<iostream>
using namespace std;
int n,m;
struct node
{
    int pre;
};
node b[4040];
void init(int n)
{
    for(int i=1;i<=2*n;i++)
    {
        b[i].pre=i;
    }
}
int Find(int x)
{
    if(b[x].pre==x) return x;
    b[x].pre=Find(b[x].pre);
    return b[x].pre;
}
void Union(int x,int y)
{
    int p1=Find(x);
    int p2=Find(y);
    if(p1!=p2)
    { 
        if(p1>p2) b[p1].pre=p2;
        else b[p2].pre=p1; //限制规则
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int left,right;
    for(int i=1;i<=t;i++)
    {
        int flag=0;
        cin>>n>>m;
        init(n);
        for(int i=0;i<m;i++)
        {
            cin>>left>>right;
            if(b[left].pre==b[right].pre) flag=1;  //可疑的行为
            else
            {
                Union(left,right+n);  //right+n表示可与right交配
                Union(right,left+n);  //left+n表示可与left交配
            }
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        if(flag==1) cout<<"Suspicious bugs found!"<<endl<<endl;
        else cout<<"No suspicious bugs found!"<<endl<<endl;
    }
}