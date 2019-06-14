#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    long long k;
    while(cin>>s>>k)
    {
        char ch='1';
        int pos=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='1') 
            {
                ch=s[i];
                pos=i+1;
                break;
            }
        }
        if(k>=pos) cout<<ch<<endl;
        else cout<<1<<endl;
    }
}