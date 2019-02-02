#include<iostream>
using namespace std;
long long c(int a,int b)
{
	if(b==0)
		return 1;
	else
	{
		long long rec=1,m=1;
		for(int i=a,j=1;i>=a-b+1,j<=b;i--,j++)
		{
			rec*=i;
			m*=j;
		}
		return rec/m;
	}
} 
int main()
{
	long long int res[13]={0};
	res[1]=0;
	res[2]=1;
	for(int i=3;i<13;i++) res[i]=(i-1)*(res[i-1]+res[i-2]);
	int n;
	while(cin>>n)
	{
		
		if(n==0) continue;
	    else
		{
		    long long int result=1;
		    for(int i=2;i<=n/2;i++) 
			{
				result+=c(n,i)*res[i];
			}
		    cout<<result<<endl;
	    }
	}
}
