//TODO:引例：斐波那契数列的记忆化存储 减少重复计算次数



//TODO:数塔
//状态空间：D(i,j)处于(i,j)位置时可取的最大值
//初始值:D(0,0)=a(0,0)
//状态转移方程：D(i,j)=max(D(i-1,j-1),D(i-1,j))+a(i,j);
// 0 9  0
// 0 12 15 0 
// 0 10 6  8  0
// 0 2  18 9  5  0
// 0 19 7  10 4  16 统一边界情况


// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// #define size 25
// int dp[size][size];
// int a[size][size];
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n;
//     while(cin>>n)
//     {
//         memset(a,0,sizeof(a));
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=i;j++)
//             {
//                 cin>>a[i][j];
//             }
//         }
//         //TODO:从上往下
//         /*
//         int  ret=0;
//         dp[1][1]=a[1][1];
//         for(int i=2;i<=n;i++)
//         {
//             for(int j=1;j<=i;j++)
//             {
//                 dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
//             }
//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(dp[n][i]>ret) ret=dp[n][i];
//         }
//         cout<<ret<<endl;
//         */
//         //TODO:从下往上
//         /*
//         for(int i=1;i<=n;i++) dp[n][i]=a[n][i];
//         for(int i=n-1;i>=1;i--)
//         {
//             for(int j=1;j<=i;j++)
//             {
//                 dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
//             }
//         }
//         cout<<dp[1][1]<<endl;
//         */
//     }
// }

//TODO:help jimmy POJ 1661
//只要计算横向移动距离

// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// #define size 1010
// #define inf 99999
// struct node
// {
//     int lx;
//     int rx;
//     int h;
//     bool operator <(const node &n) const
//     {
//         return h<n.h;
//     }
// };
// node layer[size];
// int n,Max;
// int dp[size][2];
// int down(int x,int st,int h)
// {
//     for(int i=st;i>=0;i--)
//     {
//         if(st==0) return 0;
//         if(h-layer[i].h>Max) return -1;
//         if(x<layer[st].rx&&x>layer[st].lx) return i;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     int sx,sy;
//     while(t--)
//     {
//         cin>>n>>sx>>sy>>Max;
//         layer[0].lx=layer[0].rx=sx;
//         layer[0].h=sy;
//         layer[1].lx=0;
//         layer[1].rx=0;
//         layer[1].h=0;
//         for(int i=2;i<=n+1;i++)
//         {
//             cin>>layer[i].lx>>layer[i].rx>>layer[i].h;
//         }
//         sort(layer,layer+n+2);
//         int lx,rx;
//         int downl,downr;
//         memset(dp,0,sizeof(dp));
//         for(int i=1;i<=n+1;i++)
//         {
//             lx=layer[i].lx;rx=layer[i].rx; //从最低到最高 如果从最高到最低?
//             downl=down(lx,i-1,layer[i].h);
//             downr=down(rx,i-1,layer[i].h);
//             cout<<"downl:"<<downl<<" downr: "<<downr<<endl;
//             if(downl>0)
//             {
//             dp[i][0]=min((dp[downl][0]+lx-layer[downl].lx),
//                          (dp[downl][1]+layer[downl].rx-lx));
//             }
//             else if(downl==0) dp[i][0]=0;
//             else dp[i][0]=inf;
//             if(downr>0)
//             {
//             dp[i][1]=min(dp[downr][0]+rx-layer[downr].lx,
//                         dp[downr][1]+layer[downr].rx-rx);
//             }
//             else if(downr==0) dp[i][1]=0;
//             else dp[i][1]=inf;
//             cout<<"i:"<<i<<" dp[0]: "<<dp[i][0]<<" dp[1]: "<<dp[i][1]<<endl;
//         }
//         cout<<dp[n+1][0]+sy<<endl;
//         cout<<dp[n+1][1]+sy<<endl;
//     }
//}//  WA!!




//TODO:最长上升子序列 LIS
//状态：前i个元素且最后一个元素为a[i]的最长有序子序列长度 
// f(i+1)=f(k)+1 (a[i+1]>=a[i],f(k)为i+1前最大的且a[i+1]>=a[k]) O(n^2)
// f(i+1)=f(k)+1 (a[i+1]<a[i],f(k)为i+1前最大的且a[i+1]>=a[k])
//TODO:优化  C[j] 记录目前为止f(k)==j的 最小a[k]值 k<=i;  C[0]=-1  C[] O(nlogn)
//c[j]=a[i] j为a[i]在c中第一个比它大的元素位 upper_bound() 
// #include<iostream>
// #include<algorithm>
// using namespace std;
// #define size 1010
// int a[size],dp[size],low[size];
// int route[size];
// void print(int pos)
// {
//     if(pos==-1) return;
//     print(route[pos]);
//     cout<<a[pos]<<" ";
// }
// void LIS(int n)
// {
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         dp[i]=1;
//         route[i]=-1;
//         for(int k=0;k<i;k++)
//         {
//             if(a[i]>=a[k]&&(dp[k]+1)>dp[i]) 
//             {
//                 dp[i]=dp[k]+1;
//                 route[i]=k;
//             }
//         }
//         if(dp[i]>ans) ans=dp[i];
//     }
//     cout<<ans<<endl;
//     for(int i=0;i<n;i++)
//     {
//         if(dp[i]==ans)
//         {
//             print(i);
//             break;
//         }
//     }
//     cout<<endl;
// }
// int betterLIS(int n)
// {
//     memset(low,0,sizeof(low));
//     answer=1;//最大长度
//     low[1]=a[1];
//     for(int i=2;i<=n;i++)
//     {
//         if(a[i]>low[answer]) 
//         {
//             low[++answer]=a[i];
//         }
//         else
//         {
//             int repos=upper_bound(low+1,low+answer+1,a[i])-low;
//             low[repos]=a[i];
//         }
//     }
//     return answer;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n;
//     while(cin>>n)
//     {
//         for(int i=0;i<n;i++) cin>>a[i];
//         cout<<"O(n^2):"<<endl;
//         LIS(n);
//         cout<<"O(nlogn):"<<endl;
//         betterLIS(n);
//     }
// }
//TODO:
//最长子序列个数？最长公共子序列
//LIS的应用 Super Jumping!Jumping!Jumping! :求和最大的递增子序列  b[i]=b[k]+a[i](k<i,k为从左起a[k]<a[i]且b[k]最大) 
//LIS的应用 FatMouse's Speed 最长递减子序列


// //TODO:最长公共子序列LCS
// //初始条件：f(i,0)=f(0,j)=0 有效索引从1起避免预处理 辅助空间更直观
// //f(i,j)={ f(i-1,j-1)+1,x[i]==y[j]
// //         max(f(i-1,j),f(i,j-1))  x[i]!=y[j]
// //       }
// #include<iostream>
// #include<string>
// #include<cstring>
// using namespace std;
// #define size 1010
// string a,b;
// int dp[size][size];
// int print[size][size];
// int pre[size];
// int cur[size];
// void printLCS(int r,int c)//TODO:回溯法输出LCS
// {
//     if(r==0||c==0) return;
//     if(print[r][c]==0)
//     {
//         printLCS(r-1,c-1);
//         cout<<b[c-1];  //或a[r-1]
//     }
//     else if(print[r][c]==1)
//     {
//         printLCS(r-1,c);
//     }
//     else if(print[r][c]==-1)
//     {
//         printLCS(r,c-1);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>a>>b)
//     {
//         //memset(dp,0,sizeof(dp));
//         memset(pre,0,sizeof(pre));
//         memset(cur,0,sizeof(cur));
//         for(int i=0;i<a.length();i++)
//         {
//             for(int j=0;j<b.length();j++)
//             {
//                 if(a[i]==b[j]) 
//                 {
//                     dp[i+1][j+1]=dp[i][j]+1;
//                     print[i+1][j+1]=0;
//                     //cur[j+1]=pre[j]+1;
//                 }
//                 else 
//                 {
//                     dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
//                     if(dp[i][j+1]>dp[i+1][j]) print[i+1][j+1]=1;
//                     else print[i+1][j+1]=-1;
//                     //cur[j+1]=max(pre[j+1],cur[j]);
//                 }
//                 //for(int k=1;k<=b.length();k++) pre[k]=cur[k]; //TODO:滚动！memcpy();
//             }
//         }
//         cout<<dp[a.length()][b.length()]<<endl;
//         printLCS(a.length(),b.length());
//         cout<<endl;
//         //cout<<cur[b.length()]<<endl;
//     }
// }
// //TODO:二维数组空间如何优化？ 滚动数组！

// //TODO:LCS->LIS 时间优化
//先顺序扫描x串取其在y串的所有位置，然后将位置集反序列替换x串中所有对应字母，最终结果在每个反序列集中取一个数构成LIS(严格递增)
// x:abdba; y:dbaaba
// a(2,3,5) b(1,4) d(0)
// (5,3,2)(4,1)(0)(4,1)(5,3,2) len=3
//对于自然数1-n的两个排列 求LCS 长度n<=1e5;


//LCS思考：
//如何求LCS个数？ g(i,j)为到达f(i,j)的匹配个数
//根据f(i-1,j) f(i,j-1) f(i-1,j-1)与f(i,j)的比较 判断来源 来更新g(i,j)
//其中a[i]==b[j] g(i,j)+=g(i-1,j-1) 若a[i]!=b[j]但f(i-1,j-1)==f(i,j) g(i,j)-=g(i-1,j-1)
//TODO:？？？减去两种来源的重复通过辅助空间可看出
//ans:g(n,m) 


//TODO:如何输出所有的LCS？
//https://blog.csdn.net/lisonglisonglisong/article/details/41596309
// #include<iostream>
// #include<string>
// #include<set>
// #include<algorithm>
// using namespace std;
// #define maxsize 1010
// int dp[maxsize][maxsize];
// string a,b;
// set<string> setofLCS;
// int LCS(string str1,string str2)
// {
//     int len1=str1.length();
//     int len2=str2.length();
//     for(int i=0;i<=len1;i++)
//     {
//         for(int j=0;j<=len2;j++)
//         {
//             if(i==0||j==0) dp[i][j]=0;
//             else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
//             else
//             {
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[len1][len2];
// }
// void DFS(int i,int j,string lcs)
// {
//    if(i==0||j==0)
//    {
//        reverse(lcs.begin(),lcs.end());
//        setofLCS.insert(lcs);//根据反馈注意判断长度
//        return;
//    }
//    if(a[i-1]==b[j-1])//针对dp[i][j]
//    {
//        lcs.push_back(a[i-1]);
//        DFS(i-1,j-1,lcs);
//    }
//    else
//    {
//        //观察前两个来源
//        if(dp[i-1][j]>dp[i][j-1]) DFS(i-1,j,lcs);
//        else if(dp[i-1][j]<dp[i][j-1]) DFS(i,j-1,lcs);
//        else
//        {
//            DFS(i-1,j,lcs);DFS(i,j-1,lcs);
//        }
//    }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>a>>b)
//     {
//         setofLCS.clear();
//         cout<<"The length of LCS:"<<LCS(a,b)<<endl;
//         LCS(a,b);
//         //DFS(a.length(),b.length(),"");
//         set<string>::iterator it;
//         //cout<<"All LCS number:"<<setofLCS.size()<<endl;
//         for(it=setofLCS.begin();it!=setofLCS.end();it++)
//         {
//             cout<<*it<<endl;
//         }
//     }
//}//poj.org/problem?id=1934  TODO:TLE







//TODO:纸牌 level damage 如何转换01背包使得damage和最大？



//n条直线(n<=20)的交点情况 所有情况 限制条件无三线共点
//如n=4 ans=0 3 4 5 6 
//ans(m)=(m-r)*r+ans(r); 0<=r<m; ans:可能的交点情况



//TODO:set 迭代器处理
// #include<iostream>
// #include<set>
// using namespace std;
// set<int> se[25];
// int n;
// int main()
// {
//     se[0].insert(0);
//     for(int i=1;i<=20;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             set<int>::iterator each;
//             for(each=se[j].begin();each!=se[j].end();each++)
//             {
//                 int temp=(i-j)*j+*each;
//                 se[i].insert(temp);
//             }
//         }
//     }
//     while(cin>>n)
//     {
//         set<int>::iterator it;
//         for(it=se[n].begin();it!=se[n].end();it++)
//         {
//             cout<<*it<<" ";
//         }
//         cout<<endl;
//     }
// }


//TODO:dp[][]
// #include<iostream>
// using namespace std;
// #define N 22
// int dp[N][N*(N-1)/2];
// int n;
// int main()
// {
//     while(cin>>n)
//     {
//         for(int i=0;i<=n;i++) dp[i][0]=1;//1表示存在此种情况 i条直线0个交点
//         for(int i=0;i<=n;i++)
//         {
//             for(int r=0;r<=i;r++) //与新加入的直线平行的直线数量为i-r
//             {
//                 for(int j=0;j<=r*(r-1)/2;j++)//求r条直线所有交点情况
//                 {
//                     if(dp[r][j]==1)
//                     {
//                         dp[i][j+(i-r)*r]=1;
//                     }
//                 }
//             }
//         }
//         for(int i=0;i<=n*(n-1)/2;i++)
//         {
//             if(dp[n][i]==1) cout<<i<<" ";
//         }
//         cout<<endl;
//     }
// }




TODO:Humble Numbers  HDU 1058
number=2^k1 * 3^k2 * 5^k3 * 7^k4
F(n)=min(F(i)*2,F(j)*3,F(k)*m),F(m)*7)
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int i,j,k,m;
#define N 6000
int dp[N];
int mymin(int x1,int x2,int x3,int x4)
{
    int ret=min(min(x1,x2),min(x3,x4));
    if(ret==x1) i++;
    if(ret==x2) j++;
    if(ret==x3) k++;
    if(ret==x4) m++;
    return ret;
}
int main()
{
    while(cin>>n)
    {
        dp[1]=1;
        i=1;
        j=1;
        k=1;
        m=1;
        for(int it=2;it<=n;it++)
        {
            dp[it]=mymin(2*dp[i],3*dp[j],5*dp[k],7*dp[m]);
        }
        cout<<dp[n]<<endl;
    }
}





//TODO:棋盘分割 多维状态 dp[][][][][];
//http://poj.org/problem?id=1191
/*
#include<iostream>
#include<cstring>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int n;
int board[8][8];
int dp[20][8][8][8][8];
int s[8][8][8][8];
double total_value;
double avg_value;
void init()
{
    total_value=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>board[i][j];
            total_value+=board[i][j];
        }
    }
    avg_value=total_value*1.0/n;
    memset(dp,-1,sizeof(dp)); 
    memset(s,0,sizeof(s));
    //初始化s和矩阵
    for(int r1=0;r1<8;r1++)
    {
        for(int c1=0;c1<8;c1++)
        {
            for(int r2=r1;r2<8;r2++)
            {
                for(int c2=c1;c2<8;c2++)
                {
                    int temp_sum=0;
                    for(int i=r1;i<=r2;i++)
                    {
                        for(int j=c1;j<=c2;j++) 
                        {
                            temp_sum+=board[i][j];
                        }
                    }
                    s[r1][c1][r2][c2]=temp_sum*temp_sum;
                    s[r2][c1][r1][c2]=temp_sum*temp_sum;
                    s[r1][c2][r2][c1]=temp_sum*temp_sum;
                    s[r2][c2][r1][c1]=temp_sum*temp_sum;
                }
            }
        }
    }
}
double answer()
{
    double temp=dp[1][0][0][7][7]*1.0/n;
    //temp+=1/n * 各区域总分和的平方(min)
    temp-=avg_value*avg_value;
    //cout<<avg_value<<endl;
    //cout<<temp<<endl;
    return sqrt(temp);
}
int DP(int k,int r1,int c1,int r2,int c2)
{
    if(dp[k][r1][c1][r2][c2]>=0) return dp[k][r1][c1][r2][c2];
    if(k==n) return s[r1][c1][r2][c2];
    dp[k][r1][c1][r2][c2]=inf;
    for(int a=r1;a<r2;a++)
    {
        dp[k][r1][c1][r2][c2]=min(
                min(DP(k+1,a,c1,r2,c2)+s[r1][c1][a-1][c2],DP(k+1,r1,c1,a,c2)+s[a+1][c1][r2][c2])
                    ,dp[k][r1][c1][r2][c2]);
    }
    for(int b=c1;b<c2;b++)
    {
        dp[k][r1][c1][r2][c2]=min(
                min(DP(k+1,r1,b,r2,c2)+s[r1][c1][r2][b-1],DP(k+1,r1,c1,r2,b)+s[r1][b+1][r2][c2])
                    ,dp[k][r1][c1][r2][c2]);
    }
    return dp[k][r1][c1][r2][c2];
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        init();
        DP(1,0,0,7,7);//DFS 记忆化搜索
        cout<<fixed<<setprecision(3)<<answer()<<endl;
    }
}
*/
/*
TODO:矩阵连乘 区间dp
dp[i][j]=区间[i,j]之间计算的最小次数
ans:dp[1][n]
init:dp[i][i]=0;
trans:dp[i][j]=for:min(dp[i][j],p[i]*p[k+1]*p[j]+dp[i][k]+dp[k+1][j]) i<=k<j
如何使状态以求得？从间隔较小的开始计算：间隔1..2..3
*/
/*
#include<iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
int p[N],dp[N][N],point[N][N];
int n;
void print_chain(int left,int right)
{
    if(left==right) cout<<"A"<<left;
    else
    {
        cout<<"(";
        print_chain(left,point[left][right]);
        print_chain(point[left][right]+1,right);
        cout<<")";
    }
}
int main()
{
    while(cin>>n)
    {
        //TODO:已测试！
        int i,j,k,r;
        for(i=1;i<=n+1;i++) cin>>p[i];
        for(i=1;i<=n;i++)
        {
            dp[i][i]=0;
            for(j=i+1;j<=n;j++)
            {
                dp[i][j]=inf;//TODO:半初始化
            }
        }
        for(r=1;r<=n;r++)//间隔
        {
            for(i=1;i<=n-r;i++)
            {
                j=i+r;
                for(k=i;k<j;k++)
                {
                    
                    int temp=dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1];//注意这里的乘积
                    if(temp<dp[i][j])
                    {
                        dp[i][j]=temp;
                        point[i][j]=k;//记录最优断点
                    }
                    
                    //dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1]);
                }
            }
        }
        cout<<dp[1][n]<<endl;
        print_chain(1,n);
    }
}
*/


//TODO:括号匹配问题 POJ2955
/*
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define N 105
string str;
int dp[N][N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>str)
    {
        if(str=="end") break;
        str.insert(0,"0");
        //cout<<str<<endl;
        memset(dp,0,sizeof(dp));
        int n=str.length()-1;
        for(int r=1;r<=n;r++)
        {
            for(int i=1;i<=n-r;i++)
            {
                int j=i+r;
                if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
                    dp[i][j]=dp[i+1][j-1]+2;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                //cout<<"dp:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
*/

//TODO:POJ 1141
/*
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
string str;
int dp[N][N];//dp[i][j]:使i-j合法所需添加最小的数量
int pos[N][N];
void print(int left,int right)
{
    if(left>right) return;
    if(left==right)
    {
        if(str[left]=='('||str[left]==')') cout<<"()";
        else cout<<"[]";
    }
    else if(pos[left][right]==-1)
    {
        cout<<str[left];
        print(left+1,right-1);
        cout<<str[right];
    }
    else
    {
        print(left,pos[left][right]);
        print(pos[left][right]+1,right);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(getline(cin,str))
    {
        if(str=="")
        {
            cout<<endl;continue;
        }
        int n=str.length();
        memset(dp,0,sizeof(dp));
        memset(pos,0,sizeof(pos));
        for(int i=0;i<n;i++)   dp[i][i]=1;
        for(int r=1;r<n;r++)
        {
            for(int i=0;i<n-r;i++)
            {
                int j=i+r;
                dp[i][j]=inf;
                if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
                {
                    dp[i][j]=dp[i+1][j-1];
                    pos[i][j]=-1;
                }
                for(int k=i;k<j;k++)
                {
                    int temp=dp[i][k]+dp[k+1][j];
                    if(temp<dp[i][j])
                    {
                        dp[i][j]=temp;
                        pos[i][j]=k;
                    }
                }
            }
        }
        //cout<<dp[0][n-1]<<endl;
        print(0,n-1);
        cout<<endl;
    }
}
*/



//TODO: n<=1e19 m<=bit(n);  一个整数分割成m部分使其乘积和最大
/*
#include<iostream>
#include<string>
using namespace std;
string str;
int m;
long long dp[N][N];
//TODO:dp[i][j]：左起1位-i位 分割成j部分的最大乘积和
//dp[i][j]=max(dp[i][j],dp[k][j-1]*num[k+1][j]);
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>str>>m)
    {

    }
}
*/


//TODO:n(<1000)个数字成环 相邻两堆合并，得分为两合并堆数量之和  求最大，最小得分
//dp[i][j]:i-j个数字最优值
/*
dp[i][j]=max/min(dp[i][j],dp[i][k]+dp[k+1][j])+sum[i][j]//不成环
如果成环? ans=max(dp[i][i+n-1]) 枚举长度为n的所有区间
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 1010
#define inf 0x3f3f3f3f
int a[2*N];
int dp[2*N][2*N];
int sum[2*N];//前缀和
int n;
int per[2*N][2*N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            a[i+n]=a[i];
        }
        sum[0]=0;
        for(int i=1;i<=2*n;i++)
        {
            if(i<=n) sum[i]=sum[i-1]+a[i];
            else sum[i]=sum[i-1]+a[i-n]; 
            per[i][i]=i;
        }//前缀和数组初始化
        memset(dp,0,sizeof(dp));
        for(int r=1;r<=2*n;r++)
        {
            for(int i=1;i<=2*n-r;i++)
            {
                int j=i+r;
                dp[i][j]=inf;
                //TODO:优化 四边形不等式
                for(int k=per[i][j-1];k<=per[i+1][j];k++)
                {
                    int temp=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    if(dp[i][j]>temp)
                    {
                        dp[i][j]=temp;per[i][j]=k;
                    }
                }  
                //per[i][j]：i-j之间的最优点 副值(sum[j]-sum[i-1])区间单调且满足四边形不等式
            }
        }
        int ans=inf;
        for(int i=1;i<=n+1;i++)
        {
            if(ans>dp[i][i+n-1]) ans=dp[i][i+n-1];
        }
        cout<<ans<<endl;
    }
}
*/
