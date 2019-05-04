#include<iostream>
using namespace std;
int main()
{
	long long res[10001]={0};
	res[1]=2;
	res[2]=7;
	for(int i=3;i<10001;i++) res[i]=res[i-1]+4*(i-1)+1;
	int c;
	while(cin>>c)
	{
		int *ptr=new int [c];
		for(int i=0;i<c;i++) cin>>ptr[i];
		for(int i=0;i<c;i++)
		{
			cout<<res[ptr[i]]<<endl;
		}
	}
} 
