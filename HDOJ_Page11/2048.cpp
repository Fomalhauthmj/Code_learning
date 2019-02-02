#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int c;
	long long res[21]={0};
	res[1]=0;
	res[2]=1;
	res[3]=2;
	for(int i=3;i<21;i++)
	{
		res[i]=(i-1)*(res[i-1]+res[i-2]);
	}
	while(cin>>c)
	{
		
		int *ptr=new int [c];
		for(int i=0;i<c;i++) cin>>ptr[i];
		for(int i=0;i<c;i++)
		{
			if(ptr[i]>7) ptr[i]=7;
			int sum=1;
			for(int j=1;j<=ptr[i];j++) sum*=j;
			double result=res[ptr[i]]/(0.01*sum);
			cout<<fixed<<setprecision(2)<<result<<"%"<<endl; 
		}
	}
}
