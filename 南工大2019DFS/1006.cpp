#include<iostream>
#include<cstring>
using namespace std;
int matrix[9][9];
int casenum;
bool finish;
bool legal(int r,int c,int val)
{
    for(int i=0;i<9;i++)//每一行 每一列
    {
        if(matrix[r][i]==val||matrix[i][c]==val) return false;
    }
    for(int i=r/3*3;i<r/3*3+3;i++)
    {
        for(int j=c/3*3;j<c/3*3+3;j++)
        {
            if(matrix[i][j]==val) return false;
        }
    }
    return true;
}
void DFS(int k)
{
    if(k>80||finish) //必须设置结束位
    {
        finish=1;
        return;
    }
    int r=k/9;
    int c=k%9;
    if(matrix[r][c]==0)
    {
        for(int i=1;i<=9;i++)
        {
            if(legal(r,c,i))
            {
                matrix[r][c]=i;
                DFS(k+1);
                if(finish) return;
                matrix[r][c]=0;
            }
        }
    }
    else 
    {
        DFS(k+1);
        if(finish) return;
    }
}
void disp()
{
    if(casenum!=1) cout<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j!=8) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j]<<endl;
        }
    }
}
int main()
{
    casenum=1;
    char ch;
    while(cin>>ch)
    {
        memset(matrix,0,sizeof(matrix));
        finish=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(i!=0||j!=0)  cin>>ch;//i==0&&j==0 排除
                if(ch!='?')
                {
                    matrix[i][j]=ch-'0';
                }
            }
        }
        DFS(0);
        disp();
        casenum++;
    }
}