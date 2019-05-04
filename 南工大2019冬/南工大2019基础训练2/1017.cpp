//C[52][13]
//1 2 3 4 5 6 7 8 9 10 11 12 13 *4
#include<iostream>
#include<cstring>
using namespace std;
long long kinds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    kinds=0;
    for(int a=0;a<=4;a++)
    {
        for(int b=0;b<=4;b++)
        {
            for(int c=0;c<=4;c++)
            {
                for(int d=0;d<=4;d++)
                {
                    if(a+b+c+d>13) continue;
                    for(int e=0;e<=4;e++)
                    {
                        if(a+b+c+d+e>13) continue;
                        for(int f=0;f<=4;f++)
                        {
                            if(a+b+c+d+e+f>13) continue;
                            for(int g=0;g<=4;g++)
                            {
                                if(a+b+c+d+e+f+g>13) continue;
                                for(int h=0;h<=4;h++)
                                {
                                    if(a+b+c+d+e+f+g+h>13) continue;
                                    for(int i=0;i<=4;i++)
                                    {
                                        if(a+b+c+d+e+f+g+h+i>13) continue;
                                        for(int j=0;j<=4;j++)
                                        {
                                            if(a+b+c+d+e+f+g+h+i+j>13) continue;
                                            for(int k=0;k<=4;k++)
                                            {
                                                if(a+b+c+d+e+f+g+h+i+j+k>13) continue;
                                                for(int l=0;l<=4;l++)
                                                {
                                                    if(a+b+c+d+e+f+g+h+i+j+k+l>13) continue;
                                                    for(int m=0;m<=4;m++)
                                                    {
                                                        if(a+b+c+d+e+f+g+h+i+j+k+l+m!=13) continue;
                                                        else kinds++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
    cout<<kinds<<endl;//3598180
    system("pause");
}