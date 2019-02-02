#include<iostream>
#include<string>
using namespace std;
int result(string n)
{
    int sum=0;
    for(int i=0;i<n.length();i++)
        sum+=n[i]-'0';
    if(sum<=9) return sum;
    else return result(to_string(sum));
}
int main()
{
    string n;
    while(cin>>n)
    {
        if(n=="0") break;
        else
        {
            cout<<result(n)<<endl;
        }
    }
    return 0;
}