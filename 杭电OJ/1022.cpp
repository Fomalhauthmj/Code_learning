#include<iostream>
#include<string>
#include<stack>
using namespace std;
int  main()
{
    int n;
    string str1,str2;
    while(cin>>n>>str1>>str2)
    {
        stack<char> S;
        int write[2*n]={0};
        int writepos=0;
        int inpos=0;
        while(S.empty()==false) S.pop();
        for(int i=0;i<n;i++)
        {
            if(S.empty()==true)
            {
                S.push(str1[inpos++]);
                write[writepos++]=1;
            }
            while(S.top()!=str2[i]&&inpos<n)
            {
                S.push(str1[inpos++]);
                write[writepos++]=1;
            }
            if(S.top()==str2[i])
            {
                S.pop();
                write[writepos++]=-1;
            }
        }
        if(S.empty()==true)
        {
            cout<<"Yes."<<endl;
            for(int i=0;i<2*n;i++)
            {
                if(write[i]==1) cout<<"in"<<endl;
                if(write[i]==-1) cout<<"out"<<endl;
            }
        }
        else
        {
            cout<<"No."<<endl;
        }
        cout<<"FINISH"<<endl;
    }
}