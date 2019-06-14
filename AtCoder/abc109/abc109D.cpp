#include<iostream>
#include<vector>
using namespace std;
#define maxsize 505
struct node
{
    int y1;
    int x1;
    int y2;
    int x2;
    node(int i1,int i2,int i3,int i4)
    {
        y1=i1;x1=i2;y2=i3;x2=i4;
    }
};
vector<node> V;
int h,w;
int a[maxsize][maxsize];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>h>>w)
    {
        V.clear();
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<h-1;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(a[i][j]%2)
                {
                    a[i+1][j]++;
                    a[i][j]--;
                    V.push_back(node(i+1,j+1,i+2,j+1));
                }
            }
        }
        for(int i=0;i<w-1;i++)
        {
            if(a[h-1][i]%2)
            {
                a[h-1][i]--;
                a[h-1][i+1]++;
                V.push_back(node(h,i+1,h,i+2));
            }
        }
        cout<<V.size()<<endl;
        vector<node>::iterator it;
        for(it=V.begin();it!=V.end();it++)
        {
            cout<<it->y1<<" "<<it->x1<<" "<<it->y2<<" "<<it->x2<<endl;
        }
    }
}