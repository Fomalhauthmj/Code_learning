#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        int flag=0;
        int sum=0;
        int num=0;
        if(str[0]!='A') flag=1;
        for(int i=2;i<=str.length()-2;i++)
        {
            if(str[i]=='C')
            {
                sum++;
            }
        }
        if(sum!=1) flag=1;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]<'a'||str[i]>'z') num++;
        }
        if(num!=2) flag=1;
        if(flag==0) cout<<"AC"<<endl;
        else cout<<"WA"<<endl;
    }
}