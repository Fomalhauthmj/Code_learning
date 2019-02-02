#include<iostream>
#include<iomanip>
using namespace std;
#define max 100010
int seed[max]={0};
int main()
{
    int step,mod;
    while(cin>>step>>mod)
    {
        seed[0]=0;
        bool visit[mod]={0};
        visit[0]=true;
        for(int i=1;i<mod;i++)
        {
            seed[i+1]=(seed[i]+step)%mod;
            visit[seed[i+1]]=true;
        }
        int flag=0;
        for(int i=0;i<mod;i++)
        {
            if(visit[i]==false)
            {
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<setw(10)<<right<<step<<setw(10)<<right<<mod<<"    "<<left<<"Good Choice"<<endl<<endl;
        else cout<<setw(10)<<right<<step<<setw(10)<<right<<mod<<"    "<<left<<"Bad Choice"<<endl<<endl;
    }
}