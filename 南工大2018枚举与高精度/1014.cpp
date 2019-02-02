#include<iostream>
using namespace std;
#define maxsize 101010
int res[maxsize];
int digit;
void result(int n)
{
    digit=1;
    int num;
    res[0]=1;
    int temp;
    for(int i=2;i<=n;i++)
    {
        num=0;
        for(int j=0;j<digit;j++)
        {
            temp=res[j]*i+num;
            res[j]=temp%10;
            num=temp/10;
        }
        while(num)
        {
            res[digit++]=num%10;
            num=num/10;
        }
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<1<<endl;
            continue;
        }
        result(n);
        for(int i=digit-1;i>=0;i--)
            cout<<res[i];
        cout<<endl;
    }
}