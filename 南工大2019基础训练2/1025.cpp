#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
//回溯法  
//->状态压缩
int matrix[6][6];
long long ans=0;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[6][6];
int cnt=1;
void DFS(int r,int c)
{
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(nr>=0&&nr<6&&nc>=0&&nc<6&&matrix[nr][nc]&&!vis[nr][nc])
        {
            vis[nr][nc]=1;
            cnt++;
            DFS(nr,nc);
        }
    }
}

int BFS(int r,int c)
{
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    memset(vis,0,sizeof(vis));
    vis[r][c]=1;
    int cnt=1;
    while(!q.empty())
    {
        pair<int,int> now=q.front();
        q.pop();
        int nr,nc;
        for(int i=0;i<4;i++)
        {
            nr=now.first+dir[i][0];
            nc=now.second+dir[i][1];
            if(nr>=0&&nr<6&&nc>=0&&nc<6&&matrix[nr][nc]&&!vis[nr][nc])
            {
                cnt++;
                vis[nr][nc]=1;
                q.push(make_pair(nr,nc));
            }
        }
    }
    return cnt==18;
}
bool judge()
{
    bool flag=false;
    int sr,sc;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(matrix[i][j]==1)
            {
                sr=i;
                sc=j;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    memset(vis,0,sizeof(vis));
    cnt=1;
    vis[sr][sc]=1;
    DFS(sr,sc);
    if(cnt==18) return true;
    //if(BFS(sr,sc)) return true;
    else return false;
}
void Search(int step)
{
    if(step>=18)
    {
        if(judge()) 
        {
            ans++;
        }
        return;
    }
    int r=step/6;
    int c=step%6;
    matrix[r][c]=1;
    matrix[5-r][5-c]=0;
    Search(step+1);
    matrix[r][c]=0;
    matrix[5-r][5-c]=1;
    Search(step+1);
}
int main()
{
    memset(matrix,0,sizeof(matrix));
    Search(0);
    cout<<ans<<endl;
    ans=0;
    //状态压缩
    for(int i=0;i<(1<<18);i++)
    {
        for(int j=0;j<18;j++)
        {
            int r=j/6;
            int c=j%6;
            int temp=(i>>j) & 1;
            matrix[r][c]=temp;
            matrix[5-r][5-c]=1-temp;
        }
        if(judge())
        {
            ans++;
        }
    }
    cout<<ans<<endl;//2036/4 =509
    system("pause");
}

/*
#include<iostream>
#include<cstring>
using namespace std;
int matrix[7][7];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int kinds=0;
// todo 搜索剪切线
void DFS(int r,int c)
{
    if(r==0||c==0||r==6||c==6)
    {
        kinds++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(matrix[nr][nc]==1) continue;
        matrix[6-nr][6-nc]=1;//中心对称点
        matrix[nr][nc]=1;
        DFS(nr,nc);
        matrix[nr][nc]=0;
        matrix[6-nr][6-nc]=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(matrix,0,sizeof(matrix));
    matrix[3][3]=1;
    DFS(3,3);
    cout<<kinds<<endl;
    system("pause");//2036/4=509
}
*/

//TODO:由于是按格子边线剪成两块 所以以下矩阵DFS做法错误
// #include<iostream>
// #include<cstring>
// using namespace std;
// //6x6 18
// int matrix[6][6];
// void transposition(int (*a)[6])//转置
// {
//     int temp[6][6];
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             temp[i][j]=a[j][i];
//         }
//     }
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             a[i][j]=temp[i][j];
//         }
//     }
// }
// void rotation(int (*a)[6])
// {
//     transposition(a);
//     int rota[6][6];
//     for(int i=0;i<6;i++)//列
//     {
//         for(int j=0;j<6;j++)//行
//         {
//             rota[j][5-i]=a[j][i];
//         }
//     }
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             a[i][j]=rota[i][j];
//         }
//     }
// }
// void disp(int (*a)[6])
// {
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<"------"<<endl;
// }
// bool equal(int (*a)[6],int (*b)[6])
// {
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             if(a[i][j]+b[i][j]!=1) return false;
//         }
//     }
//     return true;
// }
// void test()
// {
//     int cnt=1;
//     for(int i=0;i<6;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             matrix[i][j]=cnt++;
//         }
//     }
//     disp(matrix);
//     rotation(matrix);
//     disp(matrix);
//     cout<<"----"<<endl;
//     rotation(matrix);
//     disp(matrix);
//     cout<<"----"<<endl;
//     rotation(matrix);
//     disp(matrix);
//     cout<<"----"<<endl;
//     rotation(matrix);
//     disp(matrix);
// }
// int kinds=0;
// void DFS(int depth,int cur)
// {
//     if(cur>18) return;
//     if(cur+36-depth<18) return;
//     if(depth>=36||cur==18)
//     {
//         if(cur==18)
//         {
//             int copy[6][6];
//             for(int i=0;i<6;i++)
//             {
//                 for(int j=0;j<6;j++)
//                 {
//                     copy[i][j]=matrix[i][j];
//                 }
//             }
//             //三次旋转观察是否出现相同矩阵
//             for(int i=0;i<3;i++)
//             {
//                 rotation(copy);
//                 if(equal(copy,matrix))
//                 {
//                     kinds++;
//                     disp(copy);
//                     cout<<"temp:"<<kinds<<endl;
//                     disp(matrix);
//                     break;
//                 }        
//             }
//         }
//         return;
//     }
//     int r=depth/6;
//     int c=depth%6;
//     matrix[r][c]=1;
//     DFS(depth+1,cur+1);
//     matrix[r][c]=0;
//     DFS(depth+1,cur);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     memset(matrix,0,sizeof(matrix));
//     DFS(0,0);
//     cout<<kinds<<endl;
//     system("pause");
// }