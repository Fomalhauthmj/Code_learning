#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,int> M;
int n,k;
string str;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k>>str)
    {
        M.clear();
        for(int i=0;i<n;i++)
        {
            M[str[i]]++;
        }
        int minnum=1e6;
        for(int it=0;it<k;it++)
        {
            if(M['A'+it]<minnum) minnum=M['A'+it];
        }
        cout<<k*minnum<<endl;
    }
}