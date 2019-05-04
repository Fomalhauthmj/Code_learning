#include<iostream>
using namespace std;
int main()
{
	int n;
	long long res[51]={0};
	res[1]=1;
	res[2]=2;
	res[3]=3;
	for(int i=4;i<=50;i++)
	{
		res[i]=res[i-1]+res[i-2];
	}
	while(cin>>n)
	{
		cout<<res[n]<<endl;
	}
}
