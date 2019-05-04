#include<iostream>
using namespace std;
int result(int i)
{
	if(i==2) return 1;
	if(i==3) return 2;
	if(i>3) return result(i-1)+result(i-2);
}
int main()
{
	int n;
	while(cin>>n)
	{
		int *ptr=new int[n];
		for(int i=0;i<n;i++) cin>>ptr[i];
		for(int i=0;i<n;i++) cout<<result(ptr[i])<<endl;
	}
} 
