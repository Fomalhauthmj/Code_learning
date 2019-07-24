#include<iostream>
#include<string>
using namespace std;
bool isleapyear(int year)
{
    if(year%4==0&&year%100!=0) return true;
    if(year%400==0) return true;
    return false;
}
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int sum=0;
            string str;
            cin>>str;
            int y=stoi(str.substr(0,4));
            int m=stoi(str.substr(5,2));
            int d=stoi(str.substr(8,2));
            if(m==2&&d==29&&isleapyear(y+18)==false)
            {
                cout<<-1<<endl;
            }
            else
            {
                for(int i=y+1;i<y+18;i++)
                {
                    if(isleapyear(i)==true) sum+=366;
                    else sum+=365;
                }
                for(int i=12;i>m;i--) sum+=month[i];
                sum+=month[m]-d;
                if(isleapyear(y)==true&&m<=2) sum+=1;
                for(int i=1;i<m;i++) sum+=month[i];
                sum+=d;
                if(isleapyear(y+18)==true&&m>2) sum+=1;
                cout<<sum<<endl;
            }
        }
    }

}