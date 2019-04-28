//遍历子集树O(2^n)  遍历排列树O(n!)
//通过剪枝来降低复杂度
//递归 与 迭代(解决递归层次较高) 回溯

//八皇后问题 ans=92

// #include<iostream>
// using namespace std;
// #define N 9
// int ans=0;
// int x[N];
// bool canPut(int row,int col)
// {
//     //x[1]-x[col-1]已确定
//     for(int i=1;i<col;i++)
//     {
//         if(x[i]==row||abs(row-x[i])==abs(col-i)) return false;  //根据斜率剪枝对角线
//     }
//     return true;
// }
// void DFS(int depth)
// {
//     if(depth>8)
//     {
//         ans++;
//         return;
//     }
//     for(int i=1;i<=8;i++)
//     {
//         if(canPut(i,depth)) //i行dep列 可置
//         {
//             x[depth]=i;//第i行放在第depth列
//             DFS(depth+1);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     DFS(1);
//     cout<<ans<<endl;
//     system("pause");
//     return 0;
// }

//0-1背包 回溯法
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

//0-1背包 装载问题？

//全排列

// #include<iostream>
// #include<cstring>
// using namespace std;
// #define N 5
// char a[N]={'a','b','c','d'};
// char x[N];
// int n=4;
// bool vis[N];
// void DFS(int dep)
// {
//     if(dep>=n)
//     {
//         for(int i=0;i<n;i++)    cout<<a[i]<<" ";
//         cout<<endl;
//         return;
//     }
//     // for(int i=0;i<4;i++)
//     // {
//     //     if(!vis[i])
//     //     {
//     //         x[dep]=a[i];
//     //         vis[i]=1;
//     //         DFS(dep+1);
//     //         vis[i]=0;
//     //     }
//     // }
//     //子集树
//     for(int i=dep;i<4;i++)
//     {
//         swap(a[dep],a[i]);
//         DFS(dep+1);
//         swap(a[dep],a[i]);
//     }//排列树
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     memset(vis,0,sizeof(vis));
//     DFS(0);
//     system("pause");
//     return 0;
// }

//求一个集合的所有子集
// #include<iostream>
// using namespace std;
// #define size 10
// int a[size];
// bool b[size];
// int n;
// void DFS(int depth)
// {
//     if(depth>=n)
//     {
//         cout<<"{ ";
//         for(int i=0;i<n;i++)
//         {
//             if(b[i]) cout<<a[i]<<" ";
//         }
//         cout<<"}"<<endl;
//         return;
//     }
//     b[depth]=0;
//     DFS(depth+1);
//     b[depth]=1;
//     DFS(depth+1);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>n)
//     {
//         for(int i=0;i<n;i++) cin>>a[i];
//         DFS(0);
//     }
// }

//给定一个字符串，生成组成这个字符串的字母的全排列
// #include<iostream>
// #include<string>
// #include<cstring>
// #include<map>
// using namespace std;
// #define size 10
// string str;
// map<char,int>M;
// map<char,int>used;
// char ans[size];
// int n;
// void DFS(int depth)
// {
//     if(depth>=n)
//     {
//         for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//         cout<<endl;
//         return;
//     }
//     map<char,int>::iterator i;
//     for(i=M.begin();i!=M.end();i++) //根据出现元素的种类来进行 √
//     {
//         if(i->second>used[i->first])
//         {
//             ans[depth]=i->first;
//             used[i->first]++;
//             DFS(depth+1);
//             used[i->first]--;
//         }
//     }
//     // for(int i=0;i<n;i++)
//     // {
//     //     if(M[str[i]]>used[str[i]])
//     //     {
//     //         ans[depth]=str[i];
//     //         used[str[i]]++;
//     //         DFS(depth+1);
//     //         used[str[i]]--;
//     //     }
//     // }//重复？WA! 能找到所有的全排列 但是重复找了一些排列 因为重复元素的存在
// }
// int main()
// {
//     while(cin>>str)
//     {
//         M.clear();
//         used.clear();
//         for(int i=0;i<str.length();i++) M[str[i]]++;
//         n=str.length();
//         DFS(0);
//     }
// }

//求一个n元集合的k元子集（n>=k>0）
// #include<iostream>
// #include<cstring>
// using namespace std;
// #define size 10
// int a[size];
// bool vis[size];
// int b[size];
// int n,k;
// void DFS(int depth,int pre)
// {
//     if(depth>=k)
//     {
//         for(int i=0;i<k;i++)
//         {
//            cout<<b[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     for(int i=pre+1;i<n;i++)
//     {
//         if(!vis[i])
//         {
//             b[depth]=a[i];
//             vis[i]=1;
//             DFS(depth+1,i);
//             vis[i]=0;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>n>>k)
//     {
//         memset(vis,0,sizeof(vis));
//         for(int i=0;i<n;i++) cin>>a[i];
//         DFS(0,-1);
//     }
// }

/*
圆排列   
n个不同元素的m-圆排列个数N为：  Cm,n/m  
特别地，当m=n时，n个不同元素作成的圆排列总数N为： (n-1)!
顺时针与逆时针算作不同

#include<iostream>
#include<cstring>
using namespace std;
#define size 10
int a[size];
int b[size];
bool vis[size];
int n,k;
void DFS(int start,int depth)
{
    if(depth>=k)
    {
        for(int i=0;i<k;i++) cout<<b[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=start+1;i<n;i++)
    {
        if(!vis[i])
        {
            b[depth]=a[i];
            vis[i]=1;
            DFS(start,depth+1);
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n-k+1;i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            b[0]=a[i];
            DFS(i,1);
        }
    }
}
*/

//组合:从1...n中取k个数 按字典序
// void DFS(int start,int dep)
// {
//     if(dep>=k)
//     {
//         return;
//     }
//     for(int i=start;i<n;i++)//下一个数要比前一个大
//     {
//         x[dep]=a[i];
//         DFS(i+1,dep+1);
//     }
// }
//重组合：可取重复元素  共k个
// void DFS(int start,int dep)
// {
//     if(dep>=k)
//     {
//         return;
//     }
//     for(int i=start;i<n;i++)//下一个数要比前一个大
//     {
//         x[dep]=a[i];
//         DFS(i,dep+1);
//     }
// }

//组合的应用：选数 对下标组合
// bool isprime(int x)
// {
//     if(!(x&1)&&x!=2) return false;
//     else if(x==2) return true;
//     for(i=3;i*i<x;i+=2)
//     {
//         if(x%i==0) return false;
//     }
//     return true;
// }
/*
//埃氏筛法
long long prime[M],check[M];
int tot=0;
void gPrime()
{
    for(int i=2;i<M;i++)
    {
        if(check[i]==0)
        {
            prime[tot++]=i;
            for(int j=2;j*i<M;j++) check[i*j]=1;
        }
    }
}
*/


//欧拉筛法 线性筛法
/*
void gPrime()
{
    for(int i=2;i<M;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
        }
        for(int j=0;j<tot;j++)
        {
            if(prime[j]*i>=M) break;
            check[prime[j]*i]=1;
            if(i%prime[j]==0) break; //最小质因子筛
        }
    }
}
*/

/*
费马小定理  p为素数  a^p-1 对p取余 = 1%p;  p不为素数 不成立
long long qpow(long long a,long long n,long long p)
{
    if(n==1) return a;
    long long temp=qpow(a,n>>1,p);
    if(n&1) return a*temp%p*temp%p;
    else return temp*temp%p;
}
bool isprime(long long x)
{
    long long a;srand(time(0));
    for(int i=0;i<4;i++)
    {
        a=rand()%(x-2)+2;  //(0,x-3)  (2,x-1)
        if(qpow(a,x-1)%x!=1) return false;
    }
    return true;
}
*/

// void DFS(int start,int dep)
// {
//     int sum;
//     if(dep>=k)
//     {
//         sum=0;
//         for(int i=0;i<k;i++) sum+=x[i];
//         //判定sum素数 随机测试法
//         return;
//     }
//     for(int i=start;i<n;i++)//下一个数要比前一个大
//     {
//         x[dep]=a[i];
//         DFS(i+1,dep+1);
//     }
// }

//填数字 两个1-7 中间有i个其他数字
// #include<iostream>
// #include<cstring>
// using namespace std;
// int num[14];
// bool vis[8];
// void DFS(int current,int depth)
// {
//     if(depth>=5)
//     {
//         for(int i=0;i<14;i++) cout<<num[i]<<" ";
//         cout<<endl;
//         return;
//     }
//     for(int j=1;j<=7;j++)
//     {
//         if(!vis[j]&&num[current+j+1]==0&&current+j+1<14)  //限制条件！
//         {
//             num[current]=num[current+j+1]=j;
//             vis[j]=1;
//             int i;
//             for(i=current+1;i<14;i++)
//             {
//                 if(num[i]==0) break;
//             }
//             DFS(i,depth+1);
//             vis[j]=0;
//             num[current]=num[current+j+1]=0;
//         }
//     }
// }
// int main()
// {
//     memset(num,0,sizeof(num));
//     memset(vis,0,sizeof(vis));
//     num[0]=num[8]=7;
//     num[1]=num[6]=4;
//     vis[7]=vis[4]=1;
//     DFS(2,0);
//     system("pause");
//     return 0;
// }
//数独！  i/3*3 j/3+3  i/3*3+2 j/3*j+2  确定小区域

//数的划分
//近似O(n^k) 通过剪枝降低复杂度
// #include<iostream>
// using namespace std;
// #define size 10
// int a[size];
// int b[size];
// int n,k;
// int temp;
// void DFS(int pre,int dep)
// {
//     if(dep>=k-1)
//     {
//         if(n-temp>=b[k-2])
//         {
//             for(int i=0;i<k-1;i++) cout<<b[i]<<" ";
//             cout<<n-temp<<" ";
//             cout<<endl;
//         }
//         return;
//     }
//     for(int i=pre;i<n;i++)
//     {
//         if(n-temp>=(k-dep)*i)//强剪枝 剩余数和不够剩余数分(avg)
//         {
//             b[dep]=i+1;
//             temp+=i+1;
//             DFS(i,dep+1);
//             temp-=i+1;
//         }
//         else break;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>n>>k)
//     {
//         temp=0;
//         DFS(0,0);
//     }
// }

//跳马周游棋盘 https://blog.csdn.net/crayondeng/article/details/17174951
//增量数组确定方向
// #include<iostream>
// #include<cstring>
// using namespace std;
// #define size 20
// int dir[8][2]={
//     {-2,-1},
//     {-2,1},
//     {2,1},
//     {2,-1},
//     {1,2},
//     {1,-2},
//     {-1,2},
//     {-1,-2}
// };
// int n;
// bool vis[20][20];
// bool canPut(int x,int y)
// {
//     if(x<0||x>=n) return false;
//     else if(y<0||y>=n) return false;
//     else if(vis[x][y]==1) return false;
//     return true;
// }
// bool finish;
// void DFS(int x,int y,int dep)
// {
//     int dx,dy;
//     if(finish)
//     {
//         return;
//     }
//     if(dep>=n*n-1)  //注意此时的终止条件
//     {
//         cout<<"Finished!"<<endl;
//         finish=true;
//         return;
//     }
//     for(int i=0;i<8;i++)
//     {
//         dx=x+dir[i][0];
//         dy=y+dir[i][1];
//         if(canPut(dx,dy))
//         {
//             vis[dx][dy]=1;
//             DFS(dx,dy,dep+1);
//             vis[dx][dy]=0;
//         }
//     }
// }
// int main()
// {
//     int x,y;
//     ios::sync_with_stdio(false);
//     while(cin>>n>>x>>y)
//     {
//         memset(vis,0,sizeof(vis));
//         finish=false;
//         vis[x][y]=1;
//         DFS(x,y,0);
//     }
// }

//迷宫问题    奇偶剪枝 0-0  1-1 步数为偶数  1-0 0-1 步数为奇数

//小木棍  TODO:严格剪枝
#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
#define size 65
bool vis[size];
int a[size];
int n, len, num; //len表示每根的长度  num 表示需要拼的根数 
//拼完一根后start=0重新从头考虑 k++ cur_len=0
//一根拼不完 DFS(k,cur_len-len[i],i+1)
bool DFS(int k, int cur_len, int start)
{
    int pre=0;
    if (k >= num ) //考虑拼num根
        return true;
    for (int i = start; i < n; i++)
    {
        if (!vis[i]&&pre!=a[i])
        {
            pre=0;
            if (cur_len + a[i] == len)
            {
                vis[i] = 1;
                if (DFS(k + 1, 0, 0))
                    return true;
                vis[i] = 0;
                pre=a[i];
                return false;//TODO:当出现加上某根木棍恰好能填满一根原始木棍,但由在后面的
                                    //搜索中失败了,就不必考虑其他木棍了,直接退出当前的枚举。
            }
            else if (cur_len + a[i] < len)
            {
                vis[i] = 1;
                if (DFS(k, cur_len + a[i], i + 1))
                    return true;
                vis[i] = 0;
                pre=a[i];
                if(cur_len==0) return false;//TODO::考虑每根原始木棍的第一根木棍,如果当前枚举的木棍长度无
                                            //        法得出合法解,就不必考虑下一根木棍了，当前木棍一定是作
                                            //        为某根原始木棍的第一根木棍的，现在不行,以后也不可能得
                                            //        出合法解。也就是说每根原始木棍的第一根小木棍一定要成
                                            //        功,否则就返回。因为每一根木棒都要用到。
                                            //https://www.cnblogs.com/mycapple/archive/2012/08/14/2638430.html
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int sum;
    int ans;
    while (cin >> n)
    {
        if(n==0) break;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n, greater<int>());//排序从大到小
        ans=sum;
        for (int i = a[0]; i <= sum; i++)
        {
            if (sum % i == 0)
            {
                len = i;
                num = sum / i;
                memset(vis, 0, sizeof(vis));
                if (DFS(0, 0, 0))
                {
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}