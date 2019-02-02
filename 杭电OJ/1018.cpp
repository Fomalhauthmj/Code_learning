#include<iostream>
#include<math.h>
using namespace std;
int result(int num)
{
    double sum=1;
    for(int i=1;i<=num;i++)
    {
        sum+=log10(i);
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        cout<<result(num)<<endl;
    }
}