#include<iostream>
using namespace std;
int result(int time,int *ptr,int num,int size)
{
	if(time==1)
	{
		int temp1=ptr[size-time];
		int temp2=num;
		while(temp1%temp2!=0)
		{
			int temp3=temp2;
			temp2=temp1%temp2;
			temp1=temp3;
		}
		return ptr[size-time]/temp2*num;
	}
	else
	{
		int temp1=ptr[size-time];
		int temp2=num;
		while(temp1%temp2!=0)
		{
			int temp3=temp2;
			temp2=temp1%temp2;
			temp1=temp3;
		}
		int temp4=ptr[size-time]/temp2*num;  //注意先乘再除会溢出 要改成先除在乘 
		return result(time-1,ptr,temp4,size);
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		int *ptr=new int [n];
		for(int i=0;i<n;i++) cin>>ptr[i]; 
		cout<<result(n-1,ptr,ptr[0],n)<<endl;
	}
}
