#include<iostream>
using namespace std;
#define N 100010
long long ai;
long long ans;
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>ai;
            if(i!=0)    ans^=ai;
            else ans=ai;//拆分后异或结果<=不拆分异或结果 
        }
        if(ans==0) cout<<"Lose"<<endl;
        else cout<<"Win"<<endl;
    }
}