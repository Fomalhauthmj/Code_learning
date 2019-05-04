/*
经计算发现相邻两个斐波那契数的比值是随序号的增加而逐渐逼近黄金分割比。
由于斐波那契数都是整数，两个整数相除之商是有理数，而黄金分割是无理数，
所以只是不断逼近黄金分割
*/
#include<iostream>
using namespace std;
#define N 92
long long fib[N];
/*
https://leflacon.github.io/2e9cbb0/
*/
void init()
{
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<N;i++) fib[i]=fib[i-1]+fib[i-2];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    long long a[120];
    long long x=fib[87];
    long long y=fib[86];//long long 极限
    for(int i=0;i<101;i++)
    {
        a[i]=y/x;//模拟除法
        y=(y%x)*10;
        cout<<a[i];
    }
    cout<<endl;
    system("pause");

    //正确答案
    //TODO:"0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911374"8进一 75
    //TODO:"0.6180339887498948482045868343656381167528434309151518930402843639810346973807203378342944662358280795"
}