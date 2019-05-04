#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int k;
    while(cin>>str>>k)
    {
        while(k--)
        {
            for(int i=0;i<str.length();i++)
            {
                if(str[i]>str[i-1]&&str[i]>str[i+1]) 
                {
                    str.erase(i,1);
                    break;
                }
            }
        }
        cout<<str<<endl;
    }
}