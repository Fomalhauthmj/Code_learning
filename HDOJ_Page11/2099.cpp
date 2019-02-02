#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0) break;
        else
        {
            int results[100]={0};
            int pos=0;
            for(int i=0;i<100;i++)
            {
                if((a*100+i)%b==0) results[pos++]=i;
            }
            for(int i=0;i<pos-1;i++)
            {
                if(results[i]<10) cout<<0<<results[i]<<" ";
                else cout<<results[i]<<" ";
            }
            if(results[pos-1]<10) cout<<0<<results[pos-1]<<endl;
            else cout<<results[pos-1]<<endl;
        }

    }

}
