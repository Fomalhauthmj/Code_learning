#include<iostream>
#include<vector>
using namespace std;
#define max 4
int n;
int m[4][4]={0};
vector<pair<int,int>> V;
void deletepoint(int x,int y)
{
    vector<pair<int,int>>::iterator it;
    for(it=V.begin();it!=V.end();it++)
    {
        if(it->first==x&&it->second==y)
        {
            V.erase(it);
            break;
        }
    }
}
int effect(int x,int y)
{
    int sum=0;
    int up=x-1;
    int down=x+1;
    int left=y-1;
    int right=y+1;
    for(int i=up;i>=0;i--)
    {
        if(m[i][y]==0) sum++;
        if(m[i][y]==1) break;
        if(m[i][y]==2) continue;
    }
    for(int i=down;i<n;i++)
    {
        if(m[i][y]==0) sum++;
        if(m[i][y]==1) break;
        if(m[i][y]==2) continue;
    }
    for(int i=left;i>=0;i--)
    {
        if(m[x][i]==0) sum++;
        if(m[x][i]==1) break;
        if(m[x][i]==2) continue;
    }
    for(int i=right;i<n;i++)
    {
        if(m[x][i]==0) sum++;
        if(m[x][i]==1) break;
        if(m[x][i]==2) continue;
    }
    return sum;
}
void update(int x,int y)
{
    m[x][y]=1;
    int up=x-1;
    int down=x+1;
    int left=y-1;
    int right=y+1;
    for(int i=up;i>=0;i--)
    {
        if(m[i][y]==0||m[i][y]==2) 
        {
            m[i][y]=2;
            deletepoint(i,y);
        }
        if(m[i][y]==1) break;
    }
    for(int i=down;i<n;i++)
    {
        if(m[i][y]==0||m[i][y]==2) 
        {
            m[i][y]=2;
            deletepoint(i,y);
        }
        if(m[i][y]==1) break;
    }
    for(int i=left;i>=0;i--)
    {
        if(m[x][i]==0||m[x][i]==2) 
        {
            m[x][i]=2;
            deletepoint(x,i);
        }
        if(m[x][i]==1) break;
    }
    for(int i=right;i<n;i++)
    {
        if(m[x][i]==0||m[x][i]==2) 
        {
            m[x][i]=2;
            deletepoint(x,i);
        }
        if(m[x][i]==1) break;
    }
}
int result()
{
    int res=0;
    while(V.size()!=0)
    {
        res++;
        int mineffect=16;
        int minx=4,miny=4;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[i][j]!=0) continue;
                else
                {
                    int temp=effect(i,j);
                    if(temp<mineffect)
                    {
                        mineffect=temp;minx=i;miny=j;
                    }
                }
            }
        }
        if(minx!=4&&miny!=4)
        {
            update(minx,miny);
        }
        else break;
    } 
    return res-1;
}
int main()
{
    char ch;
    while(cin>>n)
    {
        if(n<=0) break;
        V.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch;
                if(ch=='.') 
                {
                    m[i][j]=0;
                    V.push_back(make_pair(i,j));
                }
                if(ch=='X') m[i][j]=1; 
            }
        }
        int res=result();
        if(res<=0) cout<<0<<endl;
        else cout<<res<<endl;
    }
}