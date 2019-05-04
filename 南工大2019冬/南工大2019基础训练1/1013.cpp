#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;
char chs[8]={'A','A','2','2','3','3','4','4'};
bool vis[8];
set<string> ans;
string temp;
bool judge(string str)
{
    vector<int> pos[4];
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='A') pos[0].push_back(i);
        else pos[str[i]-'1'].push_back(i);
    }
    for(int i=0;i<4;i++)
    {
        if(abs(pos[i][0]-pos[i][1])!=i+2) return false;
    }
    return true;
}
void DFS(int depth)
{
    if(depth>=8)
    {
        if(judge(temp))
        {
            ans.insert(temp);
        }
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            temp.append(1,chs[i]);
            DFS(depth+1);
            vis[i]=0;
            temp.erase(temp.length()-1,1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis,0,sizeof(vis));
    temp="";
    DFS(0);
    for(auto ele:ans)
    {
        cout<<ele<<endl;
    }
    system("pause");
    //"2342A3A4"
//4A3A2432
}