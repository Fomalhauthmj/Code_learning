#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXLEN=1e5+50;
char T[MAXLEN],S[MAXLEN];
int nxt[MAXLEN][2],f[MAXLEN];
void GetNextT(int n)
{
    nxt[1][0] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
    while (j > 0 && T[i] != T[j+1]) j = nxt[j][0];
    if (T[i] == T[j+1]) j++;
    nxt[i][0] = j;
    }
}
void GetNextS(int n)
{
    nxt[1][1]= 0;
    for (int i = 2, j = 0; i <= n; i++) {
    while (j > 0 && S[i] != S[j+1]) j = nxt[j][1];
    if (S[i] == S[j+1]) j++;
    nxt[i][1] = j;
    }
}
bool KMP_inT(int n,int m)
{
    for (int i = 1, j = 0; i <= m; i++) {
    while (j > 0 && (j == n || T[i] != S[j+1])) j = nxt[j][1];
    if (T[i] == S[j+1]) j++;
    f[i] = j;
    if (f[i] == n)return true;
    }
    return false;
}
bool KMP_inS(int n,int m)
{
    for (int i = 1, j = 0; i <= m; i++) {
    while (j > 0 && (j == n || S[i] != T[j+1])) j = nxt[j][0];
    if (S[i] == T[j+1]) j++;
    f[i] = j;
    if (f[i] == n)return true;
    }
    return false;
}
int main()
{
    scanf("%s",T+1);
    int q,tlen=strlen(T+1);
    scanf("%d",&q);
    GetNextT(tlen);
    while(q--)
    {
        scanf("%s",S+1);
        int slen=strlen(S+1);
        if(tlen>slen)
        {
            GetNextS(slen);
            if(KMP_inT(slen,tlen))
                printf("my child!\n");
            else printf("oh, child!\n");
        }
        else if(tlen<slen)
        {
            if(KMP_inS(tlen,slen))
                printf("my teacher!\n");
            else printf("senior!\n");
        }
        else if(tlen==slen)
        {
            if(strcmp(S+1,T+1)==0)
                printf("jntm!\n");
            else printf("friend!\n");
        }
    }
    system("pause");
    return 0;
}