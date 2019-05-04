#include <stdio.h>
#include<iostream>
#define N 6
#define M 5
#define BUF 1024
using namespace std;
int temp=0;
void f(int a[], int k, int m, char b[])
{
int i,j;
if(k==N){ 
b[M] = 0;
if(m==0) 
{
    printf("%s\n",b);
    cout<<temp++<<endl;
}
return;
}
for(i=0; i<=a[k]; i++)
{
    for(j=0; j<i; j++) 
    {
        b[M-m+j] = k+'A';
    }
    f(a,k+1,m-i,b); //填空
}
}
int main()
{
int a[N] = {4,2,2,1,1,3};
char b[BUF];
f(a,0,M,b);
system("pause");
return 0;
}