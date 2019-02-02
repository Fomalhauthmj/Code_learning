#include<iostream>
using namespace std;
#define size 1000010
int a[size]={0};
int main() //素数筛法的原理
{
    ios::sync_with_stdio(false);
    int pos=1;
    for(int i=2;i<size;i++)
    {
        if(!a[i]) //第一个素数为2 最大质因子位为1
        {
            for(int j=i;j<size;j+=i) a[j]=pos;  //i的倍数全部确定最大质因子
            pos++;//下一个质因子位为2 当a[3]=0时开始
        }
    }
    int number;
    while(cin>>number)
    {
        cout<<a[number]<<endl;
    }
    return 0;
}