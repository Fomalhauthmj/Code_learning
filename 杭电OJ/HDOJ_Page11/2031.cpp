#include<iostream>
#include<math.h>
#include<cstring> 
using namespace std;
int main()
{
	int N,R;
	char ch[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(cin>>N>>R)
	{
		if(N<0) cout<<"-";
		int i=0;
		char result[32]={0};
		int temp=abs(N);
		while(temp/R!=0)
		{
			result[i++]=ch[temp%R];
			temp=temp/R;
		}
		result[i]=ch[temp%R];
		for(int i=strlen(result)-1;i>=0;i--) cout<<result[i];
		cout<<endl;
	}
} 
