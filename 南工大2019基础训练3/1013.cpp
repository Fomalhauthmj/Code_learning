#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=-40;i<40;i++)
    {
        for(int j=i;j<40;j++)
        {
            for(int k=j;k<40;k++)
            {
                int temp=i*i+j*j+k*k;
                if(temp==1000)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    system("pause");
}