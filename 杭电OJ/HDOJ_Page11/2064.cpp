#include<iostream>
using namespace std;
int main()
{
    long long res[36];
    res[1]=2;
    for(int i=2;i<=35;i++) res[i]=3*res[i-1]+2;
    int n;
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
}
