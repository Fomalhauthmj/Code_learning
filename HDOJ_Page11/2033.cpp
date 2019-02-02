#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n][6]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<6;j++) cin>>a[i][j];
		}
		for(int i=0;i<n;i++)
		{
			int h,m,s;
			h=a[i][0]+a[i][3];
			m=a[i][1]+a[i][4];
			s=a[i][2]+a[i][5];
			int temp1=s/60;
			int temp2=s%60;
			m+=temp1;
			s=temp2;
			int temp3=m/60;
			int temp4=m%60;
			h+=temp3;
			m=temp4;
			cout<<h<<" "<<m<<" "<<s<<endl;
		}
	}
}
