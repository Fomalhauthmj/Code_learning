#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long l[60];
    l[0]=1;
    l[1]=3;
    for(int i=2;i<60;i++)
    {
        l[i]=l[i-1]+l[i-2];
    }
    double pi=0.618034;
    for(int i=0;i<60-1;i++)
    {
        double temp=l[i]*1.0/l[i+1];
        cout<<l[i]<<"/"<<l[i+1]<<" "<<temp<<endl;//1364/2207
    }
    system("pause");
}