#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mod 1000000009
int n,k;
struct node
{
    long long val;
    int flag;
    node(long long vv,int ff)
    {
        val=vv;
        flag=ff;
    }
};
vector<node> V;
bool cmp(node &n1,node &n2)
{
    return n1.val>n2.val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long num;
    while(cin>>n>>k)
    {
        V.clear();
        for(int i=0;i<n;i++)
        {
            cin>>num;
            if(num<0) V.push_back(node(-num,-1));
            else if(num==0) V.push_back(node(0,0));
            else if(num>0) V.push_back(node(num,1));
        }
        if(n==k)
        {
            long long ans=1;
            for(auto ele:V)
            {
                ans=(ans*ele)%mod;
            }
            cout<<ans<<endl;
            continue;
        }
        sort(V.begin(),V.end(),cmp);
        /*
        for(auto ele:V)
        {
            cout<<ele.val<<" "<<ele.flag<<endl;
        }
        */
        //n>k  0的绝对值最小 最后
        int n_num=0;
        for(int i=0;i<k;i++)
        {
            if(V[i].flag==-1)  n_num++;
        }
        if(n_num==n)
        {
            //全为负数
            if(k&1)
            {
                //k为奇数
                long long ans=1;
                for(int i=0;i<k;i++)
                {
                    ans=(ans*V[n-1-i].val)%mod;
                }
                cout<<-ans<<endl;
                continue;
            }
            else
            {
                //k为偶数
                long long ans=1;
                for(int i=0;i<k;i++)
                {
                    ans=(ans*V[i].val)%mod;
                }
                cout<<ans<<endl;
                continue;            
            }
        }
        if(n_num%2==0)
        {
            //直接处理
            long long ans=1;
            for(int i=0;i<k;i++)
            {
                ans=(ans*V[i].val)%mod;
            }
            cout<<ans<<endl;
            continue;            
        }
        else
        {
            if(V[k].flag==0)
            {
                //后全为0
                cout<<0<<endl;
                continue;
            }
            int rn_num=0;
            int rp_num=0;
            int r0_num=0;
            for(int i=k;k<n;k++)
            {
                if(V[i].flag<0) rn_num++;
                else if(V[i].flag=0) r0_num++;
                else if(V[i].flag>0) rp_num++; 
            }           
            else if()
            {
                
            }
            else if()
            {

            }
            //后必有数
            //奇数
            //去绝对值最小负加下一个正 后有正数
            //去绝对值最小正加下一个负 后有负数
        }
    }
}