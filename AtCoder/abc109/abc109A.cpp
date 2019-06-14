#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    while(cin>>a>>b)
    {
        int flag=0;
        if(a>b) swap(a,b);
        for(int i=a;i<=b;i++)
        {
            if((i*a*b)%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}