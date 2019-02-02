#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    long long a,b,k;
    long long d;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>a>>b>>k;
            d=k%2;
            cout<<(a-b)*(k/2)+d*a<<endl;//奇加偶减
        }
    }
}