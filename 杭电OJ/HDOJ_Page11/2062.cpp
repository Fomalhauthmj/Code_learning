#include<iostream>
using namespace std;
long long c[21]={0};
long long m;
int n;
int main()
{
    for(int i=1;i<=20;i++) c[i]=c[i-1]*(i-1)+1;
    while(cin>>n>>m)
    {
        int num[n+1]={0};
        for(int i=1;i<=n;i++) num[i]=i;
        int temp;
        while(m>0&&n>0)
        {
            int a=(m%c[n]==0)?0:1;
            temp=m/c[n]+a;
            if(temp>0)
            {
                cout<<num[temp];
                for(int i=temp;i<=n;i++) num[i]=num[i+1];
                m=m-(temp-1)*c[n]-1;
                if(m==0) cout<<endl;
                else cout<<" ";
            }
            n--;
        }
    }
}