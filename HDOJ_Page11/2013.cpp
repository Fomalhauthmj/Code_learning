#include<iostream>
using namespace std;
int result(int day,int num)
{
	if(day==1) return num;
	else
	{
		result(day-1,(num+1)*2);
	}
}
int main()
{
	int num;
	while(cin>>num)
	{
		cout<<result(num,1)<<endl;
	}
}
