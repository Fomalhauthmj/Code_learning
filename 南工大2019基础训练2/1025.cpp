#include<iostream>
#include<cstring>
using namespace std;
int matrix[7][7];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int kinds=0;
//TODO:搜索剪切线
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
//TODO:由于是按格子边线剪成两块 所以以下DFS做法错误
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