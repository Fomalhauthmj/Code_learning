#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int minresult=999;
        int result[7]={0};
        result[1]=abs(a-c)+abs(c-b);
        result[2]=abs(a-b)+abs(b-c);
        result[3]=abs(b-a)+abs(a-c);
        result[4]=abs(b-c)+abs(c-a);
        result[5]=abs(c-a)+abs(a-b);
        result[6]=abs(c-b)+abs(b-a);
        for(int i=1;i<=6;i++)
            if(minresult>result[i])
        {
            minresult=result[i];
        }
        cout<<minresult<<endl;
    }
}
