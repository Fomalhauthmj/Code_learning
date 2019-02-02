//TODO:引例:二分查找

//TODO:POJ 1226 Substrings 字符串排序按排序结果处理  string::find()!=string::npos
//http://poj.org/problem?id=1226
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define N 105
int n;
vector<string> V;
bool cmp(string s1,string s2)
{
    return s1.length()<s2.length();
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    string str;
    while(t--)
    {
        cin>>n;
        V.clear();
        for(int i=0;i<n;i++)
        {
            cin>>str;V.push_back(str);
        }
        sort(V.begin(),V.end(),cmp);
        if(n==1)
        {
            cout<<V[0].length()<<endl;
            continue;
        }
        int ans=0;
        bool finish=false;
        for(int len=V[0].length();len>0;len--)//子串长度
        {
            if(finish) break;
            for(int i=0;i<=(V[0].length()-len);i++)//起点
            {
                string sub=V[0].substr(i,len);
                string resub=sub;
                reverse(resub.begin(),resub.end());
                bool flag=false;
                for(int k=1;k<n;k++)
                {
                    //或者以str&rts的形式处理
                    if(V[k].find(sub)!=string::npos||V[k].find(resub)!=string::npos)
                    {
                        flag=true;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) 
                {
                    ans=len;
                    //cout<<sub<<endl;
                    finish=true;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}
*/

//TODO: HDU 1239
//http://acm.hdu.edu.cn/showproblem.php?pid=1239
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 10010 //9592
int prime[N];
int p_cnt;
int m,a,b;
bool not_prime[N];
void get_Prime()
{
    memset(not_prime,0,sizeof(not_prime));
    p_cnt=0;
    for(int i=2;i<N;i++)
    {
        if(!not_prime[i])
        {
            prime[p_cnt++]=i;
        }
        for(int j=0;j<p_cnt;j++)
        {
            if(prime[j]*i>=N) break;
            not_prime[prime[j]*i]=true;
            if(i%prime[j]==0) break; //最小质因子筛
        }
    }
} 
int main()
{
    ios::sync_with_stdio(false);
    get_Prime();
    while(cin>>m>>a>>b)
    {
        if(m+a+b==0) break;
        long long temp=0;
        int p,q;//TODO:最优证明 p,q<10000
        for(int i=0;i<p_cnt;i++)//p
        {
            if(prime[i]>m) break;
            for(int j=i;j<p_cnt;j++)//q
            {
                if(prime[i]*prime[j]>m) break;
                if(prime[i]*prime[j]<=m&&a*prime[j]<=b*prime[i])
                {
                    if(temp<prime[i]*prime[j])
                    {
                        temp=prime[i]*prime[j];
                        p=prime[i];
                        q=prime[j];
                    }
                }
            }
        }
        cout<<p<<" "<<q<<endl;
    }
}
*/

//TODO:邻接矩阵
//TODO:二维vector：vector<int> G[N]
//TODO:邻接表
//TODO:链式前向星
//TODO:http://codeforces.com/problemset/problem/377/A
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 510
char maze[N][N];
bool vis[N][N];
bool flag[N][N];
int n,m,k;
int empty_area;
int startr,startc;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
//当通路数达到empty_area-k 时退出DFS
int need_find;
bool legal(int row,int col)
{
    if(row<0||row>=n) return false;
    if(col<0||col>=m) return false;
    if(maze[row][col]!='.') return false;
    if(vis[row][col]==1) return false;
    return true;
}
void DFS(int row,int col)
{
    if(need_find==0) return;
    vis[row][col]=1;//TODO:注意这里条件及状态的书写
    flag[row][col]=1;
    need_find--;
    for(int i=0;i<4;i++)
    {
        int next_r=row+dir[i][0];
        int next_c=col+dir[i][1];
        if(legal(next_r,next_c))//TODO:边界检查 多条件 易错！
        {
            DFS(next_r,next_c);
        }
    }
    return;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!flag[i][j]&&maze[i][j]=='.') cout<<'X';
            else cout<<maze[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        empty_area=0;
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               cin>>maze[i][j];
               if(maze[i][j]=='.') 
               {
                   empty_area++;
                   startr=i;startc=j;
               }
           }
        }
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        need_find=empty_area-k;
        DFS(startr,startc);
        print();
    }
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 510
char maze[N][N];
bool vis[N][N];
int n,m,k;
int startr,startc;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool legal(int row,int col)
{
    if(row<0||row>=n) return false;
    if(col<0||col>=m) return false;
    if(maze[row][col]!='.') return false;
    if(vis[row][col]==1) return false;
    return true;
}
void DFS(int row,int col)
{
    if(k==0) return;
    vis[row][col]=1;//TODO:注意这里条件及状态的书写
    for(int i=0;i<4;i++)
    {
        int next_r=row+dir[i][0];
        int next_c=col+dir[i][1];
        if(legal(next_r,next_c))//TODO:边界检查 多条件 易错！
        {
            DFS(next_r,next_c);
            if(k>0) 
            {
                maze[next_r][next_c]='X';//回退即改为墙,只要找到k个回退点即可
                k--;
            }
            else return;
        }
    }
    return;
}
int main()
{
   ios::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               cin>>maze[i][j];
               if(maze[i][j]=='.') 
               {
                   startr=i;startc=j;
               }
           }
        }
        memset(vis,0,sizeof(vis));
        DFS(startr,startc);
        for(int i=0;i<n;i++)//print
        {
            for(int j=0;j<m;j++)
            {
                cout<<maze[i][j];
            }
            cout<<endl;
        }
    }
}
//TODO:
3 4 2
#...
.#..
#...

#...
.#..
#XX.
//Pavel drew a grid maze with all empty cells forming a connected area. 
//That is, you can go from any empty cell to any other one. 
//上述样例不成立
*/

//TODO:http://codeforces.com/problemset/problem/120/F
//如何求树的直径？两次DFS 从任意点出发 再以其最远距点为第二次起点寻找最远距点 就为树的直径

/*
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define N 110
vector<int> V[N];//V[i]表示与i相连的点 
int n;
int dis[N];
int max_dis;
int max_point;
//根据树的特性 只向子结点搜索 或vis
void DFS(int start,int pre)
{
    dis[start]=dis[pre]+1;
    if(dis[start]>max_dis)
    {
        max_dis=dis[start];
        max_point=start;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next_point=V[start][i];
        if(V[start][i]!=pre)
        {
            DFS(next_point,start);//注意这里pre=start
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);//文件输入输出
    freopen("output.txt","w",stdout);
    int T;
    while(cin>>T)
    {
        int ans=0;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;i++) V[i].clear();
            int a,b;
            for(int i=1;i<=n-1;i++)
            {
                cin>>a>>b;
                V[a].push_back(b);//无向图双向
                V[b].push_back(a);
            }
            memset(dis,0,sizeof(dis));
            dis[0]=-1;
            max_dis=0;
            DFS(1,0);
            memset(dis,0,sizeof(dis));
            dis[0]=-1;
            max_dis=0;
            DFS(max_point,0);
            ans+=max_dis;
        }
        cout<<ans<<endl;
    }
}
*/

//TODO:https://arc078.contest.atcoder.jp/tasks/arc078_b
//Best:TODO:比较到1和到n的距离 离哪个点更近属于哪个点 距离相等属于先手！
/*
#include<iostream>
#include<vector>
#define N 100010
using namespace std;
vector<int> V[N];
int n;
int dis_from_1[N];
int dis_from_n[N];
void DFS(int start,int pre,bool mode)
{
    if(mode)
    {
        dis_from_1[start]=dis_from_1[pre]+1;
    }
    else
    {
        dis_from_n[start]=dis_from_n[pre]+1;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre)
        {
            DFS(next,start,mode);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int a,b;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dis_from_1[0]=-1;
        DFS(1,0,true);
        dis_from_n[0]=-1;
        DFS(n,0,false);
        int F_point=0;
        int S_point=0;
        for(int i=1;i<=n;i++)
        {
            if(dis_from_1[i]<=dis_from_n[i]) F_point++;
            else S_point++;
        }
        //cout<<"F:"<<F_point<<"  S:"<<S_point<<endl;
        if(F_point>S_point) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}
*/
//Other:TODO:用DFS确定1-n的路径分界点 然后搜索分界点的子结点数
/*
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define N 100010
vector<int> V[N];
int n;
int parent[N];//记录父结点
int dis_from_1[N];
void DFS(int start,int pre)
{
    dis_from_1[start]=dis_from_1[pre]+1;
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre) 
        {
            parent[next]=start;//确定父结点
            DFS(next,start);
        }
    }
}
int S_count;
void DFS_for_count(int start,int pre)
{
    S_count++;
    //cout<<"start: "<<start<<" pre:"<<pre<<endl;
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        //cout<<"next:"<<next<<endl;
        if(next!=pre) 
        {
            DFS_for_count(next,start);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int a,b;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dis_from_1[0]=-1;
        DFS(1,0);
        int k=dis_from_1[n]-1;//路径点数
        int cur_point=n;
        int cnt=0;//S
        int now_parent=parent[n];
        while(1)
        {
            if(cnt>=k-ceil(k/2.0)||now_parent==1)   break; //找到分界点或强制退出
            cur_point=now_parent;
            now_parent=parent[cur_point];
            cnt++;
        }
        //cout<<"cur_point:"<<cur_point<<"now_parent:"<<now_parent<<endl;
        S_count=0;
        DFS_for_count(cur_point,now_parent);
        //cout<<"F:"<<n-S_count<<endl;
        //cout<<"S:"<<S_count<<endl;
        if(n>2*S_count) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}
*/
//TODO:http://codeforces.com/problemset/problem/700/B
/*
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define N 200010
int n,k;
vector<int> V[N];
int count[N];
bool is_University[N];
void DFS_for_count(int start,int pre)
{
    if(is_University[start]) count[start]++;
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre) 
        {
            DFS_for_count(next,start);
            //回溯时加上子树统计点数
            count[start]+=count[next];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        int a,b,u;
        for(int i=1;i<=n;i++) V[i].clear();
        memset(is_University,0,sizeof(is_University));
        memset(count,0,sizeof(count));
        for(int i=1;i<=2*k;i++)
        {
            cin>>u;
            is_University[u]=true;
        }
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        DFS_for_count(1,0);
        long long ans=0;
        for(int i=2;i<=n;i++)//n-1条边遍历
        {
            ans+=min(count[i],2*k-count[i]);
        }
        cout<<ans<<endl;
    }
}
*/

//TODO:大臣的旅费（第四届A组预赛题10）
/*
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define N 200010
int n;
vector< pair<int,int> > V[N];
int max_dis;
int max_point;
int dis[N];
void DFS(int start,int pre,int pre_dis)
{
    dis[start]=dis[pre]+pre_dis;
    if(dis[start]>max_dis)
    {
        max_dis=dis[start];
        max_point=start;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i].first;
        if(next!=pre)
        {
            DFS(next,start,V[start][i].second);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int p,q,d;
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            cin>>p>>q>>d;
            V[p].push_back(make_pair(q,d));
            V[q].push_back(make_pair(p,d));
        }
        //找最长路
        dis[0]=-1;
        max_dis=0;
        DFS(1,0,1);
        dis[0]=-1;
        max_dis=0;
        DFS(max_point,0,1);
        long ans=max_dis*10+max_dis*(max_dis+1)/2;
        cout<<ans<<endl;
    }
}
*/

//TODO:剪格子（第四届A组预赛题9）
//TODO:DFS_all_possible_solution
/*
3 3
1 2 1
1 4 2
2 3 4
*/
//如果不判断剩余块能否成为连通块 此数据ans:4 应为：5
/*
3 3
1 2 3
6 4 -1
-1 8 -2
*/
//DFS 分叉情况无解(1 2 3 4)
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 15
#define inf 0x3f3f3f3f
int block[N][N];
int all_sum;
int min_ans;
int r,c;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int temp_count;
bool vis[N][N];
bool vis_for_count[N][N];
bool legal(int nr,int nc)
{
    if(nr<1||nr>r) return false;
    if(nc<1||nc>c) return false;
    if(vis[nr][nc]) return false;
    return true;
}
void DFS_for_count(int start_r,int start_c)
{
    temp_count++;
    //cout<<"r:"<<start_r<<" c:"<<start_c<<endl;
    for(int i=0;i<4;i++)
    {
        int next_r=start_r+dir[i][0];
        int next_c=start_c+dir[i][1];
        if(legal(next_r,next_c)&&!vis_for_count[next_r][next_c])
        {
            vis_for_count[next_r][next_c]=1;
            DFS_for_count(next_r,next_c);
        }
    }
}
int temp_ans;
void DFS(int start_r,int start_c,int cur_sum)
{
    //cout<<"r:"<<start_r<<" c:"<<start_c<<" sum:"<<cur_sum<<endl;
    //缺少剪枝？
    if(temp_ans>min_ans) return;//强剪枝
    if(cur_sum*2>all_sum)
    {
        return;
    }
    if(cur_sum*2==all_sum)
    {
        bool flag=false;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(!vis[i][j])
                {
                    memset(vis_for_count,0,sizeof(vis_for_count));//init
                    vis_for_count[i][j]=1;
                    temp_count=0;
                    DFS_for_count(i,j);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        //cout<<"temp ans:"<<temp_ans<<"  temp_count:"<<temp_count<<endl;
        if(temp_count+temp_ans==r*c) 
        {
            //cout<<"temp ans:"<<temp_ans<<"  temp_count:"<<temp_count<<endl;
            min_ans=min(min_ans,temp_ans);
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int next_r=start_r+dir[i][0];
        int next_c=start_c+dir[i][1];
        if(legal(next_r,next_c))
        {
            temp_ans++;
            vis[next_r][next_c]=1;
            DFS(next_r,next_c,cur_sum+block[next_r][next_c]);
            temp_ans--;
            vis[next_r][next_c]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>c>>r)
    {
        all_sum=0;
        min_ans=inf;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>block[i][j];
                all_sum+=block[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        temp_ans=1;
        vis[1][1]=1;
        DFS(1,1,block[1][1]);
        if(min_ans!=inf) cout<<min_ans<<endl;//无法分割输出0
        else cout<<0<<endl;
    }   
}
*/

//TODO:http://lx.lanqiao.cn/problem.page?gpid=T36
//TODO:网络寻路
/*
#include<iostream>
#include<vector>
using namespace std;
#define N 10010
vector<int> V[N];
int n,m;
long long ans;
int each_ans;
int trans[2];
bool judge(int start,int end)
{
    if(start==trans[0]||start==trans[1]) return false;
    if(end==trans[0]||end==trans[1]) return false;
    return true;
}
void DFS(int init,int start,int pre,int k)
{
    if(k>3) return;
    if(k==3)//路线确定
    {
        //cout<<init<<"->"<<trans[0]<<"->"<<trans[1]<<"->"<<start<<endl;
        if(judge(init,start))
        {
            each_ans++;
        }
        return;
    }
    for(int i=0;i<V[start].size();i++)
    {
        if(k>=1) trans[k-1]=start;
        int next=V[start][i];
        if(next!=pre)//避免重复点
        {
            DFS(init,next,start,k+1);//这里不能用k++
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        int u,v;
        ans=0;
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            V[u].push_back(v);
            V[v].push_back(u);//双向路
        }
        //选择任意一个节点
        for(int i=1;i<=n;i++)
        {
            each_ans=0;
            trans[2]={0};
            DFS(i,i,0,0);
            ans+=each_ans;
        }
        cout<<ans<<endl;
    }
}
*/
//TODO:从边的角度出发 枚举边的贡献 求和 复杂度极小
/*
#include<iostream>
#include<vector>
using namespace std;
#define N 10010
vector<int> V[N];
int n,m;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        int u,v;
        ans=0;
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            V[u].push_back(v);
            V[v].push_back(u);//双向路
        }
        //枚举边
        ans=0;
        int left,right;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                //left:i right:V[i][j]
                left=i;
                right=V[i][j];
                ans+=(V[right].size()-1)*(V[left].size()-1);//此处无需x2 因为每个顶点都被遍历
            }
        }
        cout<<ans<<endl;
    }
}
*/

//TODO:奇偶剪枝

//TODO:http://acm.hdu.edu.cn/showproblem.php?pid=1241
//求联通子图
/*
#include<iostream>
#include<cstring>
using namespace std;
#define size 105
char map[size][size];
int m,n;
int ans;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[size][size];
bool legal(int r,int c)
{
    if(vis[r][c]) return false;
    if(r<0||r>=m) return false;
    if(c<0||c>=n) return false;
    return true;
}
void DFS(int sr,int sc)
{
    vis[sr][sc]=1;
    for(int k=0;k<8;k++)
    {
        int nr=sr+dir[k][0];
        int nc=sc+dir[k][1];
        if(legal(nr,nc)&&map[nr][nc]=='@')
        {
            DFS(nr,nc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n)
    {
        if(m==0) break;
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j]=='@'&&!vis[i][j])
                {
                    ans++;
                    DFS(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
}
*/

//Other:并查集
/*
#include<iostream>
using namespace std;
#define N 105
int n,m;
int par[N*N];
char G[N][N];
int num_all,num_u;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool legal(int r,int c)
{
    if(r<0||r>=n) return false;
    if(c<0||c>=m) return false;
    return true;
}
void init()
{
    for(int i=0;i<n*m;i++)
    {
        par[i]=i;
    }
}
int Find(int x)
{
    if(par[x]==x) return x;
    else par[x]=Find(par[x]);
    return par[x];
}
void Union(int r1,int c1,int r2,int c2)
{
    int px=Find(r1*m+c1);
    int py=Find(r2*m+c2);
    if(px!=py)
    {
        par[px]=par[py];
        num_u++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        num_all=num_u=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>G[i][j];
                if(G[i][j]=='@') num_all++;
            }
        }
        init();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(G[i][j]=='@')
                {
                    for(int k=0;k<8;k++)
                    {
                        int ux=i+dir[k][0];
                        int uy=j+dir[k][1];
                        if(G[ux][uy]=='@'&&legal(ux,uy)) Union(i,j,ux,uy);
                    }
                }
            }
        }
        cout<<num_all-num_u<<endl;
    }
}
*/

//TODO:剪邮票 ans：116
/*
#include<iostream>
#include<cstring>
using namespace std;
int a[13];
int b[3][4];
bool visb[3][4];
int ans;
int temp_count;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool legal(int r,int c)
{
    if(r<0||r>=3) return false;
    if(c<0||c>=4) return false;
    if(visb[r][c]) return false;
    if(b[r][c]!=1) return false;
    return true;
}
void DFS_for_count(int r,int c)
{
    temp_count++;
    visb[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(legal(nr,nc))
        {
            DFS_for_count(nr,nc);
        }
    }
}
bool judge()
{
    temp_count=0;
    memset(visb,0,sizeof(visb));
    bool finish=false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(b[i][j]==1)
            {
                DFS_for_count(i,j);
                finish=true;
                break;
            }
        }
        if(finish) break;
    }
    if(temp_count==5) return true;
    else return false;
}
void DFS(int depth,int start)
{
    if(depth>=5)
    {
        if(judge()) ans++;
        return;
    }
    for(int i=start;i<12;i++)
    {
        int r=i/4;
        int c=i%4;
        b[r][c]=1;//取
        DFS(depth+1,i+1);//下一DFS
        b[r][c]=0;//不取
    }
}
int main()
{
    ans=0;
    memset(b,0,sizeof(b));
    DFS(0,0);
    cout<<ans<<endl;
    system("pause");
}
*/

//other:next_permutation：792 12！/5！*7！
//初始排序须为字典序最小
/*
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int b[3][4];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[3][4];
bool legal(int r,int c)
{
    if(r<0||r>=3) return false;
    if(c<0||c>=4) return false;
    if(vis[r][c]) return false;
    if(b[r][c]!=1) return false;
    return true;
}
int temp_cnt;
void DFS(int r,int c)
{
    temp_cnt++;
    vis[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(legal(nr,nc)) 
        {
            DFS(nr,nc);
        }
    }
}
int main()
{
    int a[12]={
            0,0,0,0,0,
            0,0,1,1,1,
            1,1};
    int ans=0;
    do
    {
        int cnt=0;
        int startr,startc;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                b[i][j]=a[cnt++];
                if(b[i][j]==1)
                {
                    startr=i;
                    startc=j;
                }
            }
        }
        temp_cnt=0;
        memset(vis,0,sizeof(vis));
        DFS(startr,startc);
        if(temp_cnt==5) 
        {
            ans++;
        }
    }while(next_permutation(a,a+12));
    cout<<ans<<endl;
    system("pause");
}
*/

//TODO:BFS
//TODO:http://acm.hdu.edu.cn/showproblem.php?pid=1372
/*
#include<string>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 10
string a,b;
int start_r,start_c,end_r,end_c;
int board[N][N];
//马走日共8个方向
bool vis[N][N];
int dir[8][2]={ {1,2},{1,-2},{2,1},{2,-1},
                {-1,-2},{-1,2},{-2,-1},{-2,1}
                };
queue<pair<int,int>> Q;
bool legal(int r,int c)
{
    if(r<1||r>8) return false;
    if(c<1||c>8) return false;
    if(vis[r][c]) return false;
    return true;
}
int BFS(int sr,int sc)
{
    while(!Q.empty()) Q.pop();
    Q.push(make_pair(sr,sc));
    board[sr][sc]=0;
    vis[sr][sc]=1;
    while(!Q.empty())
    {
        pair<int,int> now=Q.front();
        if(now.first==end_r&&now.second==end_c)//走到终点
        {
            return board[end_r][end_c];
        }
        Q.pop();
        for(int i=0;i<8;i++)
        {
            int nr=now.first+dir[i][0];
            int nc=now.second+dir[i][1];
            if(legal(nr,nc))
            {
                vis[nr][nc]=1;
                board[nr][nc]=board[now.first][now.second]+1;
                Q.push(make_pair(nr,nc));
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        start_r=a[1]-'0';
        start_c=a[0]-'a'+1;
        end_r=b[1]-'0';
        end_c=b[0]-'a'+1;
        //cout<<start_r<<" "<<start_c<<endl;
        //cout<<end_r<<" "<<end_c<<endl;
        memset(vis,0,sizeof(vis));
        int ans=BFS(start_r,start_c);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves."<<endl;
    }
}
*/

//TODO:https://arc078.contest.atcoder.jp/tasks/arc078_b
/*
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define N 100010
vector<int> V[N];
queue<int> Q;
bool vis[N];
int dis_from_1[N];
int dis_from_n[N];
int n;
void BFS(int start,bool mode)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(vis,0,sizeof(vis));
    vis[start]=1;
    if(mode) dis_from_1[start]=0;
    else dis_from_n[start]=0;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(mode)    dis_from_1[next]=dis_from_1[now]+1;
            else        dis_from_n[next]=dis_from_n[now]+1;
            if(!vis[next])
            {
                vis[next]=1;
                Q.push(next);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int a,b;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }//成图
        //分别从1,N BFS比较距离
        BFS(1,true);
        BFS(n,false);
        int first_num=0;
        int second_num=0;
        for(int i=1;i<=n;i++)
        {
            if(dis_from_1[i]<=dis_from_n[i]) first_num++;
            else second_num++;
        }
        if(first_num>second_num) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}
*/

//TODO:http://codeforces.com/problemset/problem/689/B
/*
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define N 200010
vector<int> V[N];
int ans[N];
bool vis[N];
queue<int> Q;
int n;
void BFS(int start)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(!vis[next])
            {
                ans[next]=ans[now]+1;
                vis[next]=1;
                Q.push(next);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int ai;
        for(int i=1;i<=n;i++)
        {
            //将到i点距离为1的点加入
            cin>>ai;
            if(ai!=i)
            {
                V[i].push_back(ai);//有向
            }
            V[i].push_back(i+1);
            V[i+1].push_back(i);//无向
        }
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        vis[1]=1;
        BFS(1);
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i];
            if(i!=n) cout<<" ";
        }
        cout<<endl;
    }
}
*/

//TODO:http://codeforces.com/contest/208/problem/C
//TODO:最短路条数,每边有多少最短路经过,枚举放置点位置
//TODO:修改BFS 分别获得1->k 和 n->k 的最短路数 乘积即为经过k点的最短路数 乘法原理
//TODO:dis_from_1[],dis_from_n[] 若dis_from_1[i]+dis_from_n[i]==最短路长 则i在最短路上，缩小范围
//DFS(限制路长和方向)求出最短路径数
//TODO:TLE on test18
/*
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
#define N 105
int n,m;
vector<int> V[N];
queue<int> Q;
int dis_from_1[N];
int dis_from_n[N];
bool vis[N];
bool is_on[N];
int path;//最短路径数
int G[N];
int P[N];
int cnt;
void BFS(int start,bool mode)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(vis,0,sizeof(vis));
    vis[start]=1;
    if(mode) dis_from_1[1]=0;
    else dis_from_n[n]=0;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(!vis[next])
            {
                vis[next]=1;
                if(mode) dis_from_1[next]=dis_from_1[now]+1;
                else    dis_from_n[next]=dis_from_n[now]+1;
                Q.push(next);
            }
        }
    }
}
void DFS(int start)
{
    if(start==n)
    {
        path++;
        for(int i=1;i<=cnt;i++) G[P[i]]++;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(is_on[next]&&dis_from_1[next]==dis_from_1[start]+1)//控制DFS方向
        {
            P[cnt++]=next;
            DFS(next);
            cnt--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int v,u;
        for(int i=1;i<=m;i++)
        {
            cin>>v>>u;
            V[v].push_back(u);
            V[u].push_back(v);
        }
        BFS(1,true);
        //cout<<"min len:"<<dis_from_1[n]<<endl;
        BFS(n,false);
        //cout<<"min len:"<<dis_from_n[1]<<endl;
        //确定最短路上的点
        memset(is_on,0,sizeof(is_on));
        for(int i=1;i<=n;i++)
        {
            if(dis_from_1[i]+dis_from_n[i]==dis_from_1[n]) is_on[i]=1;
        }
        path=0;
        memset(G,0,sizeof(G));
        cnt=1;
        DFS(1);
        //cout<<"path:"<<path<<endl;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(is_on[i])
            {
                //cout<<i<<":"<<G[i]<<endl;
                if(i!=1&&i!=n) ans=max(ans,2*G[i]);
                else ans=max(ans,G[i]);
            }
        }
        cout<<fixed<<setprecision(12)<<ans*1.0/path<<endl;
    }
}
*/

//TODO: 修改BFS
/*
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
#define N 105
int n,m;
vector<int> V[N];
queue<int> Q;
int dis_from_1[N];
int dis_from_n[N];
long long path_from_1[N];
long long path_from_n[N];
bool vis[N];
long long path;//最短路径数
void BFS_from_1(int start)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(vis,0,sizeof(vis));
    vis[start]=1;
    dis_from_1[1]=0; //init
    path_from_1[1]=1;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(!vis[next])
            {
                vis[next]=1;
                dis_from_1[next]=dis_from_1[now]+1;
                path_from_1[next]=path_from_1[now];
                Q.push(next);
            }
            else if(dis_from_1[next]==dis_from_1[now]+1&&vis[next])
            {
                path_from_1[next]+=path_from_1[now];
            }
        }
    }
}
void BFS_from_n(int start)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(vis,0,sizeof(vis));
    vis[start]=1;
    dis_from_n[n]=0; //init
    path_from_n[n]=1;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(!vis[next])
            {
                vis[next]=1;
                dis_from_n[next]=dis_from_n[now]+1;
                path_from_n[next]=path_from_n[now];
                Q.push(next);
            }
            else if(dis_from_n[next]==dis_from_n[now]+1&&vis[next])
            {
                path_from_n[next]+=path_from_n[now];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int v,u;
        for(int i=1;i<=m;i++)
        {
            cin>>v>>u;
            V[v].push_back(u);
            V[u].push_back(v);
        }
        BFS_from_1(1);
        //cout<<"min len:"<<dis_from_1[n]<<endl;
        BFS_from_n(n);
        //cout<<"min len:"<<dis_from_n[1]<<endl;
        //确定最短路上的点
        path=path_from_1[n];
        //cout<<"path:"<<path<<endl;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
           if(dis_from_1[i]+dis_from_n[i]==dis_from_1[n])   
           {
               if(i==1||i==n) ans=max(ans,path_from_1[i]*path_from_n[i]);
               else ans=max(ans,path_from_1[i]*path_from_n[i]*2);
           }
        }
        cout<<fixed<<setprecision(12)<<ans*1.0/path<<endl;
    }
}
*/

//TODO:
//http://codeforces.com/problemset/problem/796/D
/*
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define N 300010
int n,k,d;
vector<pair<int,int>> G[N]; //第二维为边的编号
queue<int> Q;
bool vis_for_v[N];
bool vis_for_e[N];
vector<int> ans;
void BFS()
{
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(auto e:G[now])
        {
            int cur=e.first;
            int ei=e.second;
            if(!vis_for_v[cur])//此顶点未访问
            {
                vis_for_v[cur]=1;
                vis_for_e[ei]=1;
                Q.push(cur);
            }
            else//此顶点已访问
            {
                if(!vis_for_e[ei])//此边未访问 可删除
                {
                    ans.push_back(ei);
                    vis_for_e[ei]=1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k>>d)
    {
        while(!Q.empty()) Q.pop();//init
        memset(vis_for_v,0,sizeof(vis_for_v));
        memset(vis_for_e,0,sizeof(vis_for_e));
        for(int i=1;i<=n;i++) G[i].clear();
        int ps;
        for(int i=1;i<=k;i++)
        {
            cin>>ps;
            Q.push(ps);
            vis_for_v[ps]=1;
        }
        int u,v;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u>>v;
            G[u].push_back(make_pair(v,i));
            G[v].push_back(make_pair(u,i));
        }
        ans.clear();
        BFS();
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(i!=ans.size()-1) cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
    }
}
*/

//或者顶点属于哪个ps belong[N];
/*
belong[ps]=ps;//init
belong[cur]=belong[now];//未访问
belong[cur]!=belong[now];//已访问 属于不同ps ans++
*/
/*
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define N 300010
int n,k,d;
vector<pair<int,int>> G[N]; //第二维为边的编号
queue<int> Q;
bool vis_for_v[N];
bool vis_for_e[N];
int belong[N];
vector<int> ans;
void BFS()
{
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(auto e:G[now])
        {
            int cur=e.first;
            int ei=e.second;
            if(!vis_for_v[cur])//此顶点未访问
            {
                vis_for_v[cur]=1;
                belong[cur]=belong[now];
                Q.push(cur);
            }
            else//此顶点已访问
            {
                if(belong[cur]!=belong[now]&&!vis_for_e[ei])//两点属于不同ps 删除边
                {
                    ans.push_back(ei);
                    vis_for_e[ei]=1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k>>d)
    {
        while(!Q.empty()) Q.pop();//init
        memset(vis_for_v,0,sizeof(vis_for_v));
        memset(belong,0,sizeof(belong));
        memset(vis_for_e,0,sizeof(vis_for_e));
        for(int i=1;i<=n;i++) G[i].clear();
        int ps;
        for(int i=1;i<=k;i++)
        {
            cin>>ps;
            Q.push(ps);
            vis_for_v[ps]=1;
            belong[ps]=ps;
        }
        int u,v;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u>>v;
            G[u].push_back(make_pair(v,i));
            G[v].push_back(make_pair(u,i));
        }
        ans.clear();
        BFS();
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(i!=ans.size()-1) cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
    }
}
*/

//TODO:Nim博弈 能从某一状态到P状态则该状态为N状态 从某一状态的后继状态都为N状态则该状态为P状态
//http://codeforces.com/gym/101246/problem/D
/*
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define N 1010
vector<int> G[N];
queue<int>  Q;
int n,m;
bool vis[N];
bool status[N];
int dis[N];
stack<int> S;//BFS反序
void BFS(int start)
{
    while(!Q.empty())   Q.pop();
    while(!S.empty())   S.pop();
    memset(vis,0,sizeof(vis));
    Q.push(start);
    S.push(start);
    dis[start]=0;
    vis[start]=1;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(auto next:G[now])
        {
            if(!vis[next])//未访问
            {
                dis[next]=dis[now]+1;
                vis[next]=1;
                Q.push(next);
                S.push(next);
            }//已访问不处理
        }
    }
    memset(status,0,sizeof(status));
    while(!S.empty())
    {
        int now=S.top();
        S.pop();
        for(auto ele:G[now])
        {
            if(dis[now]==dis[ele]+1&&status[now]==0) 
                status[ele]=1;//注意这里NP点的判断  WA:判断太复杂 其实只有01两种情况
        }
        //cout<<"now:"<<now<<"    dis:"<<dis[now]<<" status:"<<status[now]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) G[i].clear();
        int a,b;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        BFS(1);
        if(status[1]) cout<<"Vladimir"<<endl;
        else cout<<"Nikolay"<<endl;
    }
}
*/

//TODO:https://codeforces.com/contest/676/problem/D
//TODO:五种状态 4个方向+旋转 旋转次数不可以为全局变量 应与每个状态相关
/*
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 1010
//用二进制表示门 0-15共16种状态 判断是否有门 &  位右移来表示旋转
char ch;
int n, m;
int maze[N][N];
int vis[N][N][5]; //不超过四次？
int stx, sty;
int edx, edy;
struct node
{
    int x;
    int y;
    int rots;
    int len;
    node() : rots(0), len(0){};
    node(int r, int c, int l, int t) : x(r), y(c), len(l), rots(t){};
};
int trans(char ch) //上右下左
{
    switch (ch)
    {
    case '+':
        return 15; //1111
    case '-':
        return 5; //0101
    case '*':
        return 0; //0000
    case '^':
        return 8; //1000
    case 'v':
        return 2; //0010
    case '<':
        return 1; //0001
    case '>':
        return 4; //0100
    case '|':
        return 10; //1010
    case 'L':
        return 14; //1110 与0001&
    case 'R':
        return 11; //1011 与0100&
    case 'U':
        return 7; //0111  与1000&
    case 'D':
        return 13; //1101 与0010&
        //这里共12种状态
    }
}
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; //左下右上
bool legal(int r, int c)
{
    if (r < 1 || r > n)
        return false;
    if (c < 1 || c > m)
        return false;
    return true;
}
int BFS()
{
    int ans = -1;
    queue<node> Q;
    Q.push(node(stx, sty, 0, 0));
    memset(vis, 0, sizeof(vis));
    vis[stx][sty][0] = 1; //未选择下已访问
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        //cout << "r:" << now.x << " c:" << now.y << "  rot:" << now.rots << " len: " << now.len << endl;
        if (now.x == edx && now.y == edy)
        {
            ans = now.len;
            return ans;
        }
        for (int i = 0; i < 4; i++) //当前方向 i 对应方向(i+2)%4
        {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (!vis[dx][dy][now.rots] && legal(dx, dy)) //未访问
            {
                if 
                (
                    (maze[now.x][now.y] & (1 << ((i+now.rots)%4))) 
                    && 
                    (maze[dx][dy]       & (1 << ((i+2+now.rots)%4)))
                )
                {
                    Q.push(node(dx, dy, now.len + 1, now.rots));
                    vis[dx][dy][now.rots] = 1;
                }
            }
        }
        if (!vis[now.x][now.y][(now.rots + 1) % 4]) //第五种状态旋转
        {
            Q.push(node(now.x, now.y, now.len + 1, (now.rots + 1) % 4));
            vis[now.x][now.y][(now.rots + 1) % 4] = 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;
                maze[i][j] = trans(ch);
            }
        }
        cin >> stx >> sty >> edx >> edy;
        cout << BFS() << endl;
    }
}
*/

//TODO:http://codeforces.com/contest/1037/problem/D

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
#define N 200010
int n;
vector<int> G[N];
int s[N];
queue<int> Q;
bool vis[N];
set<int> S1;//保存当前点的下一可访问点
set<int> S2;//保存待检验点
int pos;
set<int>::iterator it1;
set<int>::iterator it2;
bool BFS()
{
    memset(vis,0,sizeof(vis));
    while(!Q.empty()) Q.pop();
    Q.push(1);
    pos=2;
    vis[1]=1;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        S1.clear();
        for(auto ele:G[now])
        {
            if(!vis[ele])
            {
                vis[ele]=1;
                S1.insert(ele);
            }
        }//S1添加完毕
        //检验S1中元素与S2待检测序列中元素
        S2.clear();
        for(int i=pos;i<pos+S1.size();i++)
        {
            S2.insert(s[i]);
        }
        /*
        cout<<"S1:";
        for(auto ele:S1)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
        cout<<"S2:";
        for(auto ele:S2)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
        */
        for(it1=S1.begin(),it2=S2.begin();it1!=S1.end()&&it2!=S2.end();it1++,it2++)
        {
            //cout<<*it1<<" "<<*it2<<endl;
            if(*it1!=*it2) return false;
        }
        //cout<<"add:";
        for(int i=pos;i<pos+S1.size();i++) 
        {
            //cout<<s[i]<<" ";
            Q.push(s[i]);
        }
        //cout<<endl;
        pos+=S2.size();
        if(pos>n) break;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int a,b;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        if(s[1]!=1)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(BFS()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
