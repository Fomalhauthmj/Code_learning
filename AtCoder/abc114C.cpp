#include<iostream>
#include<string>
#include<set>
using namespace std;
int ele[3]={3,5,7};
int temp_ans;
int cur_value;
int n;
bool judge(int val)
{
    if(val>n) return false;
    set<char> S;
    string str=to_string(val);
    for(auto ele:str)
    {
        S.insert(ele);
    }
    if(S.size()==3) return true;
    else return false;
}
void DFS(int len,int cur_len)
{
    if(cur_len==len)
    {
        if(judge(cur_value))
        {
            //cout<<cur_value<<endl;
            temp_ans++;
        }
        return;
    }
    for(int i=0;i<3;i++)
    {
        cur_value=cur_value*10+ele[i];
        DFS(len,cur_len+1);
        cur_value=(cur_value-ele[i])/10;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str)
    {
        int len=str.length();
        if(len<=2)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        n=stoi(str);
        for(int i=3;i<=len;i++)
        {
            temp_ans=0;
            cur_value=0;
            DFS(i,0);
            ans+=temp_ans;
        }
        cout<<ans<<endl;
    }
}