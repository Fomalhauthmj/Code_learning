#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    for(int i=1;i<=10000;i++)
    {
        long long temp=pow(i,3);
        string str=to_string(i);
        int len=str.length();
        if(temp%(long long)pow(10,len)==i) 
        {
            cout<<i<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    system("pause");
    //ans=36
}