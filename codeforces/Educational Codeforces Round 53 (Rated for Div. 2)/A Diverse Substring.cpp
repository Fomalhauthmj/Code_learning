#include<iostream>
#include<map>
#include<string>
using namespace std;
bool judge(string n)
{
    map<char,int> M;
    for(int i=0;i<n.length();i++) M[n[i]]++;
    map<char,int>::iterator it;
    int max_time=n.length()/2;
    for(it=M.begin();it!=M.end();it++)
    {
        if(it->second>max_time) return false;
    }
    return true;
}
int main()
{
    string str;
    string sub;
    int len;
    while(cin>>len>>str)
    {
        bool finish=false;
        for(int i=2;i<=len;i++)
        {
            for(int j=0;j<=len-i;j++)
            {
                sub=str.substr(j,i);
                if(judge(sub))
                {
                    finish=true;
                    break;
                }
            }
            if(finish) break;
        }
        if(finish) cout<<"YES"<<endl<<sub<<endl;
        else cout<<"NO"<<endl;
    }
}