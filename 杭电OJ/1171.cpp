#include<iostream>
#include<cstring>
#define maxvalue 55
#define maxnum 5005
using namespace std;
int V[maxvalue];
int num[maxvalue];
int main()
{
    int n;
    while(cin>>n)
    {
        if(n<0) break;
        else
        {
            memset(V,0,sizeof(V));
            memset(num,0,sizeof(maxvalue));
            int sumvalue=0;
            for(int i=0;i<n;i++)
            {
                cin>>V[i]>>num[i];
                sumvalue+=V[i]*num[i];
            }
            int value[sumvalue+10]={0};
            int temp[sumvalue+10]={0};
            value[0]=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=sumvalue/2;j++)
                {
                    for(int k=0;k<=num[i]&&k*V[i]+j<=sumvalue/2;k++)
                    {
                        temp[k*V[i]+j]+=value[j];
                    }
                }
                for(int j=0;j<=sumvalue/2;j++)
                {
                    value[j]=temp[j];
                    temp[j]=0;
                }
            }
            int pos=sumvalue/2;
            for(;pos>=0;pos--)
            {
                if(value[pos]) break;
            }
            cout<<sumvalue-pos<<" "<<pos<<endl;
        }
    }
}