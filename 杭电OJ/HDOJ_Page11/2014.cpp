#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		float *ptr=new float[n];
		for(int i=0;i<n;i++)
		{
			cin>>ptr[i];
		}
		float max=ptr[0];
		float min=ptr[0];
		float sum=0;
		for(int i=0;i<n;i++)
		{
			if(ptr[i]>max) max=ptr[i];
			if(ptr[i]<min) min=ptr[i];
			sum+=ptr[i];
		}
		
		cout<<fixed<<setprecision(2)<<(sum-max-min)/(n-2)<<endl;
	}
}
