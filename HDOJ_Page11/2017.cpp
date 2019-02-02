#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		string *ptr=new string [n];
		for(int i=0;i<n;i++)
		{
			cin>>ptr[i];
		}
		for(int i=0;i<n;i++)
		{
			int num=0;
			for(int j=0;j<ptr[i].size();j++)
			{
				if(ptr[i][j]>='0'&&ptr[i][j]<='9') num++;
				else continue;
			}
			cout<<num<<endl;
		}
	}
}
