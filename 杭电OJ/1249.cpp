#include<iostream>
using namespace std;
int res[10010];
int main()
{
    res[1]=2;
    for(int i=2;i<=10000;i++)
    {
        res[i]=res[i-1]+6*(i-1);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}