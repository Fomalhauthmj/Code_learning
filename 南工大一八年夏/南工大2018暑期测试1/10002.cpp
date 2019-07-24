#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> V;
void solve(string str,string sub)
{
    int searchlen=sub.length();
    int minnum=1010;
    int temp;
    vector<int> T;
    for(int j=0;j<=str.length()-searchlen;j++)
    {
        temp=0;
        T.clear();
        string str_sub=str.substr(j,searchlen);
        for(int i=0;i<sub.length();i++)
        {
            if(sub[i]!=str_sub[i]) 
            {
                temp++;T.push_back(i+1);
            }
        }
        if(temp<minnum) 
        {
            minnum=temp;
            V.clear();
            vector<int>::iterator it;
            for(it=T.begin();it!=T.end();it++) V.push_back(*it);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    string str;
    string sub;
    int subsize;
    int strsize;
    while(t--)
    {
        cin>>subsize>>strsize>>sub>>str;
        if(str.find(sub)!=string::npos)
        {
            cout<<0<<endl;continue;
        }
        else
        {
            V.clear();
            solve(str,sub);
            cout<<V.size()<<endl;
            vector<int>::iterator it;
            for(it=V.begin();it!=V.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
}