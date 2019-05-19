//!:GNU C++11	Accepted	951 ms	9400 KB
/*
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200020
int n;
int a[N];
map<int,int> M;
vector<int> V;
bool vis[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        M.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            M[a[i]]++;
        }
        V.clear();
        for(auto ele:M)
        {
            V.push_back(ele.second);
        }
        sort(V.begin(),V.end());
    
        int ans=0;
        int len=V.size();
        for(int i=1;i<=V[len-1];i++)
        {
            int temp=i;
            int next=2*i;
            memset(vis,0,sizeof(vis));
            //找到最少的含有i个题目的独立集标为已使用
            int init=lower_bound(V.begin(),V.end(),i)-V.begin();
            vis[init]=1;
            while(next<=V[len-1])//下个测试题目数量少于最大独立数量
            {
                int pos=lower_bound(V.begin(),V.end(),next)-V.begin();//获得符合坐标
                if(pos>=len||pos<0) break;
                //cout<<"find:"<<pos<<endl;
                if(!vis[pos])//未使用
                {
                    temp+=next;
                    vis[pos]=1;
                }
                else//已使用 向右找
                {
                    while(vis[pos])
                    {
                        pos++;
                    }
                    if(pos>=len) break;
                    temp+=next;
                    vis[pos]=1;
                }
                next*=2;
            }
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
}
*/

//!:GNU C++11	Accepted	249 ms	9200 KB
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200020
int n;
int a[N];
map<int,int> M;
vector<int> V;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        M.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            M[a[i]]++;
        }
        V.clear();
        for(auto ele:M)
        {
            V.push_back(ele.second);
        }
        sort(V.begin(),V.end());
    
        int ans=0;
        int len=V.size();
        for(int i=1;i<=V[len-1];i++)
        {
            int temp=i;
            int next=2*i;
            //找到最少的含有i个题目的独立集标为已使用
            int init=lower_bound(V.begin(),V.end(),i)-V.begin();
            init++;
            while(next<=V[len-1])//下个测试题目数量少于最大独立数量
            {
                while(V[init]<next&&init<len) init++;
                if(init>=len) break;
                temp+=next;
                next*=2;
                init++;
            }
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
}