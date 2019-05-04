#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define max 110
int a[max]={0};
int b[max]={0};
int c[max]={0};
int main()
{
    int n;
    string number;
    string guess;
    vector<int> res;
    map<char,int> T1;
    map<char,int> T2;
    while(cin>>n)
    {
        if(n==0) break;
        res.clear();
        int value[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        int correctnum;
        int correctpos;
        for(int i=1000;i<10000;i++)
        {
            int flag=0;
            number=to_string(i);
            T1.clear();
            for(int k=0;k<4;k++)
            {
                T1[number[k]]++;
            }
            for(int j=1;j<=n;j++)
            {
                T2.clear();
                correctnum=0;
                correctpos=0;
                guess=to_string(a[j]);
                for(int k=0;k<4;k++)
                {
                    if(guess[k]==number[k])  
                    {
                        correctpos++;
                    }
                    T2[guess[k]]++;
                }
                for(int k=0;k<4;k++)
                {
                    if(T2[number[k]]>0)
                    {
                        correctnum+=T1[number[k]]>T2[number[k]]?T2[number[k]]:T1[number[k]];
                        T2[number[k]]=0;
                    }
                }
                if(correctnum==b[j]&&correctpos==c[j])
                {
                    value[j]=1;
                }
                else
                {
                    flag=1;break;
                }
            }
            if(flag==1) continue;
            int sumvalue=0;
            for(int j=1;j<=n;j++) sumvalue+=value[j];
            if(sumvalue==n) 
            {
                res.push_back(i);
            }
        }
        if(res.size()==1) cout<<res[0]<<endl;
        else cout<<"Not sure"<<endl;
    }
}