#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str)
    {
        int ans=inf;
        int len=str.length();
        for(int i=0;i<=len-3;i++)
        {
            int temp=stoi(str.substr(i,3));
            ans=min(ans,abs(temp-753));
        }
        cout<<ans<<endl;
    }
}