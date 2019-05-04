#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        else
        {
           int result;
           scanf("%d",&result);
           n=n-1;
           while(n--)
           {
               int num;
               scanf("%d",&num);
               result^=num;
           }
           printf("%d\n",result);
        }
    }
}
