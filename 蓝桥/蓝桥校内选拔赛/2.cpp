#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define N 1010
string strs[N];
string text;
int n;
int chars[N][27];
int chars_for_text[27];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>text>>n)
    {
        memset(chars,0,sizeof(chars));
        for(int i=1;i<=n;i++)
        {
            cin>>strs[i];
            int len=strs[i].length();
            for(int j=0;j<len;j++)
            {
                chars[i][strs[i][j]-'a']++;
            }
        }
        long long ans=0;
        int len=text.length();
        bool flag;
        for(int i=0;i<=len-8;i++)
        {
            memset(chars_for_text,0,sizeof(chars_for_text));
            for(int j=i;j<i+8;j++)
            {
                chars_for_text[text[j]-'a']++;
            }
            for(int j=1;j<=n;j++)
            {
                flag=true;
                for(int k=0;k<26;k++)
                {
                    if(chars_for_text[k]!=chars[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(!flag) continue;
                else ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}