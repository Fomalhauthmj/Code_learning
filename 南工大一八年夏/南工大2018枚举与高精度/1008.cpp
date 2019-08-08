#include<iostream>
#include<string>
using namespace std;
#define L 1000
// setw() ->代替打印空格
string add(string a,string b)//只限两个非负整数相加
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
string sub(string a,string b)//只限大的非负整数减小的非负整数
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++)
    {
        na[i]-=nb[i];
        if(na[i]<0) na[i]+=10,na[i+1]--;
    }
    while(!na[--lmax]&&lmax>0)  ;lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
string mul(string a,string b)//高精度乘法a,b,均为非负整数
{
    string s;
    int na[L],nb[L],nc[L],La=a.size(),Lb=b.size();//na存储被乘数，nb存储乘数，nc存储积
    fill(na,na+L,0);fill(nb,nb+L,0);fill(nc,nc+L,0);//将na,nb,nc都置为0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//将字符串表示的大整形数转成i整形数组表示的大整形数
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//统一处理进位
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//判断第i+j位上的数字是不是0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//将整形数组转成字符串
    return s;
}
void result(string left,string right,int opmode)
{
    if(opmode==1)
    {
        string res=add(left,right);
        int maxsize=(right.length()+1)>res.length()?(right.length()+1):res.length();
        int max=maxsize>left.length()?maxsize:left.length();
        for(int i=1;i<=max-left.length();i++) cout<<" ";
        cout<<left<<endl;
        for(int i=1;i<=max-right.length()-1;i++) cout<<" ";
        cout<<"+"<<right<<endl;
        for(int i=1;i<=max-maxsize;i++) cout<<" "; 
        for(int i=1;i<=maxsize;i++) cout<<"-";
        cout<<endl;
        for(int i=1;i<=max-res.length();i++) cout<<" ";
        cout<<res<<endl;
    }
    else if(opmode==2)
    {
        string res=sub(left,right);
        int maxsize=(right.length()+1)>res.length()?(right.length()+1):res.length();
        int max=maxsize>left.length()?maxsize:left.length();
        for(int i=1;i<=max-left.length();i++) cout<<" ";
        cout<<left<<endl;
        for(int i=1;i<=max-right.length()-1;i++) cout<<" ";
        cout<<"-"<<right<<endl;
        for(int i=1;i<=max-maxsize;i++) cout<<" "; 
        for(int i=1;i<=maxsize;i++) cout<<"-";
        cout<<endl;
        for(int i=1;i<=max-res.length();i++) cout<<" ";
        cout<<res<<endl;
    }
    else if(opmode==3)
    {
        string res=mul(left,right);
        if(res[0]=='0') res="0";
        if(right.length()==1)
        {
        
            int maxsize=2>res.length()?2:res.length();
            int max=maxsize>left.length()?maxsize:left.length();
            for(int i=1;i<=max-left.length();i++) cout<<" ";
            cout<<left<<endl;
            for(int i=1;i<=max-right.length()-1;i++) cout<<" ";
            cout<<"*"<<right<<endl;
            for(int i=1;i<=max-maxsize;i++) cout<<" ";
            for(int i=1;i<=maxsize;i++) cout<<"-";
            cout<<endl;
            for(int i=1;i<=max-res.length();i++) cout<<" ";
            cout<<res<<endl;
        }
        else
        {
            string lasttemp=mul(left,to_string(right[0]-'0'));
            string firsttemp=mul(left,to_string(right[right.length()-1]-'0'));
            if(firsttemp[0]=='0') firsttemp="0";
            int maxsize1=(right.length()+1)>firsttemp.length()?(right.length()+1):firsttemp.length();
            int maxsize2=lasttemp.length()+right.length()-1>res.length()?(lasttemp.length()+right.length()-1):res.length();
            int max=maxsize1>maxsize2?maxsize1:maxsize2;
            for(int i=1;i<=max-left.length();i++) cout<<" ";
            cout<<left<<endl;
            for(int i=1;i<=max-right.length()-1;i++) cout<<" ";
            cout<<"*"<<right<<endl;
            for(int i=1;i<=max-maxsize1;i++) cout<<" ";
            for(int i=1;i<=maxsize1;i++) cout<<"-";
            cout<<endl;
            int pos=0;
            for(int i=right.length()-1;i>=0;i--)
            {
                string temp=mul(left,to_string(right[i]-'0'));
                if(temp[0]=='0') temp="0";
                int space=max-temp.length()-pos;
                for(int i=1;i<=space;i++) cout<<" ";
                cout<<temp<<endl;
                pos++;
            }
            for(int i=1;i<=max-maxsize2;i++) cout<<" ";
            for(int i=1;i<=maxsize2;i++) cout<<"-";
            cout<<endl;
            for(int i=1;i<=max-res.length();i++) cout<<" ";
            cout<<res<<endl;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    string line;
    string left;
    string right;
    getline(cin,line);
    while(t--)
    {
        getline(cin,line);
        int oppos;
        int opmode;
        if(line.find('+')!=string::npos)   
        {
            oppos=line.find('+');
            opmode=1;
        }
        else if(line.find('-')!=string::npos) 
        {
            oppos=line.find('-');
            opmode=2;
        }
        else if(line.find('*')!=string::npos) 
        {
            oppos=line.find('*');
            opmode=3;
        }
        left=line.substr(0,oppos);
        right=line.substr(oppos+1,line.length()-1-oppos);
        result(left,right,opmode);
        cout<<endl;
    }
    //system("pause");
}