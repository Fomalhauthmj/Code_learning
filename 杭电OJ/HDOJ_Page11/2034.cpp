#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) continue;
		else
		{
		int *ptr1=new int [n];
		int *ptr2=new int [m];
		for(int i=0;i<n;i++) cin>>ptr1[i];
		for(int i=0;i<m;i++) cin>>ptr2[i];
		int *result=new int [n];
		int pos=0;
		for(int i=0;i<n;i++)
		{
			int flag=0;
			for(int j=0;j<m;j++)
			{
				if(ptr2[j]==ptr1[i]) 
				{
					flag=1;
					break;
				}
				else continue;
			}
			if(flag==0) result[pos++]=ptr1[i];
		}
		if(pos==0) cout<<"NULL"<<endl;
		else
		{
		for(int i=0;i<pos-1;i++)
		{
			for(int j=0;j<pos-1-i;j++)
			{
				if(result[j]>result[j+1])
				{
					int temp=result[j];
					result[j]=result[j+1];
					result[j+1]=temp;
				}
			}
		}
		for(int i=0;i<pos;i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<endl;
    	}
	    }
    }
}
