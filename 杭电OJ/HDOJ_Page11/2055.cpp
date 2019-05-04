#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		char *p1=new char[t];
		int *p2=new int[t];
		for(int i=0;i<t;i++) cin>>p1[i]>>p2[i];
		for(int i=0;i<t;i++)
		{
			int res;
			if(p1[i]>='A'&&p1[i]<='Z') res=p1[i]-64;
			else res=-(p1[i]-96);
			cout<<res+p2[i]<<endl;
		}
	}
}
