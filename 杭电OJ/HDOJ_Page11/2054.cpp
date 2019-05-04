#include<iostream>
using namespace std;
void deal(string &str)
{
	if(str.find('.')!=string::npos)
	{
		int i=str.length()-1;
		for(;str[i]=='0';i--)
		{
			str.erase(i,1);
		}
		if(str[i]=='.');
		str.erase(i,1);
	}
}
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		deal(a);
		deal(b);
		if(a==b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
