#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int height[n]={0};
        int solve[n]={0};
        int num=0;
        for(int i=0;i<n;i++) cin>>height[i];
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<num;j++)
            {
                if(solve[j]>=height[i])
                {
                    flag=1;
                    solve[j]=height[i];
                    break;
                }
            }
            if(flag==0) solve[num++]=height[i];
        }
        cout<<num<<endl;
    }

}