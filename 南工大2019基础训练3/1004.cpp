#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kinds=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(i==j) continue;
            for(int p=1;p<=9;p++)
            {
                for(int q=1;q<=9;q++)
                {
                    if(p==q) continue;
                    double temp1=(10*i+p)*1.0/(10*j+q);
                    double temp2=i*1.0/j*p*1.0/q;
                    if(fabs(temp1-temp2)<1e-6)
                    {
                        kinds++;
                        cout<<i<<"/"<<j<<" "<<p<<"/"<<q<<endl;
                    }
                    //else cout<<"next"<<endl;
                }
            }
        }
    }
    cout<<kinds<<endl;//14
    system("pause");
}