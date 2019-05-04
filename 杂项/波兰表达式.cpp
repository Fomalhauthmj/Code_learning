#include<iostream>
#include<stack>
#include<string>
#include<map>
#include<vector>
using namespace std;
stack<string> S1;
stack<string> S2;
stack<float> N;
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
float ResForPolishNotation(vector<string> V)
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
           float res;
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
           float temp=stof(*it);
           N.push(temp);
       }
    }
    return N.top();
}
vector<string> ReversePolishNotation(vector<string> V)
{
    while(!S1.empty()) S1.pop();
    while(!S2.empty()) S2.pop();
    vector<string>::iterator it;
    for(it=V.begin();it!=V.end();it++)
    {
        if(*it=="+"||*it=="-"||*it=="*"||*it=="/")
        {
            if(S1.empty()||S1.top()=="(") S1.push(*it);
            else if(T[*it]>T[S1.top()]) S1.push(*it);
            else
            {
                string now=S1.top();
                S1.pop();
                S2.push(now);
                int flag=0;
                while(flag!=1)
                {
                    if(S1.empty()||S1.top()=="(") 
                    {
                        S1.push(*it);flag=1;
                    }
                    else if(T[*it]>T[S1.top()])
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
        else if(*it=="(")
        {
            S1.push(*it);
        }
        else if(*it==")")
        {
            string now=S1.top();
            S1.pop();
            while(now!="(")
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
float ResForReversePolishNotation(vector<string> V)
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
           float res;
           switch(flag)
           {
               case 1:
               res=sub+now;
               break;
               case 2:
               res=sub-now;
               break;
               case 3:
               res=sub*now;
               break;
               case 4:
               res=sub/now;
               break;
               default:break;
           }
           N.push(res);
       }
       else 
       {
           float temp=stof(*it);
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
    cin>>str;
    while(str!="=")
    {
        line.push_back(str);
        cin>>str;
    }
    vector<string> res1=PolishNotation(line);
    vector<string> res2=ReversePolishNotation(line);
    vector<string>::iterator it;
    for(it=res1.begin();it!=res1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<ResForPolishNotation(res1)<<endl;
    vector<string>::reverse_iterator rit;
    for(rit=res2.rbegin();rit!=res2.rend();rit++)
    {
        cout<<*rit<<" ";
    }
    cout<<endl;
    cout<<ResForReversePolishNotation(res2)<<endl;
    
    system("pause");
}