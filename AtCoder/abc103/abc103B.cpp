#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,t;
    while(cin>>s>>t)
    {
        int flag=1;
        for(int i=1;i<=s.length();i++)
        {
            char temp=s[s.length()-1];
            s.insert(0,1,temp);
            s.erase(s.end()-1);
            if(s==t)
            {
                flag=0;
                break;
            }
        }
        if(flag==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
