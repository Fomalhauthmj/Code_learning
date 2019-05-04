#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while(cin>>str)
	{
		char maxpos=0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]>str[maxpos]) maxpos=i;
			else continue;
		}
		for(int i=0;i<str.length();)
		{
			if(str[i]==str[maxpos]) 
			{
				str.insert(i+1,"(max)");
				i+=6;
			}
			else i++;
		}
		cout<<str<<endl;
	}
}
