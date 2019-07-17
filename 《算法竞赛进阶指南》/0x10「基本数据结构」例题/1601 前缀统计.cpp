/*
 * File Created: Wednesday, 17th July 2019 10:43:55 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 6:21:23 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N=1E6+50;
int trie[N][26];
char str[N];
int End[N];
int tot=1;
void Insert(char *str)
{
    int len=strlen(str),p=1;
    for(int k=0;k<len;k++)
    {
        int ch=str[k]-'a';
        if(!trie[p][ch]) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
    End[p]++;
}
int Search(char *str)
{
    int ans=0;
    int len=strlen(str),p=1;
    for(int k=0;k<len;k++)
    {
        p=trie[p][str[k]-'a'];
        ans+=End[p];
        if(!p) break;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%s",str),Insert(str);
    for(int i=0;i<m;i++)
    {
        scanf("%s",str);
        cout<<Search(str)<<endl;
    }
    system("pause");
    return 0;
}