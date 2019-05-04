#include<iostream>
using namespace std;
int main()
{
    int n;
    int up=6;
    int down=4;
    int wait=5;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            int sum=0;
            sum+=n*wait;
            int pre=0;
            while(n--)
            {
                int now;
                cin>>now;
                sum+=(now-pre)>0?(now-pre)*up:(pre-now)*down;
                pre=now;
            }
            cout<<sum<<endl;
        }
    }
}