#include<iostream>
using namespace std;
int main()
{
    int n,u,d;
    while(cin>>n>>u>>d)
    {
        if(n==0) break;
        else
        {
            int time=0;
            int res;
            int sum=0;
            while(sum<n)
            {
                time++;
                sum+=u;
                if(sum>=n)
                {
                    res=time;
                }
                else
                {
                    sum-=d;
                    time++;
                }
            }
            cout<<res<<endl;
        }
    }
}