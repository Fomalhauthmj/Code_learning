#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if((a*b*c)%2==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}