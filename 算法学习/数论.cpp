//TODO:数论

//TODO:引例：跳兽问题
//xm=(y-1)*2n+1 或 xm=y*2n-1 -> mx+2ny=1 这里的系数有正负

//TODO:GCD与LCM

//TODO:质因数分解
//对于一个数的质因数分解 从2到sqrt(number)
//未优化 这里使用试除法
/*
#include<iostream>
#include<cstring>
using namespace std;
long long number;
int a[50][2];
void func(int n)
{
    int cnt=0;
    memset(a,0,sizeof(a));
    for(int i=2;i<=n;i++)  //TODO:优化i从2到sqrt(n)
    //这里在寻找n的因数 因为因数是成对出现的 所以不可能有一对因数均大于根号n 
    //如果不能被2到sqrt(n)范围内的数整除 那么也不可能在之后的范围内出现可以整除的数
    //2 3 5 7....素数处理后
    {
        if(n%i==0) 
        {
            a[cnt][0]=i;
            while(n%i==0)
            {
                a[cnt][1]++;
                n/=i;
            }
            cnt++;
        }
    }
    cout<<number<<"=";
    for(int i=0;i<cnt;i++)
    {
        if(i!=cnt-1)    cout<<a[i][0]<<"^"<<a[i][1]<<"*";
        else cout<<a[i][0]<<"^"<<a[i][1]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>number)
    {
        func(number);
    }
}
*/

//TODO:n!的质因数分解
//小于n的质因子 其指数分别为n/i^k向下取整后之和  k=1...

//TODO:GCD的性质

//TODO:欧几里得算法
/*
int GCD(int a,int b)  //复杂度？
{
    if(b==0) return a;
    else return GCD(b,a%b);
}
*/
//TODO:Stein算法  通过位运算  处理大整数
/*
#include<iostream>
using namespace std;
int GCD(int a,int b)
{
    int r=0;
    //注意大小交换
    while(b>0)
    {
        if(a<b) swap(a,b);
        if(!(a&1)&&!(b&1))//均为偶数
        {
            a>>=1;
            b>>=1;
            r++;
        }
        else if(!(a&1)&&(b&1))//a为偶数 b为奇数
        {
            a>>=1;
        }
        else if((a&1)&&!(b&1))//a为奇数 b为偶数
        {
            b>>=1;
        }
        else if((a&1)&&(b&1))//均为奇数
        {
            a=a-b;
        }
    }
    return a<<r;//循环到最后b=0
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<GCD(a,b)<<endl;
    }
}
*/

//TODO:http://codeforces.com/contest/891/problem/A
// 含有1  相邻两个元素的GCD=1  区间内GCD=1
/*
#include<iostream>
using namespace std;
#define N 2010
#define inf 0x3f3f3f3f
int n;
long long a[N];
long long GCD(long long a,long long b)
{
    int r=0;
    //注意大小交换
    while(b>0)
    {
        if(a<b) swap(a,b);
        if(!(a&1)&&!(b&1))//均为偶数
        {
            a>>=1;
            b>>=1;
            r++;
        }
        else if(!(a&1)&&(b&1))//a为偶数 b为奇数
        {
            a>>=1;
        }
        else if((a&1)&&!(b&1))//a为奇数 b为偶数
        {
            b>>=1;
        }
        else if((a&1)&&(b&1))//均为奇数
        {
            a=a-b;
        }
    }
    return a<<r;//循环到最后b=0
}
long long gcd[N][N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int GCD_number;
        int number_of_1=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1) number_of_1++;
            if(i==1) GCD_number=a[i];
            else GCD_number=GCD(GCD_number,a[i]);
        }
        if(GCD_number!=1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(number_of_1>0)
        {
            cout<<n-number_of_1<<endl;
            continue;
        }
        //并无1直接出现
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(i==j)    gcd[i][j]=a[j];
                else gcd[i][j]=GCD(gcd[i][j-1],a[j]);
                if(gcd[i][j]==1)
                {
                    ans=min(ans,j-i);
                }
            }
        }
        if(ans==inf) cout<<-1<<endl;
        else cout<<n-1+ans<<endl;
    }
}
*/
//TODO:http://codeforces.com/contest/798/problem/C
//对于两个相邻的数 这里GCD必为2或2的倍数 因为这些变换？？？
//如果一奇一偶经过2次变换全为偶数  两奇经过1次变换全为偶数 贪心先变换两奇 处理所有的奇数
/*
#include<iostream>
using namespace std;
#define N 100010
long long a[N];
int n;
long long GCD(long long a,long long b)
{
    if(b==0) return a;
    else return GCD(b,a%b);
}
int v[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int GCD_number;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(a[i]&1) v[i]=1;
            else v[i]=0;
            if(i==1) GCD_number=a[i];
            else GCD_number=GCD(GCD_number,a[i]);
        }
        if(GCD_number>1)
        {
            cout<<"Yes"<<endl;
            cout<<0<<endl;
            continue;
        }
        int pos=1;
        int cnt=0;
        while(pos<=n)
        {
            if((v[pos]&1)&&(v[pos+1]&1))//两个奇数
            {
                v[pos]=v[pos+1]=0;
                cnt+=1;
                pos+=2;
            }
            else pos++;
        }
        pos=1;
        while(pos<=n)
        {
            if(v[pos++]&1) cnt+=2;
        }
        cout<<"Yes"<<endl;
        cout<<cnt<<endl;
    }
}
*/

//TODO:LCM
/*
int LCM(int a,int b)
{
    return abs(a)*abs(b)/GCD(a,b);
}
*/

//TODO:例:除法表达式  贪心 通过添加括号使分母最小为x2 分子最大为x1*x3*...*xn
//循环 d=GCD(x1...xn,x2) x2/=d x2==1 success

//TODO:扩展欧几里德算法  ax+by=GCD(a,b);
/*
int x,y;
int Extend_GCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int r=Extend_GCD(b,a%b,y,x);
    y-=a/b*x;//较难理解
    return r;
    
    //int r = Extend_GCD(b,a%b,x,y);
    //t = x; x = y;
    //y = t-a/b*y;
    //return r; 更易理解
    
}
*/

//TODO:http://codeforces.com/problemset/problem/7/C
/*
#include<iostream>
using namespace std;
long long a,b,c;
long long x,y;
long long GCD(long long a,long long b,long long &x,long long &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=GCD(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b>>c)
    {
        long long d=GCD(a,b,x,y);
        //cout<<x<<" "<<y<<endl;
        if((-c)%d==0)
        {
            cout<<x*(-c/d)<<" "<<y*(-c/d)<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}
*/

//TODO:Magic Horse

//TODO:http://codeforces.com/problemset/problem/724/C
//Tmax=LCM(n,m)// 设t时刻终止 t=k1*n=k2*m t=最小公倍数
//设原坐标(a,b) 平面对称拓展后: 当2*x*n±a(横坐标)=2*y*m±b(纵坐标) 时点受到光照 这里求最小的x,y(最初相遇)
//  2xn-2ym=±a±b;
/*
#include<iostream>
using namespace std;
#define N 100010
long long n,m,k;
long long T;
long long x,y;
long long Extend_GCD(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long r=Extend_GCD(b,a%b,y,x);
    y-=a/b*x;//较难理解
    return r;
    
    //int r = Extend_GCD(b,a%b,x,y);
    //t = x; x = y;
    //y = t-a/b*y;
    //return r; 更易理解
}
long long equation(long long a, long long b, long long c, long long &x, long long &y)
{
    long long d=Extend_GCD(a,b,x,y);
    if(c%d) return -1;//不可整除 无整数解
    long long ran=b/d;
    x*=c/d;
    if(ran<0) ran=-ran;
    x=(x%ran+ran)%ran;
    return 0;
}
long long judge(int a,int b)
{
    long long temp_x,temp_y;
    if(equation(2*n,-2*m,-a+b,temp_x,temp_y)==-1)//-a+b??? -a-b??? 
        return T+1;
    long long temp=2*temp_x*n+a;
    if(temp<0||temp>T) return T+1;
    else return temp;
}
long long result(long long a,long long b)
{
    long long ans=T+1;
    ans=min(ans,judge(a,b));//枚举等式右边
    ans=min(ans,judge(a,-b));
    ans=min(ans,judge(-a,b));
    ans=min(ans,judge(-a,-b));
    if(ans==T+1) return -1;
    else return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    long long a,b;
    while(cin>>n>>m>>k)
    {
        T=1LL*n/Extend_GCD(n,m,a,b)*m;//时间上限
        for(int i=0;i<k;i++)
        {
            cin>>a>>b;
            cout<<result(a,b)<<endl;
        }
    }
}
//https://blog.csdn.net/danliwoo/article/details/52761839
//https://blog.csdn.net/a7f650ebd327889c/article/details/53606852
*/

//TODO:求解模线性方程
//TODO:取模运算https://baike.baidu.com/item/%E5%8F%96%E6%A8%A1%E8%BF%90%E7%AE%97/10739384?fr=aladdin
//TODO:Josephus问题
//模拟
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 10010
bool vis[N];
int num,m;
int f;
int Josephus(int num,int m)
{
    f=0;
    for(int i=1;i<=num;i++)
    {
        f=(f+m)%i;
    }
    return f+1;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>num>>m)
    {
        memset(vis,0,sizeof(vis));
        int number=0;
        int exit_cnt=0;
        for(int i=1;i<=num;i++)
        {
            if(!vis[i])//未退出
            {
                number++;
                if(number%m==0)
                {
                    exit_cnt++;
                    vis[i]=1;
                    cout<<"exit:"<<i<<endl;
                }
            }
            if(exit_cnt==num)
            {
                cout<<"last:"<<i<<endl;
                break;
            }
            else if(i==num) i=0;
        }
        cout<<"math:"<<Josephus(num,m)<<endl;
    }
}
*/
//队列模拟  当出队元素计数为m时 直接退出  非m时 重新加入队尾

//TODO:数的重排  k*10000 + (1234)
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string number;
int a[4] = {1, 2, 3, 4};
bool vis[4];
long long back;
bool finish;
int target;
void DFS(int depth, int cur)
{
    if (depth >= 4)
    {
        if(cur%7==target)
        {
             cout <<"back%7:"<< cur % 7 << endl;
            back = cur;
            finish = true;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            DFS(depth + 1, 10 * cur + a[i]);
            if (finish)
                return;
            vis[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> number)
    {
        for(int i=0;i<4;i++) 
        {
            number.erase(number.find(to_string(a[i])),1);
        }
        target=(7-(stoll(number)*10000)%7);
        finish = false;
        memset(vis, 0, sizeof(vis));
        DFS(0, 0);
        cout<<"front%7:"<<(stoll(number)*10000)%7<<endl;
        cout<<"res:"<<number<<back<<endl;
        cout<<"res%7:"<<(stoll(number)*10000+back)%7<<endl;
    }
}
*/

//TODO:同余
//TODO:模线性方程
/*
题目
已知a,b,n，求x，使得ax=b(mod n).

算法说明
令d=gcd(a,n),如果d|b,则存在d个解。否则无解。 
用扩展欧几里得算法求出 ax+ny=d 的一组解（x0,y0).x0即为ax=b(mod n)的一个解。d个解满足x=x0+i*n/d,i取值范围是[0,d-1].

推导过程
由同余方程的定义，可知ax-ny=b. 
将b拆分为gcd(a,n)*t. 
若gcd(a,n)不能整除b，因为ax0+ny0=gcd(a,n).等式左边有因子gcd(a,n),而等式右边没有，所以此时是无解的。 
设x0，y0满足ax0+ny0=gcd(a,n). 
等式两边同乘以t，得 
a(x0*t)-n(-y0*t)=gcd(a,n)*t. 
即x0*t为ax=b(mod n)的一个解。

通解证明： 
设（x1,y1)和(x2,y2)是ax-ny=b的解。 
ax1 - ny1 = b; …(1) 
ax2 - ny2 = b; …(2) 
(2) - (1),得： 
a(x2 - x1) = n(y2 - y1) 
等式两边同时除以d,d=gcd(a,n).得： 
a/d * (x2 - x1) = n/d * (y2 - y1). 
因为 a/d 和 n/d互质了，所以(x2 - x1)一定是 n/d 的倍数，即 
x2 - x1 = n/d * i.

i的最大取值为d - 1.因为如果 i = d 的话，x2 - x1 = n. 
ax2 = b(mod n).即 
a(x1 + n) = b(mod n)， 
ax1 + a*n = b(mod n). 
x2和x1是模n下的同一个解。所以i的取值范围是[0,d-1].
--------------------- 
作者：EnjoyingAC 
来源：CSDN 
原文：https://blog.csdn.net/qq_37685156/article/details/79750628 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
/*
#include<iostream>
using namespace std;
int a,b,m;
int x,y;
int Extend_GCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int r=Extend_GCD(b,a%b,y,x);
    y-=a/b*x;//较难理解
    return r;
    
    //int r = Extend_GCD(b,a%b,x,y);
    //t = x; x = y;
    //y = t-a/b*y;
    //return r; 更易理解
    
}
int main()
{
    ios::sync_with_stdio(false);
    //ax同余b mod(m)
    //ax+my=b  aX+mY=GCD(a,m)   *系数b/GCD
    while(cin>>a>>b>>m)
    {
        int d=Extend_GCD(a,m,x,y);
        if(b%d==0)
        {
            for(int i=0;i<d;i++)
            {
                cout<<"x="<<(x*b/d+i*m/d)%m<<endl;
            }
        }
    }
}
*/

//TODO:求mod m 的 逆元
//ax≡1(mod  p)的解x称为a模p的逆元  当gcd(a,p)==1（即a，p互质）时，方程有唯一解，否则无解
//根据费马小定理 a*a(p-2)≡1（mod p）对于整数a，p，a关于p的逆元就是a^(p-2)
//快速幂 但注意这个定理要求a,p互质！
/*
#include<iostream>
using namespace std;
int a,m;
int x,y;
int Extend_GCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int r=Extend_GCD(b,a%b,y,x);
    y-=a/b*x;//较难理解
    return r;
    
    //int r = Extend_GCD(b,a%b,x,y);
    //t = x; x = y;
    //y = t-a/b*y;
    //return r; 更易理解
    
}
int main()
{
    //ax同余1(modm)   ax+my=1   x=x0*1/d=x0 唯一解
    while(cin>>a>>m)
    {
        int d=Extend_GCD(a,m,x,y);
        if(d==1)//只有GCD=1 才有逆元  
        {
            //解出x
            if(x<0) x+=m; //此时x为所求逆元
        }
    }
}
*/

/*
long long inv(long long a,long long m)
{
    while(a<0)
        a+=m;
    a%=m;//a<m
    return a==1?1:(m-m/a)*inv(m%a,m)%m;
}
*/
/*
https://www.cnblogs.com/rir1715/p/7748054.html
证明：

设x = p % a,y = p / a
于是有 x + y * a = p
(x + y * a) % p = 0
移项得 x % p = (-y) * a % p
x * inv(a) % p = (-y) % p
inv(a) = (p - y) * inv(x) % p
于是 inv(a) = (p - p / a) * inv(p % a) % p

然后一直递归到1为止，因为1的逆元就是1
--------------------- 
作者：SethChai 
来源：CSDN 
原文：https://blog.csdn.net/a493823882/article/details/79612025 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
//应用 快速计算组合数

//TODO:http://codeforces.com/problemset/problem/963/A
/*
#include<iostream>
using namespace std;
#define mod 1000000009
#define N 100010
long long n,a,b,k;
int s[N];
long long quick_pow(long long a,long long b)
{
    if(b==0) return 1;
    long long temp=quick_pow(a,b>>1);
    if(b&1)
    {
        return a%mod*temp%mod*temp%mod;
    }
    else return temp%mod*temp%mod;//快速幂
}
long long inv(long long a,long long m) //逆元
{
    return a==1?1:(m-m/a)*inv(m%a,m)%m;
}
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    while(cin>>n>>a>>b>>k)
    {
        for(int i=0;i<k;i++) // 0...k-1
        {
            cin>>ch;
            if(ch=='+') s[i]=1;
            else s[i]=-1;
        }
        long long a1=0;
        for(int i=0;i<k;i++)
        {
            a1=((a1+s[i]*quick_pow(a,n-i)*quick_pow(b,i))%mod+mod)%mod;//确保a1为正
            //a1=(a1+s[i]*quick_pow(a,n-i)*quick_pow(b,i))%mod;
        }
        //首项a1得到
        //项数为(n+1)/k
        //公比为q=(b/a)^k  注意公比不要写错
        long long num=(n+1)/k;
        long long q=quick_pow(b,k)%mod*quick_pow(inv(a,mod),k)%mod;
        if(q==1)//公比为1
        {
            cout<<num*a1%mod<<endl;
        }
        else
        {
            long long sum=((a1*(quick_pow(q,num)-1)%mod*inv(q-1,mod))%mod+mod)%mod;//保证sums为正
            cout<<sum<<endl;
        }
    }
}
*/
/*
2 2 3 3
+-+
4 1 5 1
-
ans:7
ans:999999228
*/

//TODO:http://codeforces.com/problemset/problem/487/C
//如果1 在中间出现两个相同的MOD值
//如果7 在中间在其之后的MOD值均为0
//合数(非素数)无解 在一对因数之后的MOD值为0
//对于素数的平方  只有4有解 n=m^2 reason: (m*2*m)%n=0  2m<=m^2
/*
#include<iostream>
using namespace std;
#define N 100010
//ax同余1(modm)
long long inv(long long a,long long m)
{
    //while(a>m) a-=m;
    return a==1?1:(m-m/a)*inv(m%a,m)%m;
}

int n;
int ans[N];
bool judge(int num)
{
    if(num==2) return true;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(!judge(n)&&n!=4)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(n==4)
        {
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<3<<endl;
            cout<<2<<endl;
            cout<<4<<endl;
            continue;
        }
        ans[1]=1;
        ans[n]=n;
        for(int i=2;i<=n-1;i++)
        {
            ans[i]=(i*inv(i-1,n))%n;
        }
        //逆元构造 1 2 3 4 5.....0  用逆元消除前缀乘积影响
        //1* 2*inv(1) *  3*inv(2) 符合上述构造
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<endl;
        }
    }
}
*/

//TODO:http://codeforces.com/problemset/problem/710/D
//TODO:模线性方程
//x = a1k + b1 = a2l + b2
//a1k-a2l=b2-b1   a1X+a2Y=b2-b1
//x同余b1 (mod a1)
//x同余b2 (mod a2)
//求解模线性方程组->中国剩余定理

#include<iostream>
using namespace std;
long long k,l;
long long Extend_GCD(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long r=Extend_GCD(b,a%b,y,x);
    y-=a/b*x;//较难理解
    return r;
    
    //int r = Extend_GCD(b,a%b,x,y);
    //t = x; x = y;
    //y = t-a/b*y;
    //return r; 更易理解
    
}
void minial(long long& x, long long& y,long long k1, long long k2){
    //cout<<x<<"  "<<y<<endl;
    long long t = x/k1;
    x -= t*k1, y += t*k2;
    if( x < 0){
    x += k1, y-=k2;
    }
    if( y > 0){
    t = y/k2;
    x += t*k1, y -= t*k2;
    if( y > 0){
    x += k1, y-=k2;
    }  
    }
    //cout<<x<<"  "<<y<<endl;
}
//https://blog.csdn.net/ACM__dongsheng/article/details/66473029 

long long a1,b1,a2,b2,L,R;
long long for_ans(long long X,long long lcm)
{
    //cout<<"CUR:"<<X<<"  LCM:"<<lcm<<endl;
    if(X>R) return 0;
    /*
    long long ans=0;
    if(R>=X) ans+=(R-X)/lcm+1;
    if(L-1>=X) ans-=(L-1-X)/lcm+1;
    */
    if(X<L) return (R-X)/lcm-(L-1-X)/lcm;
    else return (R-X)/lcm+1;
}
int main()
{
    ios::sync_with_stdio(false);
    //x = a1k + b1 = a2l + b2
    //a1k-a2l=b2-b1   a1X+a2Y=b2-b1
    while(cin>>a1>>b1>>a2>>b2>>L>>R)
    {
        long long d=Extend_GCD(a1,a2,k,l);
        //cout<<"d:"<<d<<endl;
        long long c=b2-b1;
        if(c%d==0)//有解
        {
            //K=k*(c/d)+t*(B/d)  L=l*(c/d)-t*(A/d)  t为任何整数 k>=0 l<=0 
            k=k*c/d;
            l=l*c/d;
            minial(k,l,a2/d,a1/d);//后两个参数为B/d A/d
            //X增值为LCM(a1,a2)
            long long lcm=a1/d*a2;
            long long X=a1*k+b1;
            cout<<for_ans(X,lcm)<<endl;
        }
        else cout<<0<<endl;//无解
    }
}
/*  
改了一晚上居然是因为编译器没有重新生成任务
51 -1981067352 71 -414801558 -737219217 1160601982
-414801558
3621
435075
135 -1526277729 32 1308747737 895574 1593602399
1308751161
4320
65938
*/

//中国剩余定理
/*
#include<iostream>
using namespace std;
#define N 105
long long inv(long long a,long long m)
{
    while(a>m) a-=m;//TODO:注意这里的语句 使a<m
    return a==1?1:((m-m/a)*inv(m%a,m))%m;
}
int b[N];//={0,2,3,2};
int m[N];//={0,3,5,7};
int n;
long long Chinese_Remainder(int b[],int m[],int n)
{
    long long ret=0;
    long long M=1;
    for(int i=1;i<=n;i++)
    {
        M*=m[i];
    }
    for(int i=1;i<=n;i++)
    {
        int temp=M/m[i];
        ret=((ret+b[i]*temp*inv(temp,m[i]))%M+M)%M;//确保正数
    }
    return ret;
}
long long GCD(long long a,long long b)
{
    if(b==0) return a;
    else return GCD(b,a%b);
}
long long Extend_Chinese_Remainder(int c[],int m[],int n)
{
    long long ret;
    long long m1,m2,c1,c2;
    for(int i=2;i<=n;i++)
    {
        m1=m[i-1];
        m2=m[i];
        c1=c[i-1];
        c2=c[i];
        int d=GCD(m1,m2);
        if((c2-c1)%d!=0)
        {
            //无解
            break;
        }
        else
        {
            m[i]=m1/d*m2;
            c[i]=(inv(m1/d,m2/d)*(c2-c1)/d)%(m2/d)*m1+c1;
            c[i]=(c[i]%m[i]+m[i])%m[i];
        }
    }
    return c[n];
}
//https://www.cnblogs.com/zwfymqz/p/8425731.html
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>m[i]>>b[i];
        }
        //cout<<Chinese_Remainder(b,m,n)<<endl;
        cout<<Extend_Chinese_Remainder(b,m,n)<<endl;
    }
}
*/

//TODO:模幂运算与欧拉定理
/*
int quick_pow_mod(int a,int b,int c)
{
	int ans=1;   //记录结果
	a=a%c;   //预处理，使得a处于c的数据范围之下
	while(b!=0)
	{
		if(b&1) ans=(ans*a)%c;   //如果b的二进制位不是0，那么我们的结果是要参与运算的
		b>>=1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位
		a=(a*a)%c;   //不断的加倍
	}
	return ans;
}
*/
//https://blog.csdn.net/ltyqljhwcm/article/details/53043646

//对于给定的一个素数p: φ(p)=p-1 那么容易证明φ(n)=p^k-p^(k-1)

//已知少于或等于p^k的正整数的个数为p^k-1,其中和p^k不互质的正整数有{ p×1,p×2,...,p×(p^(k-1)-1)}，共计p^(k-1)-1个

//故: φ(n) = p^k-1-(p^(k-1)-1)=p^k-p^(k-1)。
/*
int euler(int x){
    int res = x;
    for(int i=2; i*i<=x; i++)
        if(x % i == 0){
             res = res / i * (i - 1);
             while(x % i == 0) x /= i;
         }
    if(x > 1) res = res / x * (x - 1);
    return res;
}
*/
//https://www.cnblogs.com/flipped/p/5324598.html
//TODO:Pollard rho  基于Floyd 的环检测
/*
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 100010
using namespace std;
long long fac[N];
int cnt;
long long GCD(long long a,long long b)
{
    return b==0?a:GCD(b,a%b);
}
long long mod(long long a,long long b,long long c)
{
    long long ret=0;
    long long temp=a;
    while(b)
    {
        if(b&1)
        {
            ret=(ret+temp)%c;
        }
        temp=(temp*2)%c;
        b>>=1;
    }
    return ret%c;
}
long long f(long long num,long long n ,int k)
{
    return (mod(num,num,n)+k)%n;
}
long long Pollard_rho(long long n,long long k)
{
   long long a,b;
   a=b=2;
   long long p=1;
   while(p==1)
   {
       a=f(a,n,k);
       b=f(f(b,n,k),n,k);
       p=GCD(abs(b-a),n);
       if(p>1&&p<n) return p;
       else if(p==n) return 0;
   }
   return -1;
}
long long all_factor(long long n,long long fac[])//质因子分解
{
    long long p;
    cout<<"cur n:"<<n<<endl;
    p=Pollard_rho(n,1);
    if(p==0) 
    {
        fac[cnt++]=n;//n为素数
    }
    else if(p>0)
    {
        all_factor(p,fac);
        all_factor(n/p,fac);
    }
    else
    {
        all_factor(n,fac); //算法失败 重新开始
    }
}
int main()
{
    ios::sync_with_stdio(false);
    
    // long long a,b,c;
    // while(cin>>a>>b>>c)
    // {
    //    cout<<"mod:"<<mod(a,b,c)<<endl;
    // }
    
    
    long long number;
    while(cin>>number)
    {
        cnt=0;
        all_factor(number,fac);
        for(int i=0;i<cnt;i++)
        {
            cout<<fac[i]<<" ";
        }
        cout<<endl;
    }
    
}
*/
//https://www.cnblogs.com/kuangbin/archive/2012/08/19/2646396.html
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;


//****************************************************************
// Miller_Rabin 算法进行素数测试
//速度快，而且可以判断 <2^63的数
//****************************************************************
const int S=20;//随机算法判定次数，S越大，判错概率越小


//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
    a%=c;
    b%=c;
    long long ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    long long tmp=x;
    long long ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}





//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
    long long ret=pow_mod(a,x,n);
    long long last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;

bool Miller_Rabin(long long n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    long long x=n-1;
    long long t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}


//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
long long factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

long long gcd(long long a,long long b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

long long Pollard_rho(long long x,long long c)
{
    long long i=1,k=2;
    long long x0=rand()%x;
    long long y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(long long n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

int main()
{
    //srand(time(NULL));//需要time.h头文件//POJ上G++不能加这句话
    long long n;
    while(scanf("%I64d",&n)!=EOF)
    {
        tol=0;
        findfac(n);
        for(int i=0;i<tol;i++)printf("%I64d ",factor[i]);
        printf("\n");
        if(Miller_Rabin(n))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
*/