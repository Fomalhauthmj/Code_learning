/*
 * File Created: Wednesday, 17th July 2019 10:44:10 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 6:34:36 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
using namespace std;
const int N=1E5+50;
int n;
int trie[32*N][2];
int tot=1;
void Insert(int number)
{
    int p=1;
    for(int i=31;i>=0;i--)
    {
        int now=(number>>i)&1;
        if(!trie[p][now]) trie[p][now]=++tot;
        p=trie[p][now];
    }
}
int Find(int number)
{
    int p=1;
    int ret=0;
    for(int i=31;i>=0;i--)
    {
        int now=(number>>i)&1;
        if(!trie[p][now^1]) p=trie[p][now],ret<<=1;
        else p=trie[p][now^1],ret=(ret<<1)+1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ans=0;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        ans=max(ans,Find(num));
        Insert(num);
    }
    ans=max(ans,Find(num));
    cout<<ans<<endl;
    system("pause");
    return 0;
}