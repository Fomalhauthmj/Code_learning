#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    vector<int> V;
    while(cin>>t)
    {
        while(t--)
        {
            V.clear();
            int n;
            cin>>n;
            int num;
            for(int i=0;i<n;i++)
            {
                cin>>num;
                V.push_back(num);
            }
            sort(V.begin(),V.end());
            vector<int>::iterator it;
            for(it=V.begin();it<V.end()-1;it++)
            {
                cout<<*it<<" ";
            }
            cout<<*it<<endl;
        }
    }

}