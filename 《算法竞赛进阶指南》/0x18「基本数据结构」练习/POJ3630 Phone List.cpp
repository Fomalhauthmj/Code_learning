#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int N=1E5+50;
int trie[N][11],tot;
char ns[10010][11];
bool End[N];
void Insert(char *str)
{
    int p=1,len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int ch=str[i]-'0';
        if(!trie[p][ch]) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
    End[p]=true;
}
bool Find(char *str)
{
    int p=1,len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int ch=str[i]-'0';
        p=trie[p][ch];
        if(End[p]&&i!=len-1) 
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        bool flag=true;
        cin>>n;
        memset(trie,0,sizeof(trie));
        memset(End,0,sizeof(End));
        tot=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",ns[i]);
            Insert(ns[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(!Find(ns[i]))
            {
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    system("pause");
    return 0;
}