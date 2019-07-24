#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int a=1;a<=9;a++)
    {
        for(int b=0;b<10;b++)
        {
            if(a==b) continue;
            for(int c=0;c<10;c++)
            {
                if(a==c||b==c) continue;
                for(int d=0;d<10;d++)
                {
                    if(a==d||b==d||c==d) continue;
                    for(int e=0;e<10;e++)
                    {
                        if(a==e||b==e||c==e||d==e) continue;
                        for(int f=0;f<10;f++)
                        {
                            if(a==f||b==f||c==f||d==f||e==f) continue;
                            long long num=100000*a+10000*b+1000*c+100*d+10*e+f;
                            long long temp=num*num;
                            bool flag=true;
                            while(temp)
                            {
                                int bit=temp%10;
                                if(bit==a||bit==b||bit==c||bit==d||bit==e||bit==f)
                                {
                                    flag=false;
                                    break;
                                }
                                temp/=10;
                            }
                            if(flag) cout<<num<<endl;
                        }
                    }
                }
            }
        }
    }
    system("pause");
    //203879
//639172
}