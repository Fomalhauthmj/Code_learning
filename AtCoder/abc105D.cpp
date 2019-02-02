#include<iostream>
using namespace std;
#define max 100010
long long candy[max];
long long m;
int n;
long long num;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>num;
            candy[i]=num%m;
        }
        
    }
}