#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXLEN=105;
int nxt[MAXLEN];
char str[MAXLEN];
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b))
	{
	scanf("%s",str+1);
	nxt[1]=0;
	int n=strlen(str+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(j>0&&str[i]!=str[i+1]) j=nxt[j];
		if(str[i]==str[j+1]) j++;
		nxt[i]=j;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int p=i/(i-nxt[i])*i;
		p++;
		int temp=1;
		while(str[p]==str[temp])
		{
			p++,temp++;
			if(temp>i) temp=1;
		}
		p--;
		cout<<i-nxt[i]<<" "<<(i/(i-nxt[i]))<<" "<<i%(i-nxt[i])<<endl;
		cout<<i<<" "<<p<<endl;
		ans=max(ans,a*p-b*i);
	}
	cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}
/*
5 3
0201
2 1
2121
*/
