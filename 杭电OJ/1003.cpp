#include<stdio.h>
using namespace std;
#define maxnum 100010
int num[maxnum];
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        int sum=0;
        int temp=1;
        int max=-2000;
        int start=1;
        int end=1;
        for(int j=1;j<=n;j++) 
        {
            scanf("%d",&num[j]);
            sum+=num[j];
            if(sum>max)
            {
                start=temp;
                end=j;
                max=sum;
            }
            if(sum<0)  //sum+num[j+1]<num[j+1]-> 抛弃之前的 从 num[j+1] 起  O(n)
            {
                sum=0;
                temp=j+1;
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n",max,start,end);
        if(i<t) printf("\n");
    }
}