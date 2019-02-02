#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define size 10010
int n,k;
double len[size];
double sub[size];
double judge(double mid)
{
    for(int i=0;i<n;i++) sub[i]=len[i];
    int num=0;
    for(int i=0;i<n;i++)
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
    if(num>=k) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        if(n==0&&k==0) break;
        for(int i=0;i<n;i++) 
        {
            cin>>len[i];
        }
        sort(len,len+n);
        double left=0.0;
        double right=len[n-1];
        double mid;
        while(left<=right)
        {
            if(fabs(left-right)<1e-4) break;
            mid=(right+left)/2;
            if(judge(mid)==true) left=mid;
            else right=mid;
        }
        cout<<fixed<<setprecision(2)<<left<<endl;
    }
}