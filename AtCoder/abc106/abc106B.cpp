#include<iostream>
using namespace std;
int judge(int n)
{
    int num=0;
    for(int i=1;i*i<n;i++)
    {
        if(n%i==0&&i*i!=n) num+=2;
        if(i*i==n) num++;
    }
    return num;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0) continue;
            if(judge(i)==8) ans++;
        }
        cout<<ans<<endl;
    }
}