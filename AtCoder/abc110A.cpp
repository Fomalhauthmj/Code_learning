#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        V.clear();
        V.push_back(a);V.push_back(b);V.push_back(c);
        sort(V.begin(),V.end(),greater<int>());
        cout<<V[0]*10+V[1]+V[2]<<endl;
    }
}