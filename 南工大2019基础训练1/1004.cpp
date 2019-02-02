#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=1;
    for(int i=10;i<=99;i++)
    {
        if(i-27>0)
        {
            int c1=i%10;
            int c2=i/10;
            if(c1*10+c2==i-27)
            {
                cout<<cnt++<<" "<<i<<endl;
            }
        }
    }
    system("pause");
    /*
1 30
2 41
3 52
4 63
5 74
6 85
7 96
    */
}