#include<iostream>
#include<cstring>
using namespace std;
#define size 4
int n;
char city[size][size];
int ans;
bool legal(int r,int c)
{
    if(city[r][c]!='.') return false;
    if(r<0||r>=n) return false;
    if(c<0||c>=n) return false;
    return true;
}
bool noattack(int r,int c)
{
    for(int i=c-1;i>=0;i--)
    {
        if(city[r][i]=='.') continue;
        if(city[r][i]=='X') break;
        if(city[r][i]=='0') return false;
    }
    for(int i=c+1;i<n;i++)
    {
        if(city[r][i]=='.') continue;
        if(city[r][i]=='X') break;
        if(city[r][i]=='0') return false;
    }
    for(int i=r-1;i>=0;i--)
    {
        if(city[i][c]=='.') continue;
        if(city[i][c]=='X') break;
        if(city[i][c]=='0') return false;
    }
    for(int i=r+1;i<n;i++)
    {
        if(city[i][c]=='.') continue;
        if(city[i][c]=='X') break;
        if(city[i][c]=='0') return false;
    }
    return true;
}
void DFS(int pos,int temp_ans)
{
    if(pos==n*n)
    {
        if(temp_ans>ans) ans=temp_ans;
        return;
    }
    int nr=pos/n;
    int nc=pos%n;
    if(legal(nr,nc)&&noattack(nr,nc))
    {
        city[nr][nc]='0';
        DFS(pos+1,temp_ans+1);
        city[nr][nc]='.';
    }
    DFS(pos+1,temp_ans);
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>city[i][j];
            }
        }
        ans=-1;
        DFS(0,0);
        cout<<ans<<endl;
    }
}