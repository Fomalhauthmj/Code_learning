
#include<iostream>
#include<set>
using namespace std;
set<int> S;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    int num;
    while(cin>>n>>m)
    {
        S.clear();
        for(int i=0;i<n+m;i++)
        {
            cin>>num;
            S.insert(num);
        }
        set<int>::iterator it;
        int num=S.size();
        int i=0;
        for(it=S.begin();it!=S.end();it++)
        {
            cout<<*it;
            i++;
            if(i==num) cout<<endl;
            else cout<<" ";
        }
    }
}