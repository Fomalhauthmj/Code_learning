#include<iostream>
using namespace std;
int main()
{
	char ch[3];
	while(cin>>ch[0]>>ch[1]>>ch[2])
	{
		char max=ch[0];
		char min=ch[0];
		for(int i=0;i<3;i++)
		{
			if(ch[i]>max)
			{
				max=ch[i];
			}
			if(ch[i]<min)
			{
				min=ch[i];
			}
		}
		char mid;
		for(int i=0;i<3;i++)
		{
			if(max!=ch[i]&&min!=ch[i])
			{
				mid=ch[i];
				break;
			}
			else continue;
		}
		cout<<min<<" "<<mid<<" "<<max<<endl;
}	
}

