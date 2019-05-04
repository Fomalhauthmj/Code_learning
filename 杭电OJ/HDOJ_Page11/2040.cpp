#include<iostream>
#include<cmath>
using namespace std;
bool judge(int num1,int num2)
{
	int sum=0;
	for(int i=1;i<num1;i++)
	{
		if(num1%i==0) sum+=i;
		else continue;
	}
	if(sum==num2)
	{
		int temp=0;
		for(int i=1;i<num2;i++)
		{
			if(num2%i==0) temp+=i;
			else continue;
		}
		if(temp==num1) return true;
		else return false;
	}
	else return false;
}
int main()
{
	int m;
	while(cin>>m)
	{
		int *ptr1=new int[m];
		int *ptr2=new int[m];
		for(int i=0;i<m;i++) cin>>ptr1[i]>>ptr2[i];
		for(int i=0;i<m;i++)
		{
			if(judge(ptr1[i],ptr2[i])==true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
