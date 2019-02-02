#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
int a[]={111,222,333,444,555,666,777,888,999};
int main()
{
    while(cin>>N)
    {
        int flag=0;
        for(int i=N;i<1000;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[j]>=i)
                {
                    cout<<a[j]<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    }
}