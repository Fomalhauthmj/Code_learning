#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x;
    while(cin>>x)
    {
        if(x==7||x==5||x==3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}