#include<iostream>
#include<vector>
#define max 100010
using namespace std;
long long s[max];
long long c[max];
vector<pair<int,int>> V;
long long res;
int n;
bool result(int mode)
{
    for(int i=1;i<=n;i++) c[i]=s[i];
    V.clear();
    switch(mode)
    {
        case 1:
            c[1]--;c[n]++;
            res=1;
            V.push_back(make_pair(1,n));
            break;
        case -1:
            c[1]++;c[n]--;
            res=1;
            V.push_back(make_pair(n,1));
            break;
        case 0:
            res=0;
            break;
        default:
            break;
    }
    for(int i=1;i<n;i++)
    { 
        if(c[i]==1) 
        {
            V.push_back(make_pair(i,i+1));
            c[i]=0;c[i+1]++;
            res++;
        }
        else if(c[i]==-1) 
        {
            V.push_back(make_pair(i+1,i));
            c[i]=0;c[i+1]--;
            res++;
        }
        else if(c[i]==0) continue;
        else if(c[i])
        {
            return false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=0)
        {
            return false;
        }
    }
    return true;
}
void print()
{
    cout<<"YES"<<endl;
    cout<<res<<endl;
    vector<pair<int,int>>::iterator it;
    for(it=V.begin();it!=V.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }         
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    long long sum;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>s[i];
            sum+=s[i];
        }
        if(sum%n!=0) 
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            long long avg=sum/n;
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                s[i]-=avg;
                if(s[i]>2||s[i]<-2)
                {
                    flag=1;
                    break;
                }
            }
            int subflag=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i]!=0)
                {
                    subflag=1;
                    break;
                }
            }
            if(subflag==0)
            {
                cout<<"YES"<<endl;
                cout<<0<<endl;
                continue;
            }
            if(flag==0)
            {
                if(result(1)) print();
                else if(result(-1)) print();
                else if(result(0)) print();
                else cout<<"NO"<<endl;
            }
            else cout<<"NO"<<endl; 
        }
    }
}