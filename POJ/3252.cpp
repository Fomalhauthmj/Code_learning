#include<iostream>
#include<string>
using namespace std;
int main()
{
    int start,finish;
    while(cin>>start>>finish)
    {
        for(int i=start;i<=finish;i++)
        {
            string str;
            int inpos=0;
            while(i/2!=1)
            {
                str[inpos++]=(i%2==0)?'0':'1';
                i/=2;
            }
            str[inpos]='1';
            cout<<str<<endl;
        }
    }
}