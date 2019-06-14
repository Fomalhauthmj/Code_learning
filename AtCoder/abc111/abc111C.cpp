#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
map<int,int> odd;
map<int,int> even;
struct node
{
    int num;
    int per;
    node(int i1,int i2)
    {
        num=i1;
        per=i2;
    }
};
vector<node> Vo;
vector<node> Ve;
bool cmp(node &n1,node &n2)
{
    return n1.per>n2.per;
}
int n;
int v[N];
int main()
{   
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        odd.clear();
        even.clear();
        Vo.clear();
        Ve.clear();
        for(int i=1;i<=n;i++) 
        {
            cin>>v[i];
            if(i%2==0) even[v[i]]++;
            else odd[v[i]]++;
        }
        map<int,int>::iterator it;
        for(it=odd.begin();it!=odd.end();it++)
        {
            Vo.push_back(node(it->first,it->second));
        }
        for(it=even.begin();it!=even.end();it++)
        {
            Ve.push_back(node(it->first,it->second));
        }
        Ve.push_back(node(1e6,0));//处理4:1 1 1 1 在各组最后添加一个溢出位
        Vo.push_back(node(1e6,0));
        sort(Vo.begin(),Vo.end(),cmp);
        sort(Ve.begin(),Ve.end(),cmp);
        //cout<<"odd:"<<Vo[0].num<<" "<<Vo[0].per<<endl;
        //cout<<"even:"<<Ve[0].num<<" "<<Ve[0].per<<endl;
        if(Vo[0].num==Ve[0].num)
        {
            cout<<n-max(Vo[1].per+Ve[0].per,Vo[0].per+Ve[1].per);
        }
        else cout<<n-Ve[0].per-Vo[0].per<<endl;
    }
}