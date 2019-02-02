#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> x;
vector<int> y;
int X,Y;
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    int number;
    while(cin>>n>>m>>X>>Y)
    {
        x.clear();y.clear();
        for(int i=0;i<n;i++)
        {
            cin>>number;x.push_back(number);
        }
        for(int i=0;i<m;i++)
        {
            cin>>number;y.push_back(number);
        }
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end());
        bool flag=0;
        //cout<<x[0]<<endl;
        //cout<<y[0]<<endl;
        for(int i=X+1;i<=Y;i++)
        {
            if(i>x[0]&&i<=y[0])
            {
                flag=1;
                break;
            }
        }
        if(flag) cout<<"No War"<<endl;
        else cout<<"War"<<endl;
    }
}