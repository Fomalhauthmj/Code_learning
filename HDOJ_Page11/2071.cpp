#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		for(int k=0;k<t;k++)
		{
			int n;
			cin>>n;
		double *ptr=new double[n];
		for(int i=0;i<n;i++) cin>>ptr[i];
		int maxpos=0;
		for(int i=0;i<n;i++)
		{
			if(ptr[i]>ptr[maxpos]) maxpos=i;
			else continue;
		}
		cout<<fixed<<setprecision(2)<<ptr[maxpos]<<endl;
	    }
	}
}
