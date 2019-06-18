#include <iostream>
#include<algorithm>
using namespace std;
const int N = 510;
struct node
{
    int ti,wi;
    bool operator<(const node &n) const
    {
        if(wi!=n.wi) return wi>n.wi;
        return ti>n.ti;
    }
};
int m,n;
node ns[N];
bool t[N];
bool judge(int x)
{
    for(int i=ns[x].ti;i>=1;i--)
    {
        if(!t[i])
        {
            t[i]=1;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ns[i].ti;
    }
    for(int i=0;i<n;i++)
    {
        cin>>ns[i].wi;
    }
    sort(ns,ns+n);
    for(int i=0;i<n;i++)
    {
        if(!judge(i))
            m-=ns[i].wi;
    }
    cout<<m<<endl;
    //system("pause");
    return 0;
}