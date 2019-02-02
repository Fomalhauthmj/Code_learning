#include<iostream>
using namespace std;
int main()
{
	long long int resh[34]={0};
	long long int resl[34]={0};
	resh[0]=1;
	for(int i=1;i<34;i++)
	{
		resh[i]=3*resh[i-1]+2*resl[i-1];
		resl[i]=resh[i-1]+resl[i-1];
	}
	int n;
	while(cin>>n&&n!=-1)
	{
		cout<<resh[n]<<", "<<resl[n]<<endl;
	}
}
