#include<iostream>
using namespace std;
int main()
{
	int n;
	long long res[51]={0};
	res[1]=3;
	res[2]=6;
	res[3]=6;
	for(int i=4;i<=50;i++)
	{
		res[i]=res[i-1]+2*res[i-2];
	}
	while(cin>>n)
	{
		cout<<res[n]<<endl; 
	}
}
