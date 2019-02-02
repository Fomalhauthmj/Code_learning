#include<iostream>
using namespace std;
int result(int n,int m)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            double temp1=(i*i+j*j+m)*1.0/(i*j);
            int temp2=temp1;
            if(temp1-temp2==0.0) sum++;
        }
    }
    return sum;
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int casenum=1;
        int n,m;
        int flag=0;
        while(cin>>n>>m)
        {
            if(n==0&&m==0) 
            {
                flag=1;
                break;
            }
            else
            {
                cout<<"Case "<<casenum++<<": "<<result(n,m)<<endl;
            }
        }
        if(flag==1) 
        {
            if(i<N) cout<<endl;
            continue;
        }
    }
    return 0;
}