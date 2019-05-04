#include<iostream>
#include<string>
using namespace std;
char str[2020];
char init[20];
void print()
{
    for(int i=1;i<=2014;i++)
    {
        cout<<str[i];
    }
    cout<<endl<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    for(char j='a';j<='s';j++)
    {
        init[cnt++]=j;
    }
    for(int i=1;i<=2014;i++)
    {
        str[i]=init[(i-1)%19];
    }
    int flag;
    int len=2014;
    print();
    cnt=1;
    while(len>1)
    {
        flag=0;
        for(int i=1;i<=len;i++)
        {
            if(!flag)//奇数
            {
                flag=1;
            }
            else//偶数
            {
                flag=0;
                str[cnt++]=str[i];
            }
        }
        len/=2;
        for(int i=1;i<=len;i++)
        {
            cout<<str[i];
        }
        cout<<endl<<endl;
        cnt=1;
    }
    cout<<str[1]<<endl;
    cout<<endl;
    system("pause");
    //ans=q
}