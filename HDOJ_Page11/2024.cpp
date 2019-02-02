#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
bool judge(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(i==0)
		{
			if(str[0]=='_'||isalpha(str[0])) 
			{
				continue;
			}
			else return false;
		}
		else
		{
			if(str[i]=='_'||isalnum(str[i]))
			{
				continue;
			}
			else return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while(cin>>n)
	{
		string *ptr=new string [n];
		string waste;
		getline(cin,waste);
		for(int i=0;i<n;i++)
		{
			getline(cin,ptr[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(judge(ptr[i])==true) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}
