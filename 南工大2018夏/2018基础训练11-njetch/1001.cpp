//0-1背包  TODO:如何处理非整数的背包？ *C=>整数
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
#define N 35
double Q;
int V;
int n;
int value[N];
int dp[3001000];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>Q>>n)
    {
        V=Q*100;
        if(n==0) break;
        int m;
        string str;
        for(int i=1;i<=n;i++) 
        {
            bool flag=true;//发票有效性
            value[i]=0;
            cin>>m;
            int temp_tot=0;
            int temp_a=0;
            int temp_b=0;
            int temp_c=0;
            for(int j=1;j<=m;j++)
            {
                cin>>str;
                if(str[0]!='A'&&str[0]!='B'&&str[0]!='C')//含有无效类别
                {
                    flag=false;
                }
                else
                {
                    int each_item_value=stod(str.substr(2))*100;
                    temp_tot+=each_item_value;
                    if(str[0]=='A') temp_a+=each_item_value;
                    else if(str[0]=='B') temp_b+=each_item_value;
                    else if(str[0]=='C') temp_c+=each_item_value;
                }
            }
            if(temp_tot>100000) flag=false;
            if(temp_a>60000||temp_b>60000||temp_c>60000) flag=false;
            if(flag) value[i]=temp_tot;
            else value[i]=0;
            //cout<<i<<"  "<<value[i]<<endl;
        }
        //0-1背包
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=V;j>=value[i];j--)
            {
                dp[j]=max(dp[j],dp[j-value[i]]+value[i]);
            }
        }
        cout<<fixed<<setprecision(2)<<dp[V]*1.0/100<<endl;
    }
}