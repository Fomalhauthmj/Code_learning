#include<iostream>
#include<cstring>
using namespace std;
#define size 105
char map[size][size];
bool row[size];
bool col[size];
//TODO:
int main()
{
    ios::sync_with_stdio(false);
    int h,w;
    while(cin>>h>>w)
    {
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>map[i][j];
            }
        }
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j]=='#')
                {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<h;i++)
        {
            if(row[i])
            {
                for(int j=0;j<w;j++)
                {
                    if(col[j])
                    {
                       cout<<map[i][j];
                    }
                }
                cout<<endl;
            }
        }
    }
}