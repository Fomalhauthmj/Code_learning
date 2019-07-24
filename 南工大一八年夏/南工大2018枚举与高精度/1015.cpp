#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int mod;
    while(cin>>str>>mod)
    {
        int ans=0;
        int sum=0;
        for(int i=0;i<str.length();i++)
        {
            ans=(ans*10+str[i]-'0')%mod;
        }
        cout<<ans<<endl;
    }
}