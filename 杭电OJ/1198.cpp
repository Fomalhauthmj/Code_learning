// #include<iostream>
// #include<string>
// #include<cstring>
// using namespace std;
// #define max 550
// int m,n;
// int type[11][4]={
//     {1,0,0,1},
//     {1,1,0,0},
//     {0,0,1,1},
//     {0,1,1,0},
//     {1,0,1,0},
//     {0,1,0,1},
//     {1,1,0,1},
//     {1,0,1,1},
//     {0,1,1,1},
//     {1,1,1,0},
//     {1,1,1,1}
// };
// char map[max][max];
// int pre[max*max];
// int answer;
// void init(int m,int n)
// {
//     for(int i=0;i<m*n;i++)
//     {
//         pre[i]=i;
//     }
//     answer=m*n;
// }
// int find(int x)
// {
//     if(pre[x]==x) return x;
//     return pre[x]=find(pre[x]);
// }
// void myunion(int pos1x,int pos1y,int pos2x,int pos2y,int dir)
// {
//     int flag=0;
//     if(pos2x<0||pos1x>=m||pos2y<0||pos2y>=n)  return;
//     int typepos1=map[pos1x][pos1y]-'A';
//     int typepos2=map[pos2x][pos2y]-'A';
//     if(dir==1)
//     {
//         if(type[typepos1][1]&&type[typepos2][3]) flag=1;
//     }
//     if(dir==2)
//     {
//         if(type[typepos1][2]&&type[typepos2][0]) flag=1;
//     }
//     if(flag==1)
//     {
//         int fatherpos1=find(pos1x*n+pos1y);
//         int fatherpos2=find(pos2x*n+pos2y);
//         if(fatherpos1!=fatherpos2)
//         {
//             pre[fatherpos2]=fatherpos1;
//             answer--;
//         }
//     }
// }

// int main()
// {
//     while(cin>>m>>n)
//     {
//         if(m<=0||n<=0) break;
//         else
//         {
//             memset(map,0,sizeof(map));
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     cin>>map[i][j];
//                 }
//             }
//             init(m,n);
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     myunion(i,j,i+1,j,2);
//                     myunion(i,j,i,j+1,1);
//                 }
//             }
//             cout<<answer<<endl;
//         }
//     }

// }
