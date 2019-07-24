//1 2 5 6 8 9 0
//1 2 5 9 8 6 0

//3 4 7 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1000;i<=9999;i++)
    {
        if(i%10==0) continue;
        string s1=to_string(i);
        if(s1.find('3')!=string::npos) continue;
        if(s1.find('4')!=string::npos) continue;
        if(s1.find('7')!=string::npos) continue;
        for(int k=0;k<s1.length();k++)
        {
            if(s1[k]=='6') s1[k]='9';
            else if(s1[k]=='9') s1[k]='6';
        }
        reverse(s1.begin(),s1.end());
        int n1=stoi(s1);
        if(i-n1<200||i-n1>300) continue;
        for(int j=1000;j<=9999;j++)
        {
            if(j%10==0) continue;
            string s2=to_string(j);
            if(s2.find('3')!=string::npos) continue;
            if(s2.find('4')!=string::npos) continue;
            if(s2.find('7')!=string::npos) continue;
            for(int k=0;k<s2.length();k++)
            {
                if(s2[k]=='6') s2[k]='9';
                else if(s2[k]=='9') s2[k]='6';
            }
            reverse(s2.begin(),s2.end());
            int n2=stoi(s2);
            if(n2-j<800||n2-j>900) continue;
            if(n1+n2-i-j==558)
            {
                cout<<i<<" "<<j<<endl;
            }
        }   
    }
    system("pause");//9088
}