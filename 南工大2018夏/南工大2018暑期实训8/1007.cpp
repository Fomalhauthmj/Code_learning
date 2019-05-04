//八皇后问题 ans=92

#include<iostream>
using namespace std;
int ans[11];
int N;
int x[15];
bool canPut(int row,int col)
{
    //x[1]-x[col-1]已确定
    for(int i=1;i<col;i++)
    {
        if(x[i]==row||abs(row-x[i])==abs(col-i)) return false;  //根据斜率剪枝对角线
    }
    return true;
}
void DFS(int depth,int n)
{
    if(depth>n) 
    {
        ans[n]++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(canPut(i,depth)) //i行dep列 可置
        {
            x[depth]=i;//第i行放在第depth列
            DFS(depth+1,n);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=10;i++)
    {
        DFS(1,i);
    }
    while(cin>>N)
    {
        if(N==0) break;
        cout<<ans[N]<<endl;
    }
    return 0;
}