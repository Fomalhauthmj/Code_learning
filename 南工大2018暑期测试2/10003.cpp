//http://codeforces.com/contest/722/problem/C
//TODO:并查集
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define size 100010
long long a[size]; 
int b[size];
int n;
struct node
{
    int pre;
    long long sum;
};
node nodes[size];
bool vis[size];
long long ans[size];
void init()
{
    for(int i=1;i<=n;i++)
    {
        nodes[i].pre=i;nodes[i].sum=a[i];
    }
    memset(vis,0,sizeof(vis));
}
int Find(int x)
{
    if(nodes[x].pre==x) return x;
    nodes[x].pre=Find(nodes[x].pre);
    return nodes[x].pre;
}
void Union(int x,int y)
{
    int prex=Find(x);
    int prey=Find(y);
    if(prex!=prey)
    {
        nodes[prex].pre=prey;
        nodes[prey].sum+=nodes[prex].sum;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int addpoint;
    long long maxvalue;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)  cin>>a[i];
        for(int i=1;i<=n;i++)  cin>>b[i];
        init();
        maxvalue=0;//可以换优先队列用top()元素
        for(int i=n;i>=1;i--)
        {
            addpoint=b[i];
            vis[addpoint]=1;
            ans[i]=maxvalue;
            if(addpoint!=1&&vis[addpoint-1]) Union(addpoint,addpoint-1);
            if(addpoint!=n&&vis[addpoint+1]) Union(addpoint,addpoint+1);
            maxvalue=max(maxvalue,nodes[Find(addpoint)].sum);
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<endl;
        }
    }
}

//TODO:set multiset TODO:WA
// #include<iostream>
// #include<set>
// #include<cstring>
// using namespace std;
// #define size 100010
// long long a[size];
// long long sum[size];
// multiset<long long> ans;
// set<int> point;
// int n;
// void init()
// {
//     memset(sum,0,sizeof(sum));
//     for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//     ans.clear();point.clear();
//     point.insert(0);point.insert(n+1);
//     ans.insert(sum[n]);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     int t;cin>>t;
//     int cut;
//     multiset<long long>::iterator it2;
//     set<int>::iterator it1;
//     int start,end;
//     while(t--)
//     {
//         cin>>n;
//         for(int i=1;i<=n;i++) cin>>a[i];
//         init();
//         for(int i=1;i<=n;i++)
//         {
//             cin>>cut;
//             it1=point.upper_bound(cut);
//             end=*it1;
//             start=*(--it1);//获取断点所在线段的端点
//             it2=ans.find(sum[end-1]-sum[start]);
//             ans.erase(it2);//删除start+1 ..cut...end-1的连续和线段
//             ans.insert(sum[end-1]-sum[cut]);
//             ans.insert(sum[cut-1]-sum[start]);//重新添加start+1...cut-1 和cut+1 ...end-1 两段连续和线段
//             point.insert(cut);//添加新断点
//             it2=ans.end();
//             cout<<*(--it2)<<endl;//获取最大线段和
//         }
//     }
// }


//TODO:朴素方法
/*
        bool judge(int pos,int op)
        {
            for(int i=1;i<=op;i++)
            {
                if(b[i]==pos) return false;
            }
            return true;
        }
        for(int i=1;i<=n;i++)//第i次操作后  剩余数中找下标连续元素和最大值
        {
            sum=0;temp=0;
            for(int j=1;j<=n;j++)//从头开始找
            {
                if(judge(j,i)) temp+=a[j];
                else if(!judge(j,i))
                {
                    if(temp>sum) 
                    {
                        //cout<<j<<"max:"<<temp<<endl;
                        sum=temp;
                    }
                    temp=0;
                }
                if(j==n&&temp>sum) sum=temp;
            }
            cout<<sum<<endl;
        }
*/