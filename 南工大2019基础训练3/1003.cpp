#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int a=1;a<=9;a++)
    {
        for(int b=0;b<=9;b++)
        {
            if(a==b) continue;
            for(int c=0;c<=9;c++)
            {
                if(a==c||b==c) continue;
                for(int d=0;d<=9;d++)
                {
                    if(a==d||b==d||c==d) continue;
                    for(int e=1;e<=9;e++)
                    {
                        if(a==e||b==e||c==e||d==e) continue;
                        for(int x=1;x<=9;x++)
                        {
                            int temp=10000*a+1000*b+100*c+10*d+e;
                            temp*=x;
                            int right=10000*e+1000*d+100*c+10*b+a;
                            if(temp==right) cout<<temp/x<<endl;
                        }
                    }
                }
            }
        }
    }
    system("pause");//21978
}