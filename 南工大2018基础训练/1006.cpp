#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> V;
    int n,m;
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        V.clear();
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            V.push_back(num);
        }
        sort(V.begin(),V.end());
        vector<int>::iterator it;
        for(it=V.end()-1;it>V.end()-m;it--)
        {
            cout<<*it<<" ";
        }
        cout<<*it<<endl;
    }
}