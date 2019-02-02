#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,s;
	while(cin>>str&&str!="#")
	{
		cin>>s;
		int sum=0;
		int pos=0;
		while(str.find(s,pos)!=string::npos)
		{
			pos=str.find(s,pos)+s.length();
			sum++;
		}
		cout<<sum<<endl;
	}
	
} 
