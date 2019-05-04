#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //1=1
    //1 3=4
    //1 3 5=9
    //1 3 5 7=16
    //1 3 5 7 9=25
    //1111^3  ->1169^2
    long long temp=1367631;
    for(int i=1;i<1200;i++)
    {
        for(int j=i+1;j<1200;j++)
        {
            if(j*j-i*i==temp)
            {
                cout<<i<<" "<<j<<endl;
            }//185 1184  185*2-1=369  371
        }
    }
    system("pause");
}