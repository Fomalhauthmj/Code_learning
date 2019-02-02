#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
bool isleapyear(int y)
{
	if(y%400==0)
	{
		return true;
	}
	if(y%4==0&&y%100!=0)
	{
		return true;
	}
	return false;
}
int main()
{
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char date[11];
	char *y;
	char *m;
	char *d;
	while(cin>>date)
	{
		y=strtok(date,"/");
		m=strtok(NULL,"/");
		d=strtok(NULL,"/");
		if(isleapyear(atoi(y)))
		{
			int sum=0;
			for(int i=1;i<atoi(m);i++)
			{
				sum+=month[i];
			}
			if(atoi(m)>2)
			{
		    	cout<<sum+atoi(d)+1<<endl;

			}
			else
			{
				cout<<sum+atoi(d)<<endl;
			}
		}
		else
		{
			int sum=0;
			for(int i=1;i<atoi(m);i++)
			{
				sum+=month[i];
			}
			cout<<sum+atoi(d)<<endl;
		}
	}
}
