#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define size 10
int n,m,q; //n:row  m:col  q:chessman
int board[size][size]; //0:空  1：普通棋子 2：炮
int ans;
vector<pair<int,int>> V1;
vector<pair<int,int>> V2;
bool noeat(int r,int c)
{
    int num;
    if(board[r][c]!=0) return false;
    for(int i=m-1;i>c;i--)
    {
        if(board[r][i]==2)
        {
            num=0;
            for(int j=i-1;j>c;j--)
            {
                if(board[r][j]!=0) num++;
            }
            if(num==1) return false;
        }
    }
    for(int i=0;i<c;i++)
    {
        if(board[r][i]==2)
        {
            num=0;
            for(int j=i+1;j<c;j++)
            {
                if(board[r][j]!=0) num++;
            }
            if(num==1) return false;
        }
    }
    for(int i=0;i<r;i++)
    {
        if(board[i][c]==2)
        {
            num=0;
            for(int j=i+1;j<r;j++)
            {
                if(board[j][c]!=0) num++;
            }
            if(num==1) return false;
        }
    }
    for(int i=n-1;i>r;i--)
    {
        if(board[i][c]==2)
        {
            num=0;
            for(int j=i-1;j>r;j--)
            {
                if(board[j][c]!=0) num++;
            }
            if(num==1) return false;
        }
    }
    return true;
}
void DFS(int pos,int temp_ans)
{
    if(pos==n*m)
    {
        if(temp_ans>ans) 
        {
            ans=temp_ans;
            //vector<pair<int,int>>::iterator it;
            //V1.clear();
            //for(it=V2.begin();it!=V2.end();it++) V1.push_back(make_pair(it->first,it->second));
        }
        return;
    }
    int nr=pos/n;
    int nc=pos%m;
    if(noeat(nr,nc))
    {
        board[nr][nc]=2;
        V2.push_back(make_pair(nr,nc));
        DFS(pos+1,temp_ans+1);
        board[nr][nc]=0;
        V2.pop_back();
    }
    DFS(pos+1,temp_ans);
}
int main()
{
    ios::sync_with_stdio(false);
    int row,col;
    while(cin>>n>>m>>q)
    {
        memset(board,0,sizeof(board));
        for(int i=0;i<q;i++)
        {
            cin>>row>>col;
            board[row][col]=1;
        }
        ans=-1;
        V2.clear();
        DFS(0,0);
        cout<<ans<<endl;
        //vector<pair<int,int>>::iterator it;
        //for(it=V1.begin();it!=V1.end();it++) cout<<it->first<<" "<<it->second<<endl;
    }
}