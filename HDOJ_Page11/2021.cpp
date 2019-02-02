#include<iostream>
using namespace std;
int result(int salary)
{
	int num100=salary/100;
	int num50=(salary-100*num100)/50;
	int num10=(salary-100*num100-50*num50)/10;
	int num5=(salary-100*num100-50*num50-10*num10)/5;
	int num2=(salary-100*num100-50*num50-10*num10-5*num5)/2;
	int num1=salary-100*num100-50*num50-10*num10-5*num5-2*num2;
	return num100+num50+num10+num5+num2+num1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) continue;
		else
		{
			int *salary=new int[n];
			for(int i=0;i<n;i++)
			{
				cin>>salary[i];
			}
			int sum=0;
			for(int i=0;i<n;i++)
			{
				sum+=result(salary[i]);
			}
			cout<<sum<<endl;
		}
	}
}
