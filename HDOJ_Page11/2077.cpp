#include<iostream>
using namespace std;
int main()
{
    long long res[21]={0};
    res[1]=2;
    for(int i=2;i<=20;i++) res[i]=3*res[i-1]-2;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}
