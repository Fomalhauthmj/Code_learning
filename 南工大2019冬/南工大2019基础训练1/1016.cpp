#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long ans=0;
    for(int i=1;i<=100;i++)
    {
        ans+=(i*(i+1))/2;
    }
    cout<<ans<<endl;
    system("pause");
    //171700
}