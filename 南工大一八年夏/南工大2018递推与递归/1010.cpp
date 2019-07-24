#include<iostream>
using namespace std;
long long res[45]={0};
int main()
{
    res[1]=3;
    res[2]=9;
    for(int i=3;i<=40;i++)
    {
        res[i]=2*res[i-1]+res[i-2];
    }
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}