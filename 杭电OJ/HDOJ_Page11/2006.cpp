#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int *ptr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>ptr[i];
	    } 
	    int sum=1;
	    for(int i=0;i<n;i++)
	    {
	    	if(ptr[i]%2!=0)
	    	{
	    		sum*=ptr[i];
			}
			else
			{
				continue;
			}
		}
		cout<<sum<<endl;
	} 
}
