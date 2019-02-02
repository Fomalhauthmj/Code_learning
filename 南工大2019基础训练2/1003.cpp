#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1900;i<=2014;i++)
    {
        int temp=2014-i;
        if(temp<=0) continue;
        int num=i;
        int sum=0;
        while(num)
        {
            sum=sum+num%10;
            num/=10;
        }
        sum+=num%10;
        if(sum==temp) cout<<i<<endl;
    }
    system("pause");
    //2006 1988
}