#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class person
{
public:
	string name;
	int num;
	int time;
	person(string s ="",int n=0,float t=0)
	{
		name=s;
		num=n;
		time=t;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	person s[1000];
	int pos=0;
	string name;
	string a[n];
	int result[2]={0};
	while(cin>>name)
	{
		result[0]=0;result[1]=0;
		for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i++)
	    {
		    if(a[i].find("(")!=string::npos)
		    {
			    int pos1=a[i].find("(");
			    int pos2=a[i].find(")");
			    string sub1=a[i].substr(0,pos1);
			    string sub2=a[i].substr(pos1+1,pos2-pos1-1);
			    int num1=stoi(sub1);
			    int num2=stoi(sub2);
			    result[0]++;
			    result[1]+=num1+m*num2;
		    }
		    else
		    {
			    int num=stoi(a[i]);
			    if(num>0)
			    {
				    result[0]++;
				    result[1]+=num;
			    }
		    }
	    }
		person temp;
		temp.name=name;
		temp.num=result[0];
		temp.time=result[1];
		s[pos]=temp;
		pos++;
	}
	for(int i=0;i<pos;i++)
	{
		for(int j=0;j<pos-i-1;j++)
		{
			if(s[j].num<s[j+1].num) swap(s[j],s[j+1]);
			if(s[j].num==s[j+1].num)
			{
				if(s[j].time>s[j+1].time) swap(s[j],s[j+1]);
			    if(s[j].time==s[j+1].time)
			    {
			    	if(s[j].name>s[j+1].name) swap(s[j],s[j+1]);
				}
			}
		}
	}
	for(int i=0;i<pos;i++)
	{
		cout<<std::left<<setw(10)<<s[i].name<<" "<<std::right<<setw(2)<<s[i].num<<" "<<setw(4)<<s[i].time<<endl;
	}

}
