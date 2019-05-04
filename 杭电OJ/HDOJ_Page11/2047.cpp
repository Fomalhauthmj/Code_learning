#include<iostream>
using namespace std;
int main()
{
	int n;
	long long res[40]={0};
	res[1]=3;
	res[2]=8;
	for(int i=3;i<40;i++)
	{
		res[i]=2*(res[i-1]+res[i-2]);
	}
	while(cin>>n)
	{
		cout<<res[n]<<endl;
	}
}
