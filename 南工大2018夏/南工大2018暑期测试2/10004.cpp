#include<iostream>
#include<algorithm>
using namespace std;
#define size 1010
int enemy[size];
long long all_edge;
struct node
{
    int pre;
    int num;
};
int n,m,k;
node city[size];
void init()
{
    for(int i=1;i<=n;i++) 
    {
        city[i].pre=i;
        city[i].num=1;
    }
}
int Find(int x)
{
    if(city[x].pre==x) return x;
    city[x].pre=Find(city[x].pre);
    return city[x].pre;
}
void Union(int u,int v)
{
    int preu=Find(u);
    int prev=Find(v);
    if(preu!=prev)
    {
        city[preu].pre=prev;
        city[prev].num+=city[preu].num;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)   
    {
        cin>>n>>m>>k;
        init();
        for(int i=0;i<k;i++) 
        {
            cin>>enemy[i];
        }
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            Union(u,v);
        }
        all_edge=0;
        int max_node_enemy=0;
        int cur_node_enemy;
        int no_enemy_node=n;
        for(int i=0;i<k;i++)
        {
            cur_node_enemy=city[Find(enemy[i])].num;
            //cout<<"now enemy city:"<<enemy[i]<<" "<<"its node: "<<cur_node_enemy<<endl; 
            max_node_enemy=max(max_node_enemy,cur_node_enemy);
            all_edge+=cur_node_enemy*(cur_node_enemy-1)/2;
            //cout<<"all_edge:"<<all_edge<<endl;
            no_enemy_node-=cur_node_enemy;
        }
        all_edge-=max_node_enemy*(max_node_enemy-1)/2;
        all_edge+=(max_node_enemy+no_enemy_node)*(max_node_enemy+no_enemy_node-1)/2;
        all_edge-=m;
        cout<<all_edge<<endl;
    }
}
//http://codeforces.com/problemset/problem/744/A
//http://codeforces.com/contest/744/submission/42202450
//换个思路吧

