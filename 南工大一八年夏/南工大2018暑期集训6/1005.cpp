#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define pi acos(-1.0)
#define size 10010
int N,F;
double area[size];
double sub[size];
double r;
bool judge(double mid)
{
    int num=0;
    for(int i=0;i<N;i++) sub[i]=area[i];
    for(int i=0;i<N;i++)
    {
        if(sub[i]>=mid)
        {
            while(sub[i]>=mid)
            {
                sub[i]-=mid;
                num++;
            }
        }
        else continue;
    }
    if(num>=F+1) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>N>>F;
        for(int i=0;i<N;i++) 
        {
            cin>>r;
            area[i]=pi*r*r;
        }
        sort(area,area+N);
        double left=0.0;
        double right=area[N-1];
        double mid;
        while(left<=right)
        {
            if(fabs(left-right)<=1e-7) break;
            mid=(left+right)/2;
            if(judge(mid)==true) left=mid;
            else right=mid;
        }
        cout<<fixed<<setprecision(4)<<left<<endl;
    }
}