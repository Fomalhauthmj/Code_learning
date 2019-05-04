#include <stdio.h>
#include<iostream>
void f(int x)
{
int i;
for(i=0; i<32; i++) printf("%d", (x>>(31-i))&1);
printf(" ");

//x =x&1?(x+1)&x:x; // 填空
x=(x+1)&x;
for(i=0; i<32; i++) printf("%d", (x>>(31-i))&1);
printf("\n"); 
}

int main()
{
f(103);
f(12);
system("pause");
return 0;
}