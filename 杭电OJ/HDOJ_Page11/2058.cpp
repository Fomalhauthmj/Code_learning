#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) continue;
		else
		{
			for(int i=sqrt(2*m);i>0;i--)
			{
				int a=m/i+(1-i)/2;
				if(i*(a+a+i-1)/2==m) cout<<'['<<a<<','<<a+i-1<<']'<<endl; 
			}
			cout<<endl;
		}
    }
}
