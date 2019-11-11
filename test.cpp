#include<bits/stdc++.h>
using namespace std;
int vis[100];
int pre[100];
vector<int> E[10];
void DFS(int x, int fa)
{
    vis[x] = 1, pre[x] = fa;
    //cout<<"cur"<<x<<" "<<fa<<endl;
    for (int y : E[x])
    {
        //cout<<"nxt"<<x<<" "<<y<<endl;
        if (y == fa)
            continue;
        if (!vis[y])
            DFS(y, x);
        else if (vis[y] == 1)
        {
            int t=x;
            do
            {
                cout<<t<<" ";
                t=pre[t];
            } while (t!=y);
            cout<<y<<endl;
        }
    }
    //cout<<"end"<<x<<endl;
    vis[x] = 2;
}
int main()
{
    E[1].push_back(2);
    E[2].push_back(1);
    E[2].push_back(3);
    E[3].push_back(2);
    E[1].push_back(3);
    E[3].push_back(1);
    for(int i=1;i<=4;i++)
        if(!vis[i]) DFS(i,0);
    system("pause");
    return 0;
}