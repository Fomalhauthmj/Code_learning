#include<iostream>
using namespace std;
int result(int i,int num)
{
	if(i==1) return (num-1)*2;
	if(i>1) return  result(i-1,(num-1)*2);
}
int main()
{
	int n;
	while(cin>>n)
	{
		int *ptr=new int [n];
		for(int i=0;i<n;i++) cin>>ptr[i];
		for(int i=0;i<n;i++) cout<<result(ptr[i],3)<<endl;
	}
}
