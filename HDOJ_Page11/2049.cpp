#include<iostream>
using namespace std;
int main()
{
	int c;
	long long res[21]={0};
	res[1]=0;
	res[2]=1;
	for(int i=3;i<21;i++) res[i]=(i-1)*(res[i-1]+res[i-2]);
	while(cin>>c)
	{
		int a[c][2]={0};
		for(int i=0;i<c;i++) cin>>a[i][0]>>a[i][1];
		for(int i=0;i<c;i++)
		{
			long long sumn=1;
			long long summ=1;
			long long sumn_m=1;
			for(int i1=1;i1<=a[i][0];i1++) sumn*=i1;
			for(int i2=1;i2<=a[i][1];i2++) summ*=i2;
			for(int i3=1;i3<=(a[i][0]-a[i][1]);i3++) sumn_m*=i3;
			long long result=sumn/(summ*sumn_m);
			cout<<result*res[a[i][1]]<<endl;
		}
	}
	
} 
