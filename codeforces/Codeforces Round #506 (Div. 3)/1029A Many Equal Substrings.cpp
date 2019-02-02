#include<iostream>
#include<string>
using namespace std;
int n,k;
string t;
string ans;
void func()
{
    ans=t;
    int cnt=1;
    int pos=1;
    int lent=t.size();//注意size()返回字符串长度 而 sizeof() 返回内存空间大小
    while(cnt<k)
    {
        int lenans=ans.size();
        if(pos>=lenans)
        {
            ans+=t;
            cnt++;
        }
        else
        {
            bool canadd=true;
            int addpos=0;
            for(int i=0;i<lent;i++)
            {
                if((i+pos)>=lenans) break;
                if(ans[i+pos]!=t[i]) canadd=false;
                else addpos++;
            }
            if(canadd)
            {
                //cout<<"len:"<<addpos<<"  "<<"will add :"<<t.substr(addpos)<<endl;
                ans+=t.substr(addpos);
                cnt++;
            }
        }
        pos++;
        //cout<<"now ans : "<<ans<<endl;
    }
    cout<<ans<<endl;
}
void prefix_func()
{
    //KMP next的简化只求最长的前缀与后缀相同
    int maxlen=0;
    for(int i=1;i<n;i++)
    {
        if(t.substr(0,i)==t.substr(n-i)) maxlen=i;
    }
    int len=n-maxlen;
    for(int i=0;i<k-1;i++)
    {
        cout<<t.substr(0,len);
    } 
    cout<<t<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k>>t)
    {
      //func();
      prefix_func();
    }
}
