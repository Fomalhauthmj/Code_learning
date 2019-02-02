#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> M;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string level;
    while(cin>>n)
    {
        M.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>level;
            while(level[0]=='0')
            {
                level.erase(0,1);
            }
            M[level]++;
        }
        int res=0;
        map<string,int>::iterator it;
        for(it=M.begin();it!=M.end();it++)
        {
            if(it->second>res)
            {
                res=it->second;
            }
        }
        cout<<res<<endl;
    }
}