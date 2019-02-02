#include<iostream>
#include<iomanip>
#include<queue>
#include<math.h>
using namespace std;
#define max 10001
int m,n;
double f[max],j[max];
struct node
{
    double f;
    double j;
    double ratio;
    node(double f1,double f2)
    {
        f=f1;j=f2;
        ratio=j/f;
    }
    bool operator<(const node &n) const
    {
        return ratio<n.ratio;
    }
};
double result()
{
    double jsum=0;
    double fsum=m;
    priority_queue<node> Q;
    for(int i=1;i<=n;i++) Q.push(node(f[i],j[i]));
    while(!Q.empty())
    {
        node maxratio=Q.top();
        Q.pop();
        if(fsum>=maxratio.f)
        {
            fsum-=maxratio.f;
            jsum+=maxratio.j;
        }
        else
        {
            jsum+=maxratio.ratio*fsum;
            fsum=0;
        }
    }
    return jsum;
}
int main()
{
    while(cin>>m>>n)
    {
        if(m==-1&&n==-1) break;
        else
        {
            for(int i=1;i<=n;i++) cin>>j[i]>>f[i];
            cout<<fixed<<setprecision(3)<<result()<<endl;
        }
    }
}
