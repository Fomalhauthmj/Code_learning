#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		if(t>=90&&t<=100)
		{
			cout<<"A"<<endl;
		    continue;
	    }
		if(t>=80&&t<90)
		{
			cout<<"B"<<endl;
			continue;
		}
		if(t>=70&&t<80)
		{
			cout<<"C"<<endl;
			continue;
		}
		if(t>=60&&t<70)
		{
			cout<<"D"<<endl;
			continue;
		}
		if(t>=0&&t<60)
		{
			cout<<"E"<<endl;
			continue;
		}
		cout<<"Score is error!"<<endl;
	}
	return 0;
}
