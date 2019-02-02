#include<iostream>
using namespace std;
 int main()
 {
 	long long a,b;
 	while(cin>>hex>>a>>b)
 	{
 		if(a+b>=0) cout<<uppercase<<hex<<a+b<<endl;
 		else cout<<uppercase<<hex<<"-"<<-(a+b)<<endl;
	}
 }
