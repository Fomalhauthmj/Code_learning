#include<iostream>
#include<string>
using namespace std;
bool judge(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!=str[str.length()-1-i]) return false;
		else continue;
	}
	return true;
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
			if(judge(ptr[i])==false) cout<<"no"<<endl;
			else cout<<"yes"<<endl;
 		}
	}
} 
