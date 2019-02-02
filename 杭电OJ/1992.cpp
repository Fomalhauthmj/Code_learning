#include<iostream>
using namespace std;
#define max 1010
long long res[max]={0};
int main()
{  
    res[0]=1;
    res[1]=1;
    res[2]=5;
    res[3]=11;
    for(int i=4;i<max;i++)
    {
        res[i]=res[i-1]+5*res[i-2]+res[i-3]-res[i-4];
    }
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            int num;
            cin>>num;
            cout<<i<<" "<<res[num]<<endl;
        }
    }
}

