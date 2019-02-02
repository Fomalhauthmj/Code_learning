#include<iostream>
using namespace std;
#define size 1000010
long long a[size];
int n;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    long long nim=1;
    while(t--)
    {
        cin>>n;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]&1) flag=1;
        }
        if(flag==1) cout<<"xm"<<endl; //只要存在奇数 小明必胜
        else cout<<"xf"<<endl;
    }
}