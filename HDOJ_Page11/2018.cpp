#include<iostream>
using namespace std;
int result(int year) 
{
	if(year<4) return year;
	else return result(year-3)+result(year-1);
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n!=0)
		{
			cout<<result(n)<<endl;
		}
		else continue;
	}
 } 
