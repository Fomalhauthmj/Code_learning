#include<iostream>
#include<cstring>
using namespace std;
//离散化  2n-1 2n  -> n(1-200)
int room[201]={0};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(room,0,sizeof(room));
        int n;
        cin>>n;
        int a,b;
        int c1,c2;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            if(a>b)
            {
                c2=a%2==0?a/2:(a+1)/2;
                c1=b%2==0?b/2:(b+1)/2;
            }
            else 
            {
                c1=a%2==0?a/2:(a+1)/2;
                c2=b%2==0?b/2:(b+1)/2;
            }
            for(int j=c1;j<=c2;j++) room[j]++;
        }
        int max=0;
        for(int i=1;i<=200;i++)
        {
            if(room[i]>max)
            {
                max=room[i];
            }
        }
        cout<<max*10<<endl;
    }
}