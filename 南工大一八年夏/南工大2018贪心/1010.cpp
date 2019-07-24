#include<iostream>
#include<algorithm>
using namespace std;
#define max 21
struct hero
{
    int dps;
    int hp;
};
bool cmp(const hero &h1,const hero &h2)
{
    return h1.dps*1.0/h1.hp>h2.dps*1.0/h2.hp;
}
hero enemy[max];
int main()
{
    int n;
    long long res;
    while(cin>>n)
    {
        res=0;
        for(int i=1;i<=n;i++)
        {
            cin>>enemy[i].dps>>enemy[i].hp;
        }
        sort(enemy+1,enemy+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            res+=enemy[i].dps*enemy[i].hp;
            for(int j=i+1;j<=n;j++)
            {
                res+=enemy[j].dps*enemy[i].hp;
            }
            enemy[i].hp=0;
        }
        cout<<res<<endl;
    }
}