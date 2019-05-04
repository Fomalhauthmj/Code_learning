#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while(getline(cin,str))
	{
		for(int i=0;i<str.length();i++)
		{
			if(i==0) str[i]-=32;
			else
			{
				if(str[i-1]==' ') str[i]-=32;
			}
		}
		cout<<str<<endl;
	}
}
