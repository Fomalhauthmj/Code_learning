#include<iostream>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;
stack<string> S1;
stack<string> S2;
stack<double> N;
map<string,int> T;
vector<string> PolishNotation(vector<string> V)
{
    while(!S1.empty()) S1.pop();
    while(!S2.empty()) S2.pop();
    vector<string>::reverse_iterator it;
    for(it=V.rbegin();it!=V.rend();it++)
    {
        if(*it=="+"||*it=="-"||*it=="*"||*it=="/")
        {
            if(S1.empty()||S1.top()==")") S1.push(*it);
            else if(T[*it]>=T[S1.top()]) S1.push(*it);
            else
            {
                string now=S1.top();
                S1.pop();
                S2.push(now);
                int flag=0;
                while(flag!=1)
                {
                    if(S1.empty()||S1.top()==")") 
                    {
                        S1.push(*it);flag=1;
                    }
                    else if(T[*it]>=T[S1.top()])
                    {
                        S1.push(*it);flag=1;
                    }
                    else
                    {
                        now=S1.top();
                        S1.pop();
                        S2.push(now);
                    }
                }
            }
        }
        else if(*it==")")
        {
            S1.push(*it);
        }
        else if(*it=="(")
        {
            string now=S1.top();
            S1.pop();
            while(now!=")")
            {
                S2.push(now);
                now=S1.top();
                S1.pop();
            }
            continue;
        }
        else
        {
            S2.push(*it);
        }
    }
    while(!S1.empty())
    {
        string now=S1.top();
        S1.pop();
        S2.push(now);
    }
    vector<string> R;
    while(!S2.empty())
    {
        string now=S2.top();
        S2.pop();
        R.push_back(now);
    }
    return R;
}
double ResForPolishNotation(vector<string> V)
{
    while(!N.empty()) N.pop();
    vector<string>::reverse_iterator it;
    for(it=V.rbegin();it!=V.rend();it++)
    {
       if(*it=="+"||*it=="-"||*it=="*"||*it=="/")
       {
           int flag=0;
           if(*it=="+") flag=1;
           else if(*it=="-") flag=2;
           else if(*it=="*") flag=3;
           else if(*it=="/") flag=4;
           double now=N.top();
           N.pop();
           double sub=N.top();
           N.pop();
           double res;
           switch(flag)
           {
               case 1:
               res=now+sub;
               break;
               case 2:
               res=now-sub;
               break;
               case 3:
               res=now*sub;
               break;
               case 4:
               res=now/sub;
               break;
               default:break;
           }
           N.push(res);
       }
       else 
       {
           double temp=stof(*it);
           N.push(temp);
       }
    }
    return N.top();
}
int main()
{
    T["+"]=1;
    T["-"]=1;
    T["*"]=2;
    T["/"]=2;
    vector<string> line;
    string str;
    while(getline(cin,str))
    {
        line.clear();
        if(str=="0") break;
        istringstream temp(str);
        while(temp>>str)
        {
            line.push_back(str);
        }
        vector<string> res1=PolishNotation(line);
        cout<<fixed<<setprecision(2)<<ResForPolishNotation(res1)<<endl;
    }
    return 0;
}