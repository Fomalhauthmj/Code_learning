#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define ull unsigned long long
#define N 3030
#define A 975591799 
#define B 1401170116
#define P 131
#define Q 13331
vector<int> V[N];
stack<int> s;
ull Hash(int root)
{
    if(!V[root].size()) return 1;
    vector<ull> t;
    for(int i=0;i<V[root].size();i++)
        t.push_back(Hash(V[root][i]));
    sort(t.begin(),t.end());
    ull ret=A;
    for(int i=0;i<t.size();i++) ret=((ret*P)^t[i])%Q;
    return ret*B%Q;
}
ull Solve(string str)
{
    for(int i=1;i<N;i++) V[i].clear();
    int len=str.length();
    int cnt=0;
    while(!s.empty()) s.pop();
    s.push(++cnt);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0')
        {
            V[s.top()].push_back(++cnt);
            s.push(cnt);
        }
        else s.pop();
    }
    return Hash(1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string a,b;
    while(n--)
    {
        cin>>a>>b;
        if(Solve(a)==Solve(b)) cout<<"same"<<endl;
        else cout<<"different"<<endl;
    }
    //system("pause");
    return 0;
}