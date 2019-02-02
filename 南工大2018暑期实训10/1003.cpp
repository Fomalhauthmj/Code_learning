#include<iostream>
#include<algorithm>
using namespace std;
#define size 1010
struct node
{
    int wei;
    int spd;
    int num;
};
node mice[size];
int n;
bool cmp(node &n1,node &n2)
{
    if(n1.wei!=n2.wei) return n1.wei<n2.wei;
    else return n1.spd>n2.spd;
}
int route[size];
int dp[size];
void print(int pos)
{
    if(pos==-1) return;
    print(route[pos]);
    cout<<mice[pos].num<<endl;
}
void LIS(int pos)
{
    n=0;
    for(int i=0;i<pos;i++)
    {
        dp[i]=1;
        route[i]=-1;
        for(int k=0;k<i;k++)
        {
            if(mice[i].wei>mice[k].wei&&mice[i].spd<mice[k].spd&&(dp[k]+1)>dp[i]) 
            {
                dp[i]=dp[k]+1;
                route[i]=k;
            }
        }
        if(dp[i]>n) n=dp[i];
    }
    //cout<<"max:"<<n<<endl;
    cout<<n<<endl;
    for(int i=0;i<pos;i++)
    {
        if(dp[i]==n)
        {
            print(i);
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int pos=0;
    while(cin>>mice[pos].wei>>mice[pos].spd)
    {
        mice[pos].num=pos+1;
        pos++;
        if(cin.eof()) break;
    }
    sort(mice,mice+pos,cmp);
    LIS(pos);
    system("pause");
}