#include<iostream>
#include<string>
using namespace std;
bool judge(string str)
{
	if(str.length()<8||str.length()>16) return false;
	int flag=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='a'&&str[i]<='z') 
		{
			flag++;
			break; 
		} 
	}
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			flag++;
			break;
		}
	}
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			flag++;
			break;
		}
	}
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='~'||str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^')
		{
			flag++;
			break;

		}
	}
	if(flag>=3) return true;
	else return false;
}
int main()
{
	int n;
	while(cin>>n)
	{
		string *ptr=new string [n];
		for(int i=0;i<n;i++) cin>>ptr[i];
		for(int i=0;i<n;i++)
		{
			if(judge(ptr[i])==true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
