#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int d;
    while(cin>>d)
    {
        if(d==22)
        {
            cout<<"Christmas Eve Eve Eve"<<endl;
        }
        else if(d==23)
        {
            cout<<"Christmas Eve Eve"<<endl;
        }
        else if(d==24)
        {
            cout<<"Christmas Eve"<<endl;
        }
        else
        {
            cout<<"Christmas"<<endl;
        }
    }
}