#include<iostream>
#include<algorithm>
using namespace std;
#define max 202
int a[max]={0};
int b[max]={0};
int n,m;
int main()
{   
    int t;
    for(int i=0;i<m;i++)
    {
        cin>>t;
        a[t]=1;
    }
    int cnt=0;
    int flag=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]==0)
        {
            b[cnt]++;
            flag=1;
        }
        else
        {
            if(flag) cnt++;
            flag=0;
        }
    }
    if(a[n-1]==0) cnt++;
    sort(b,b+cnt,greater<int>());
}