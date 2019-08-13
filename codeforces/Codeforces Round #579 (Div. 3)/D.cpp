#include<iostream>
#include<string>
using namespace std;
//二分
string s,t;
bool Judge(int mid)
{
    int len=s.length();
    for(int i=0;i+mid-1<=len-1;i++)
    {
        int pos=0;
        for(int j=0;j<=i-1;j++)
        {
            if(s[j]==t[pos]) pos++;
        }
        for(int j=i+mid;j<=len-1;j++)
        {
            if(s[j]==t[pos]) pos++;
        }
        if(pos>=t.length()) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    int left=0;
    int right=s.length()-t.length();
    int mid;
    while(left<right)
    {
        mid=(left+right+1)>>1;
        //cout<<"cur :"<<mid<<endl;
        if(Judge(mid))
            left=mid;
        else right=mid-1;
    }
    cout<<left<<endl;
    //system("pause");
    return 0;
}