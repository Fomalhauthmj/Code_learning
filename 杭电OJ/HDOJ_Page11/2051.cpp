#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		char str[32]={0};
		int pos=0;
		while(n/2!=0)
		{
			str[pos]=n%2?'1':'0';
			n=n/2;
			pos++;
		}
		str[pos]=n%2?'1':'0';
		cout<<strrev(str)<<endl;
	}
}
