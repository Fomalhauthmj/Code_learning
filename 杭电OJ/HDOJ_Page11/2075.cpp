#include<iostream>
using namespace std;
bool judge(long long num1,long long num2)
{
	if(num2>num1) return false;
	else
	{
		if(num1==num2) return true;
		else
		{
			if(num1%num2==0) return true;
			else return false;
		}
	}
}
int main()
{
	int t;
	while(cin>>t)
	{
		long long *p1=new long long[t];
		long long *p2=new long long[t];
		for(int i=0;i<t;i++) cin>>p1[i]>>p2[i];
		for(int i=0;i<t;i++)
		{
			if(judge(p1[i],p2[i])==true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
}
