#include<iostream>
#include<cstring>
#include<algorithm>
#define maxdigit 1000
#define plus 1
#define minus -1
using namespace std;
class bignumber
{
    friend ostream & operator <<(ostream &cout,bignumber &bn);
    friend int  compare(bignumber,bignumber);
    private:
    char digits[maxdigit];
    int signbit;
    int lastdigit;
    public:
    bignumber();
    bignumber(long long num);
    bignumber(char *s);
    bignumber operator+(bignumber &a);
    bignumber operator-(bignumber &a);
    void zero_justify()
    {
        for(int i=lastdigit;i>=0;i--)
        {
            if(digits[i]=='0') lastdigit--;
            else break;
        }
    }
    void digit_left_move(int d)
    {
        for(int i=lastdigit;i>=0;i--)
        {
            digits[i+d]=digits[i];
        }
        for(int i=0;i<d;i++) digits[i]='0';
    }
  
};
bignumber::bignumber()
{
    lastdigit=0;
    signbit=plus;
    memset(digits,'0',sizeof(digits));
}
bignumber::bignumber(long long num)
{
    bignumber();
    if(num<0) 
    {
        signbit=minus;
        num=abs(num);
    }
    else
    {
        signbit=plus;
    }
    lastdigit=-1;
    while(num)
    {
        digits[++lastdigit]=num%10+'0';
        num/=10;
    }
}
bignumber::bignumber(char *s)
{
    bignumber();
    if(s[0]=='-')
    {
        signbit=minus;
        lastdigit=strlen(s)-2;
        for(int i=0;i<=lastdigit;i++)
        {
            digits[i]=s[lastdigit+1-i];
        }
    }
    else
    {
        signbit=plus;
        lastdigit=strlen(s)-1;
        for(int i=0;i<=lastdigit;i++)
        {
            digits[i]=s[lastdigit-i];
        }
    }
}
ostream & operator <<(ostream &cout,bignumber &bn)
{
    if(bn.signbit==minus) cout<<'-';
    for(int i=bn.lastdigit;i>=0;i--)
    {
        cout<<bn.digits[i];
    }
    return cout;
}
int compare(const bignumber &a,const bignumber &b)
{
    return 0;
    //a>b -1
    //a=b 0
    //a<b 1   
}
bignumber bignumber::operator+(bignumber &a)
{
    bignumber c;
    if(signbit==a.signbit)
    {
        c.signbit=signbit;
        c.lastdigit=max(lastdigit,a.lastdigit)+1;
        int carry=0;
        int temp;
        for(int i=0;i<=c.lastdigit;i++)
        {
            temp=digits[i]-'0'+a.digits[i]-'0'+carry;
            c.digits[i]=temp%10+'0';
            carry=temp/10;
        }
        c.zero_justify();
    }
    else
    {
        if(signbit==minus)
        {
            signbit=plus;
            //c=a-*this;
            signbit=minus;
        }
        else
        {
            a.signbit=plus;
            //c=*this-a;
            a.signbit=minus;
        }
    }
    return c;
}
bignumber bignumber::operator-(bignumber &a)
{
    bignumber c;
    if(signbit==minus||a.signbit==minus)
    {
        a.signbit=-1*a.signbit;
        c=*this+a;
        a.signbit=-1*a.signbit;
        return c;
    }
    else
    {
        if(compare(*this,a)==plus)
        {
            c=a-*this;
            c.signbit=minus;
            return c;
        }
        c.lastdigit=max(a.lastdigit,lastdigit);
        int borrow=0;
        c.signbit=plus;
        int v;
        for(int i=0;i<=c.lastdigit;i++)
        {
            v=digits[i]-a.digits[i]-borrow;
            if(v<0)
            {
                v+=10;borrow=1;
            }
            else
            {
                borrow=0;
            }
             c.digits[i]=v+'0';
        }
    }
    c.zero_justify();
    return c;
}
int main()
{
    bignumber bn("1240012");
    bignumber num(424);
    bignumber zero;
    cout<<bn<<endl;
    cout<<num<<endl;
    cout<<zero<<endl;
    zero=bn+num;
    cout<<zero<<endl;
    system("pause");
    return 0;
}