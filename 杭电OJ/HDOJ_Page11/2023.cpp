#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int score[n][m]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>score[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			double sum=0;
			for(int j=0;j<m;j++) sum+=score[i][j];
			if(i==n-1) printf("%.2lf\n",sum/m);
			else printf("%.2lf ",sum/m);
		}
		double avg[m]={0};
		for(int j=0;j<m;j++)
		{
			double sum=0;
			for(int i=0;i<n;i++) sum+=score[i][j];
			avg[j]=sum/n;
			if(j==m-1) printf("%.2lf\n",avg[j]);
			else printf("%.2lf ",avg[j]); 
		}
		int num1=0;
		for(int i=0;i<n;i++)
		{
			int num2=0;
			for(int j=0;j<m;j++)
			{
				if(score[i][j]>=avg[j])
				{
					num2++;
				}
				else break;
			}
			if(num2==m) num1++;
		}
		printf("%d\n\n",num1);
	}
}
