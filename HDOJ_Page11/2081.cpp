#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		string result="6";
		cin>>str;
		string res=str.substr(str.length()-5);
		result.append(res);
		cout<<result<<endl;
	}
}
