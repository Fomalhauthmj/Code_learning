#include<iostream>
#include<math.h>
using namespace std;
int express(int i)
{
	return i*i+i+41; 
}
bool isprimenumber(int num)
{
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0) return false;
		else continue;
	}
	return true;
}
int main()
{
	int x,y;
	while(cin>>x>>y)
	{
		if(x==0&&y==0) continue;
		else
		{
			for(int i=x;i<=y;i++)
			{
				if(isprimenumber(express(i))==true) 
				{
					if(i==y) cout<<"OK"<<endl;
					else continue;
				}
				else
				{
					cout<<"Sorry"<<endl;
					break;
				}
			}
		}
	}
	
}
