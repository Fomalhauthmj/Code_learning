#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double ans=0;
    double temp;
    while(1)
    {
        char ch;
        for(int i=0;i<5;i++) ch=getchar();
        cin>>temp;
        cout<<temp<<endl;
        ch=getchar();
        ch=getchar();
        int count;
        if(ch>='0'&&ch<='9')
        {
            count=(ch-'0')*10;
            ch=getchar();
            if(ch>='0'&&ch<='9')
            {
                count+=ch-'0';
                ans+=temp*count/100;
                ch=getchar();
            }
            else ans+=temp*count/100;
        }
        else
        {
            ch=getchar();
            ch=getchar();
            ans+=temp*0.5;
        }
        cout<<"cur:"<<ans<<endl;
        ch=getchar();//5136.86
    }
    system("pause");
}