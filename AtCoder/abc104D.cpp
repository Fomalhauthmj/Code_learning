#include<iostream>
using namespace std;
long long ch[4]={0};
int main()
{
    string str;
    while(cin>>str)
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='?') ch[0]++;
            else if(str[i]=='A') ch[1]++;
            else if(str[i]=='B') ch[2]++;
            else if(str[i]=='C') ch[3]++;
        }
    }
}