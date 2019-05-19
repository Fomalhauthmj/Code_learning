//!:0-1背包


//!:复习  0-1背包 回溯法
// #include<iostream>
// using namespace std;
// #define N 15
// struct node
// {
//     int weight;
//     int value;
// };
// node goods[N];
// int n,W;
// int current;
// int ans,tempans;
// int rest;//未考虑物品的价值
// int x[N]; //x[i]=0 x[i]不取
// int ret[N];
// void DFS(int depth) //表示第depth个物品
// {
//     if(depth>=n)
//     {
//         if(tempans>ans)
//         {
//             ans=tempans;
//             for(int i=0;i<n;i++)
//             {
//                 ret[i]=x[i];
//             }
//         }
//         return;
//     }
//     //加入
//     if(current+goods[depth].weight<=W)
//     {
//         x[depth]=1;
//         current+=goods[depth].weight;
//         tempans+=goods[depth].value;
//         DFS(depth+1);
//         current-=goods[depth].weight;
//         tempans-=goods[depth].value;
//     }
//     //不加入
//     rest-=goods[depth].value;
//     if(rest+tempans>ans) //剪枝
//     {
//         x[depth]=0;
//         DFS(depth+1);
//     }
//     rest+=goods[depth].value;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin>>n>>W;
//     rest=0;
//     for(int i=0;i<n;i++)
//     {
//         cin>>goods[i].weight>>goods[i].value;
//         rest+=goods[i].value;
//     }
//     current=0;
//     ans=0;
//     tempans=0;
//     DFS(0);
//      for(int i=0;i<n;i++)
//     {
//         if(ret[i]==1) cout<<i+1<<" ";
//     }
//     cout<<endl<<ans<<endl;
//     system("pause");
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;
// #define size 1010
// int w[size];
// int v[size];
// int weight,n;
// int dp[size][size];
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>weight>>n)
//     {
//         for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
//         memset(dp,0,sizeof(dp));
//         for(int i=1;i<=n;i++)
//         {
//            for(int j=0;j<=weight;j++)
//            {
//                if(j-w[i]>=0) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//                else dp[i][j]=dp[i-1][j];
//            }
//         }
//         //输出最优方案：用now标记当前剩余容量输出方案！
//         //已测试
//         cout<<dp[n][weight]<<endl;
//         int now=weight;
//         for(int i=n;i>=1;i--)
//         {
//             if(dp[i][now]>dp[i-1][now])
//             {
//                 cout<<i<<" ";
//                 now-=w[i];
//             }
//         }
//     }
// }
// 0-1背包的空间优化
//for(i:1->n) for(j:weight->0) 确保得到f[j]时f[weight-w[i]]保存的是状态f[i-1][weight-w[i]] 
//f[j]=max(f[j],f[weight-w[i]]+v[i]); 

//若要求刚好装满的最优解 初始化处理 dp[0]=0 else dp[i]=-inf
//!:已测试
// #include<iostream>
// using namespace std;
// #define inf 0x3f3f3f3f
// #define size 1010
// int w[size];
// int v[size];
// int dp[size];
// int weight,n;
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>weight>>n)
//     {
//         for(int i=0;i<n;i++) cin>>w[i]>>v[i];
//         dp[0]=0;
//         for(int i=1;i<=weight;i++) dp[i]=-inf;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=weight;j>=w[i];j--)
//             {
//                 if(dp[j-w[i]]!=-inf) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
//             }
//         }
//         cout<<dp[weight]<<endl;
//     }
// }   
//10 5 2 6 2 3 6 5 5 4 4 6
//15


//!:完全背包
#include<iostream>
#include<cstring>
using namespace std;
#define size 1010
int w[size];
int v[size];
int weight,n;
int dp[size];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>weight>>n)
    {
        for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
           for(int j=w[i];j<=weight;j++)
           {
               dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
           }
        }
        cout<<dp[weight]<<endl;
    }
}
// //!:优化：for(i:1->n) for(j:0->v)  一维正序



//!:分组背包 for(组：k) for(空间：v->0) for(组属物品:i) 一维空间倒序确保状态正确
//!:多重背包 https://blog.csdn.net/yoer77/article/details/70943462