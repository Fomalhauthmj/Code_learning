#include<iostream>
using namespace std;
int a,b,n;
int result[55]={0};
int  work(int a,int b)
{
    result[1]=1;
    result[2]=1;
    for(int i=3;i<=55;i++)
    {
        result[i]=(a*result[i-1]+b*result[i-2])%7;
        if(i>4)
        {
            if(result[i-1]==result[3]&&result[i]==result[4])
            {
                return i-4;
            }
        }
    }
}
int main()
{
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0&&n==0) break;
        else
        {
            int time=work(a,b);
            if((n-2)%time==0) cout<<result[time+2]<<endl;
            else cout<<result[(n-2)%time+2]<<endl;
        }
    }
}