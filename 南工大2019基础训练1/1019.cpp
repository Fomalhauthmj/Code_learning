#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //a+b+c+d=50 100 50  10 5= 2000
    int cnt=0;
    for(int a=0;a<=50;a++)
    {
        for(int b=0;b<=50;b++)
        {
            for(int c=0;c<=50;c++)
            {
                for(int d=0;d<=50;d++)
                {
                    if(a+b+c+d==50&&100*a+50*b+10*c+5*d==2000)
                    {
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    system("pause");//50
}