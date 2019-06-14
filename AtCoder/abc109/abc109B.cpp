#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> M;
int n;
string prestr;
string str;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        M.clear();
        cin>>prestr;
        M[prestr]++;
        int flag=0;
        for(int i=1;i<n;i++)
        {
            cin>>str;
            if(str[0]!=prestr[prestr.length()-1]) flag=1;
            M[str]++;
            if(M[str]!=1) flag=1;
            prestr=str;
        }
        if(flag==1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}