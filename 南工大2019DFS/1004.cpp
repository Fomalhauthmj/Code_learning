#include<iostream>
#include<string>
#include<set>
#include<cstring>
using namespace std;
set<char> S[26];
bool vis[26];
bool DFS(char start)
{
    if(start=='m') return true;
    for(auto ele:S[start-'a'])
    {
        if(vis[ele-'a']) continue;
        vis[ele-'a']=1;
        if(DFS(ele)) return true;
        vis[ele-'a']=0;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str)
    {
        for(int i=0;i<26;i++) S[i].clear();
        S[str[0]-'a'].insert(str[str.length()-1]);
        while(cin>>str)
        {
            if(str=="0") break;
            S[str[0]-'a'].insert(str[str.length()-1]);
        }
        memset(vis,0,sizeof(vis));
        vis['b'-'a']=1;
        if(DFS('b')) cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
}