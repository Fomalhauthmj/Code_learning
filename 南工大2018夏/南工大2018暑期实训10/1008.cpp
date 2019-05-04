#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 1010
string a,b;
int pre[size];
int cur[size];
int LCS()
{
    memset(pre,0,sizeof(pre));
    memset(cur,0,sizeof(cur));
    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            if(a[i]==b[j]) cur[j+1]=pre[j]+1;
            else
            {
                cur[j+1]=max(pre[j+1],cur[j]);
            }
        }
        for(int j=1;j<=b.length();j++) pre[j]=cur[j];
    }
    return cur[b.length()];
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        cout<<LCS()<<endl;
    }
}