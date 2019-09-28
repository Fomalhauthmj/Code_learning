#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
const int MAXLEN=1e7+500;
char ori[MAXLEN],temp[MAXLEN],str[MAXLEN];
ll a,b;
int nxt[MAXLEN];
int main()
{
    scanf("%lld%lld",&a,&b);
    scanf("%s",temp);
    int len=strlen(temp);
    for(int i=0;i<len;i++)
    {
        if(temp[i]=='.')
        {
            strcpy(ori+1,temp+i+1);
            break;
        }
    }
    len=strlen(ori+1);
    for(int i=1;i<=len;i++)
        str[i]=ori[len+1-i];
    //cout<<str+1<<endl;
    nxt[1]=0;
    for(int i=2,j=0;i<=len;i++)
    {
        while(j>0&&str[i]!=str[j+1]) j=nxt[j];
        if(str[i]==str[j+1]) j++;
        nxt[i]=j;
    }
    ll ans=-1e18;
    for(int p=1;p<=len;p++)
    {
        int l = p - nxt[p];
        //cout<<l<<" "<<p<<endl;
        ans=max(ans,a*p-b*l);
    }
    printf("%lld\n",ans);
    //system("pause");
    return 0;
}
/*
5 3
1.1020
9
2 1
12.1212
6
*/