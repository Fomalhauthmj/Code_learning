#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string a,b;
string Solve(string str)
{
    vector<string> son;
    string ret="";
    int len=str.length();
    int cnt=0,pre=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0') cnt++;
        else cnt--;
        if(!cnt)
        {
            if(i-1>pre+1)
                son.push_back("0"+Solve(str.substr(pre+1,i-pre-1))+"1");
            else son.push_back("01");
            pre=i+1;
        }
    }
    sort(son.begin(),son.end());
    len=son.size();
    for(int i=0;i<len;i++) ret+=son[i];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<((Solve(a)==Solve(b))?"same":"different")<<endl;
    }
    system("pause");
    return 0;
}