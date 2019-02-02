#include<iostream>
#include<cmath>
using namespace std;
int res[65]={0};
int main()
{
    res[0]=0;
    res[1]=1;
    for(int i=2;i<65;i++)
    {
        int min=99999;
        for(int j=1;j<i;j++)
        {
            if(2*res[j]+pow(2,i-j)-1<min)
                min=2*res[j]+pow(2,i-j)-1;
        }
        res[i]=min;
    }
    int n;
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
}