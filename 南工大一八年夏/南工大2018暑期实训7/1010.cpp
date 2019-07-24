#include<iostream>
using namespace std;
#define size 50050
int n,m;
int ans;
struct node
{
    int parent;
    int column;//到根结点的距离
};
node a[size];
void init()
{
    for(int i=1;i<=n;i++) 
    {
        a[i].parent=i;
        a[i].column=0;
    }
}
int Find(int x)
{
    if(a[x].parent==x) return x; 
    int pa=a[x].parent;
    a[x].parent=Find(a[x].parent);
    a[x].column+=a[pa].column;//递归更新到根节点的距离
    return a[x].parent;
}
void Union(int A,int B,int X)
{
    int pa=Find(A);
    int pb=Find(B);
    if(pa!=pb)
    {
        a[pb].parent=pa;
        a[pb].column=a[A].column+X-a[B].column;//向量的计算？分段计算√
    }
    else
    {
        if(a[B].column-a[A].column!=X) ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int A,B,X;
    while(cin>>n>>m)
    //while(cin>>n>>m&&!cin.eof())
    {
        ans=0;
        init();
        for(int i=0;i<m;i++)
        {
            cin>>A>>B>>X;
            Union(A,B,X);
        }
        cout<<ans<<endl;
    }
}
// #include<stdio.h>
// using namespace std;
// #define size 50050
// int n,m;
// int ans;
// struct node
// {
//     int parent;
//     int column;
// };
// node a[size];
// void init()
// {
//     for(int i=1;i<=n;i++) 
//     {
//         a[i].parent=i;
//         a[i].column=0;
//     }
// }
// int Find(int x)
// {
//     if(a[x].parent==x) return x; 
//     int pa=a[x].parent;
//     a[x].parent=Find(a[x].parent);
//     a[x].column+=a[pa].column;//递归更新到根节点的距离
//     return a[x].parent;
// }
// void Union(int A,int B,int X)
// {
//     int pa=Find(A);
//     int pb=Find(B);
//     if(pa!=pb)
//     {
//         a[pb].parent=pa;
//         a[pb].column=a[A].column+X-a[B].column;//向量的计算？
//     }
//     else
//     {
//         if(a[B].column-a[A].column!=X) ans++;
//     }
// }
// int main()
// {
//     int A,B,X;
//     while(scanf("%d%d",&n,&m)!=EOF)
//     {
//         ans=0;
//         init();
//         for(int i=0;i<m;i++)
//         {
//             scanf("%d%d%d",&A,&B,&X);
//             Union(A,B,X);
//         }
//         printf("%d\n",ans);
//     }
// }