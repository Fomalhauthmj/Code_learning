#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    double ans=a*1.0/b;
    int kinds=0;
    for(int i=1;i<=100000;i++)
    {
        for(int j=i+1;j<=100000;j++)
        {
            int ta=i+j;
            int tb=i*j;
            double temp=ta*1.0/tb;
            if(fabs(ans-temp)<1e-12)
            {
                cout<<"1/"<<i<<" "<<"1/"<<j<<endl;
                kinds++;
            }
        }
    }
    cout<<kinds<<endl;//7  注意精确度
    system("pause");
}