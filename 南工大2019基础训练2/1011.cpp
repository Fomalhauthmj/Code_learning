#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int a=0;a<=100;a++)
    {
        for(int b=0;b<=100;b++)
        {
            for(int c=0;c<=100;c++)
            {
                if(3*a+7*b+c==315&&4*a+10*b+c==420)
                {
                    cout<<a+b+c<<endl;
                }
            }
        }
    }
    system("pause");//105
}