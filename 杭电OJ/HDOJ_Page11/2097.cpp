#include<iostream>
using namespace std;
bool judge(int num)
{
    int sum=0;
    int n=num;
    while(n/10!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    sum+=n%10;
    n=num;
    int sum1=0;
    while(n/16!=0)
    {
        sum1+=n%16;
        n=n/16;
    }
    sum1+=n%16;
    if(sum!=sum1) return false;
    else
    {
        int sum2=0;
        n=num;
        while(n/12!=0)
        {
            sum2+=n%12;
            n=n/12;
        }
        sum2+=n%12;
        if(sum2==sum) return true;
        else return false;
    }

}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            if(judge(n)==true) cout<<n<<" is a Sky Number."<<endl;
            else cout<<n<<" is not a Sky Number."<<endl;
        }

    }

}
