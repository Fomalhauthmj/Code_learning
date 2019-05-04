#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
	string str;
	while(getline(cin,str)&&str!="#")
	{
		char *p=new char[str.length()+1];
		strcpy(p,str.c_str());
		vector<string> result;
		char *temp=strtok(p," ");
		while(temp)
		{
			string res=temp;
			result.push_back(res);
			temp=strtok(NULL," ");
		}
		int sum=0;
		for(int i=0;i<result.size();i++)
		{
			int flag=0;
			for(int j=0;j<i;j++)
			{
				if(result[j]==result[i])
				{
					flag=1;
					break;
				}
			}
			if(flag==1) continue;
			else sum++;
		}
		cout<<sum<<endl;
	}
}
