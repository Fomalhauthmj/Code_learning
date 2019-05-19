#include<iostream>
#include<string>
#include<map>
using namespace std;
#define size 200020
struct node
{
    string pre;
    int num;
    node():num(1),pre(" "){};
};
map<string,node> M;
int f;
string Find(string x)
{
    if(M[x].pre==x) return x;
    M[x].pre=Find(M[x].pre);
    return Find(M[x].pre);
}
int Union(string a,string b)
{
    string fa=Find(a);
    string fb=Find(b);
    if(fa!=fb)
    {
        M[fa].pre=fb;
        M[fb].num+=M[fa].num;//!:lazy只要更新根结点 
        return M[fb].num;
    }
    return M[fa].num;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    string a,b;
    while(cin>>t)
    {
        while(t--)
        {
            M.clear();
            cin>>f;
            for(int i=0;i<f;i++)
            {
                cin>>a>>b;
                if(M[a].pre==" ") M[a].pre=a;
                if(M[b].pre==" ") M[b].pre=b;
                cout<<Union(a,b)<<endl;
            }
        }
    }
}