#include<iostream>
#include<string>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            if(str[i]<='Z') str[i]+=32;
        }
        if(str=="jessie") cout<<"Good guy!"<<endl;
        else cout<<"Dare you say that again?"<<endl;
    }
}