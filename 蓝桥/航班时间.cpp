#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,m,s,d;
    //格式化输入输出
    while(scanf("%d:%d:%d",&h,&m,&s))
    {
        char ch=getchar();
        //如果空格 如果回车
        if(ch==' ') 
        {
            scanf("(+%d)",&d);//cout<<h<<" "<<m<<" "<<s<<" "<<d<<" "<<endl;
            printf("%02d:%02d:%02d (+%d)\n",h,m,s,d);
        }
        else
        {
            printf("%02d:%02d:%02d\n",h,m,s);
        }
    }

}