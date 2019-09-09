#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXLEN=5e5+50;
struct Palindromic_Tree
{
    int nxt[MAXLEN][26],fail[MAXLEN],len[MAXLEN],s[MAXLEN];
    int cnt[MAXLEN];// 结点表示的本质不同的回文串的个数(调用Count()后) 
    int num[MAXLEN];// 结点表示的最长回文串的最右端点为回文串结尾的回文串个数 
    int last,sz,n;
    int NewNode(int x)
    {
        memset(nxt[sz],0,sizeof(nxt[sz]));
        cnt[sz]=num[sz]=0,len[sz]=x;
        return sz++;
    }
    void Init()
    {
        sz=0;
        NewNode(0),NewNode(-1);
        last=n=0,s[0]=-1,fail[0]=1;
    }
    int GetFail(int u)
    {
        while(s[n-len[u]-1]!=s[n]) u=fail[u];
        return u;
    }
    void Add(int c)
    {
        //c-='a'
        s[++n]=c;
        int u=GetFail(last);
        if(!nxt[u][c])
        {
            int np=NewNode(len[u]+2);
            fail[np]=nxt[GetFail(fail[u])][c];
            num[np]=num[fail[np]]+1;
            nxt[u][c]=np;
        }
        last=nxt[u][c];
        cnt[last]++;
    }
    void Count()
    {
        for(int i=sz-1;~i;i--)
            cnt[fail[i]]+=cnt[i];
    }
}PT;
char str[MAXLEN];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    PT.Init();
    PT.Add(str[0]-'a');
    int k=PT.num[PT.last];
    printf("%d ",k);
    for(int i=1;i<len;i++)
    {
        PT.Add((str[i]-97+k)%26+97-'a');
        k=PT.num[PT.last];
        printf("%d ",k);
    }
    printf("\n");
    //system("pause");
    return 0;
}