#include<iostream>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n<=2) 
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int k=(n%2==0)?(n/2):(n+1)/2;
        cout<<"1 "<<k<<endl;
        cout<<n-1;
        for(int i=1;i<=n;i++)
        {
            if(i==k) continue;
            else cout<<" "<<i;
        }
        cout<<endl;
    }
}