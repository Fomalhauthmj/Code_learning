#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        string res;
        cin>>str;
        for(int i=0;i<str.length();)
        {
            int num=1;
            int pos=i+1;
            while(str[pos]==str[i])
            {
                num++;
                pos++;
            }
            if(num>1) res.append(to_string(num));
            res.append(1,str[i]);
            i+=num;
        }
        cout<<res<<endl;
    }
}