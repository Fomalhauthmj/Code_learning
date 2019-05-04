#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		string *ptr=new string [n];
		string waste;
		getline(cin,waste);
		for(int i=0;i<n;i++)
		{
			getline(cin,ptr[i]); 
		}
		for(int i=0;i<n;i++)
		{
		    int num1,num2,num3,num4,num5;
	    	num1=num2=num3=num4=num5=0;
			for(int j=0;j<ptr[i].length();j++)
			{
				if(ptr[i][j]=='a'||ptr[i][j]=='A') num1++;
				if(ptr[i][j]=='e'||ptr[i][j]=='E') num2++;
				if(ptr[i][j]=='i'||ptr[i][j]=='I') num3++;
				if(ptr[i][j]=='o'||ptr[i][j]=='O') num4++;
				if(ptr[i][j]=='u'||ptr[i][j]=='U') num5++;
			}
			cout<<"a:"<<num1<<endl;
		    cout<<"e:"<<num2<<endl;
		    cout<<"i:"<<num3<<endl;
		    cout<<"o:"<<num4<<endl;
		    if(i==n-1) cout<<"u:"<<num5<<endl;
		    else cout<<"u:"<<num5<<endl<<endl;
		}
	}
}
