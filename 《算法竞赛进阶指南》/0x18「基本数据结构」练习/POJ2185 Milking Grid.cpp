#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define ull unsigned long long
#define P 131
const int R=1E4+50;
const int C=80;
char s[R][C];
ull Hash[R];
int nxt[R];
int work(int len)
{
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<len)
        if(j==-1||Hash[i]==Hash[j]) nxt[++i]=++j;
        else j=nxt[j];
    return len-nxt[len]; 
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++) scanf("%s",s[i]);
    memset(Hash,0,sizeof(Hash));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            Hash[i]=Hash[i]*P+s[i][j];
    int height=work(r);
    memset(Hash,0,sizeof(Hash));
    for(int i=0;i<c;i++)
        for(int j=0;j<r;j++)
            Hash[i]=Hash[i]*P+s[j][i];
    int width=work(c);
    //cout<<height<<" "<<width<<endl;
    cout<<height*width<<endl;
    //system("pause");
    return 0;
}