#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0&&b==0) continue;
		else
		{
			int result=1;
			for(int i=0;i<b;i++)
			{
				result=result*a%1000;
			}
			cout<<result%1000<<endl;
		}
	}
}
