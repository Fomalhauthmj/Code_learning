#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        if(str=="end") break;
        else
        {
            int flag=0;
            int vowelnum=0;
            for(int i=0;i<str.length();i++)
            {
                if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') vowelnum++;
            }
            if(vowelnum<1) flag=1;
            int vnum=0;int cnum=0;
            for(int i=0;i<str.length();i++)
            {
                
                if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                { 
                    cnum=0;
                    vnum++;
                    if(vnum==3)
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    vnum=0;   
                    cnum++;
                    if(cnum==3)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            for(int i=0;i<str.length()-1;i++)
            {
                if(str[i+1]==str[i]&&str[i]!='e'&&str[i]!='o')
                {
                    flag=1;
                    break;
                }
            }
            cout<<"<"<<str<<">";
            if(flag==1)
            {
                cout<<" is not acceptable."<<endl;
            }
            else cout<<" is acceptable."<<endl;
        }
    }
    return 0;
}