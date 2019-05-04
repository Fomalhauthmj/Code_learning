#include<iostream>
using namespace std;
int main()
{
    int n;
    int flag=0;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            if(flag==1) cout<<endl;
            else flag=1;
            int *p=new int [n];
            int sum=0;
            for(int i=0;i<n;i++)
            {
                cin>>p[i];
                sum+=p[i];
            }
            int avg=sum/n;
            int result=0;
            for(int i=0;i<n;i++)
            {
                if(p[i]>avg) result+=p[i]-avg;
                else continue;
            }
            cout<<result<<endl;
        }
    }
}
