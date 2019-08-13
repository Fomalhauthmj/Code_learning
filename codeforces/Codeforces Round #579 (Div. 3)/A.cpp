#include<iostream>
using namespace std;
const int N=205;
int p[N*2],q,n;
bool Judge(int x)
{
    if(p[x]>p[x+1])
    {
        for(int i=1;i<n;i++)
            if(p[x+i]!=p[x+i-1]-1) return false;
    }
    else
    {
        for(int i=1;i<n;i++)
            if(p[x+i]!=p[x+i-1]+1) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    while(q--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            p[i+n]=p[i];
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(Judge(i))
            {
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}