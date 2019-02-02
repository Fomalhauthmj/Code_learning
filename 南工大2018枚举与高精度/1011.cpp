#include<iostream>
#include<string>
#define L 2010
using namespace std;
string add(string a,string b)//只限两个非负整数相加
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
int main()
{
    int n;
    string f[5];
    string temp1,temp2;
    while(cin>>n)
    {
        if(n<=4) 
        {
            cout<<1<<endl;
            continue;
        }
        f[1]=f[2]=f[3]=f[4]="1";
        for(int i=5;i<=n;i++)
        {
            temp1=add(f[4],f[3]);
            temp2=add(temp1,f[2]);
            f[0]=add(temp2,f[1]);
            f[1]=f[2];
            f[2]=f[3];
            f[3]=f[4];
            f[4]=f[0];
        }
        cout<<f[0]<<endl;
    }
}