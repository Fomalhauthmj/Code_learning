#include<iostream>
#include<math.h>
using namespace std;
int res[1001]={0};
int main()
{
    res[1]=2;
    for(int i=2;i<1001;i++)
    {
       res[i]=res[i-1]+(i-1)*i*0.5+1;
    }
    int n;
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
}