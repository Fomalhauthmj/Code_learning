#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long m,n,k;
vector<long long> factors;
long long cnt;
//二分 容斥
//给出一个A值 求出1-A中与m,n都互质的数的个数(容斥)
//根据个数与k的比较结果来二分逼近
//猜测若一个数与a,b互质则该数与LCM(a,b)互质
long long GCD(long long a,long long b)
{
    if(b==0) return a;
    else return GCD(b,a%b);
}
void Prime_factor(long long num)
{
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            factors.push_back(i);
            while(num%i==0)
            {
                num/=i;
            }
        }
    }
    if(num>1) factors.push_back(num);
    /*
    for(auto ele:factors)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    */
}
//AC
long long ans;
void DFS(long long k,long long t,long long s,long long n)			//利用容斥原理求可以由公因子组成的数的个数,
{  
    if(k==cnt)  //k为当前因子  t为所含因子数  s为因子积   n为范围 
    {
        if(t&1) ans+=n/s;
        else if(t!=0) ans-=n/s;
        return;
    }
    DFS(k+1,t,s,n);
    DFS(k+1,t+1,s*factors[k],n);
}
//WA?  !:int->long long 溢出
long long get_num(long long num)
{
    //根据容斥原理
    long long temp=0;
    for(int i=1;i<(1<<(cnt));i++)//0不取 1取
    {
        long long mult=1,bits=0;
        for(int j=0;j<cnt;j++)
        {
            if(i&(1<<j))//包含有第j个素数因子
            {
                bits++;
                mult*=factors[j];
            }
        }
        long long cur_num=num/mult;
        if(bits&1)  temp+=cur_num;
        else    temp-=cur_num;
    }
    //cout<<"from 1 to "<<num<<" ans:"<<num-temp<<endl;
    return num-temp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    int casenum=1;
    while(T--)
    {
        cin>>m>>n>>k;
        factors.clear();
        Prime_factor(m);
        Prime_factor(n);
        sort(factors.begin(),factors.end());
        cnt=unique(factors.begin(),factors.end())-factors.begin();
        long long left=1;
        long long right=1e18;
        long long mid;//二分边界
        while(left<=right)
        {
            mid=(left+right)/2;
            //ans=0;
            //DFS(0,0,1,mid);
            long long temp=get_num(mid);
            //cout<<"cur:"<<left<<" "<<right<<" "<<mid<<" "<<temp<<endl;
            if(temp<k)
            {
                left=mid+1;
            }
            else if(temp>=k)
            {
                right=mid-1;
            }
        }
        cout<<"Case "<<casenum++<<": "<<left<<endl;
    }
}