#include<iostream>
#include<iomanip>
using namespace std;
int  step(int n)
{
    int res=1;
    for(int i=1;i<=n;i++) res*=i;
    return res;
}

int main()
{
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    double result[10]={0};
    result[0]=1;
    for(int i=1;i<10;i++) 
    {
        result[i]=result[i-1]+1.0/step(i);
    }
    cout<<0<<" "<<result[0]<<endl;
    cout<<1<<" "<<result[1]<<endl;
    cout<<2<<" "<<result[2]<<endl;
    for(int i=3;i<10;i++)
    {
        cout<<i<<" "<<fixed<<setprecision(9)<<result[i]<<endl;
    }
}