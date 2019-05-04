#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        while(n--)
        {
            string str;
            cin>>str;
            int rpos1=str.find('(');
            int rpos2=str.find(')');
            int r=stoi(str.substr(rpos1+1,rpos2-rpos1-1));
            int num=stoi(str.substr(0,rpos1));
            int i;
            for(i=0;num/10!=0;i++)
            {
                sum+=num%10*pow(r,i);
                num=num/10;
            }
            sum+=num%10*pow(r,i);
        }
        cout<<sum<<endl;
    }
    


}