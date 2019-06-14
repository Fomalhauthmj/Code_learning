#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string n;
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n.length();i++)
        {
            if(n[i]=='1') n[i]='9';
            else if(n[i]=='9') n[i]='1';
            else continue;
        }
        cout<<n<<endl;
    }
}