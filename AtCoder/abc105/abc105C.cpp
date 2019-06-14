#include<iostream>
#include<algorithm>
using namespace std;
string result(long long num)
{
    string res;
    int temp=0;
    long long number=num;
    while(num!=0)
    {
        temp=num%-2;
        if(temp<0) 
        {
            temp=temp+2;
            num=num/-2+1;
        }
        else
        {
            num=num/-2;
        }
        res.append(to_string(temp));
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    long long num;
    while(cin>>num)
    {
        if(num==0) cout<<0<<endl;
        else cout<<result(num)<<endl;
    }
}