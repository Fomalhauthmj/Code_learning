#include<iostream>
#include<string>
using namespace std;
int board[9][9];
bool finish;//为什么要设置一个结束位？
bool canPut(int x,int y,int num)
{
    for(int i=0;i<9;i++)
    {
        if(board[x][i]==num) return false;
        if(board[i][y]==num) return false;
    }//行 列 不重复
    int smallx1=x/3*3;
    int smally1=y/3*3;
    int smallx2=x/3*3+2;
    int smally2=y/3*3+2;
    for(int i=smallx1;i<=smallx2;i++)
    {
        for(int j=smally1;j<=smally2;j++)
        {
            if(board[i][j]==num) return false;
        }
    }//小区域无重复
    return true;
}
void DFS(int depth)
{
    if(depth>=81||finish) //结束
    {
        finish=1;//设置终止位
        return;
    }
    if(board[depth/9][depth%9]==0) //这里对每一个空位置进行深度搜索 而不遍历
    {
        for(int k=1;k<=9;k++)
        {
            if(canPut(depth/9,depth%9,k))
            {
                board[depth/9][depth%9]=k;
                DFS(depth+1);
                if(finish) return;  //如果已结束 终止
                board[depth/9][depth%9]=0;
            }
        }
    }
    else 
    {
        DFS(depth+1);
        if(finish) return;//如果已结束 终止
    }
}
int main()
{
    string line;
    while(1)
    {
        finish=0;
        for(int i=0;i<9;i++)
        {
            cin>>line;
            for(int j=0;j<9;j++)  board[i][j]=line[j]-'0';
        }
        DFS(0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}