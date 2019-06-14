#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        if(str.length()==2)
        {
            cout<<str<<endl;
        }
        else if(str.length()==3)
        {
            reverse(str.begin(),str.end());
            cout<<str<<endl;
        }
    }
}