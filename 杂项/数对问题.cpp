#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int main()
{
	int N;
	while(cin>>N)
	{
		V.clear();
		string str;
		for(int i=0;i<=N;i++)
		{
			str=to_string(i);
			string::iterator it;
			for(it=str.begin();it!=str.end();it++)
			{
				str.erase(it);
				if(str!=""&&stoi(str)+i==N)
				{
					V.push_back(i);
					break;
				}
				str=to_string(i);
			}
		}
		vector<int>::iterator reit;
		for(reit=V.begin();reit!=V.end();reit++)
		{
			cout<<*reit<<" ";
		}
		cout<<endl;
	}
}