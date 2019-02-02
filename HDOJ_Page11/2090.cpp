#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	double sum=0;
	string name;
	double num;
	double price;
	while(cin>>name>>num>>price&&cin.eof()!=true)
	{
		sum+=num*price;
	}
	cout<<fixed<<setprecision(1)<<sum<<endl;
}
