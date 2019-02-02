#include<iostream>
#include<stdlib.h> 
#include<cstring>
using namespace std;
int res[1000000]={0};
char str[1000000];
int main()
{
	int n,m;
	for(int i=1;i<1000000;i++)
	{
		itoa(i,str,10);
		if(strstr(str,"4")!=NULL||strstr(str,"62")!=NULL) res[i]++;
		res[i]+=res[i-1];
	}
	while(cin>>n>>m)
	{
		if(n==0&&m==0) continue;
		else
		{
		    int result;
			result=m-n+1-(res[m]-res[n-1]);
			cout<<result<<endl;
		} 
	} 
}
