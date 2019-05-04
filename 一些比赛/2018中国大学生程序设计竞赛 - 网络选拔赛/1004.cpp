#include<iostream>
using namespace std;
long long b,c;
void result(int a)
{
    if(a%2)
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    long long n,int a;
    while(t--)
    {
        cin>>n>>a;
        if(n>2||n==0)
        {
            cout<<-1<<" "<<-1<<endl;
            continue;
        }
        else
        {
            if(n==1)
            {
               cout<<1<<" "<<a+1<<endl;
            }
            else if(n==2)
            {
                result(a);
            }
        }
    }
}