//p=1  * 2-9   1 < n < 4294967295  p >= n
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double n;
    while(cin>>n) //注意double 类型  不可整数%
    {
        while(n>18) n/=18;
        if(n<=9) cout<<"Stan wins."<<endl;
        else if(n>9) cout<<"Ollie wins."<<endl;
    }
}