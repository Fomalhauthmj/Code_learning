#include<iostream>
#include<cstring>
using namespace std;
string a;
string b;
int num[1002]={0};
int main()
{
    int t;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        cin>>a>>b;
        memset(num,0,sizeof(num));
        int aend=a.length()-1;
        int bend=b.length()-1;
        int pos=1001;
        while(aend>=0&&bend>=0)
        {
            if(a[aend]+b[bend]-96>=10)
            {   
                num[pos--]+=(a[aend]+b[bend]-96)%10;
                num[pos]+=1;
            }
            else
            {
                num[pos--]+=a[aend]+b[bend]-96;
            }
            aend--;
            bend--;
        }
        if(aend!=-1)
        {
            for(int i=aend;i>=0;i--) num[pos--]+=a[i]-48;
        }
        if(bend!=-1)
        {
            for(int i=bend;i>=0;i--) num[pos--]+=b[i]-48;
        } 
        for(int i=1001;i>=0;i--)
        {
            if(num[i]>=10)
            {
                num[i]=num[i]%10;
                num[i-1]++;
            }
        }
        int startpos=0;
        for(int i=pos;i<1002&&num[i]>=0;i++)
        {
            if(num[i]>0) 
            {
                startpos=i;
                break;
            }
        }
        cout<<"Case "<<m<<":"<<endl;
        cout<<a<<" + "<<b<<" = ";
        for(int i=startpos;i<1002;i++) cout<<num[i];
        if(m<t) cout<<endl<<endl;
        else cout<<endl;
    }
}