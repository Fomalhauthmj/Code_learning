#include<iostream>
using namespace std;
int main()
{
	long long res[51]={0};
	res[0]=0;
	res[1]=1;
	for(int i=2;i<51;i++) res[i]=res[i-1]+res[i-2];
	int n;
	while(cin>>n&&n!=-1) cout<<res[n]<<endl;
}
