#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    for(int i=10000;i<=99999;i++)
    {
        string str=to_string(i);
        if(str.find('4')!=string::npos) cout<<i<<endl;
        else cnt++;
    }
    cout<<cnt<<endl;
    system("pause");
    //52488
}