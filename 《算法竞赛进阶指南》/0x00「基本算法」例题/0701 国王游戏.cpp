#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1010;
int n;
struct node
{
    int a, b;
    node(int aa, int bb) : a(aa), b(bb)
    {
    }
    node() {}
    bool operator<(const node &n) const
    {
        return a * b < n.a * n.b;
    }
};
node p[N];
#define MAXN 9999
#define DLEN 4
class BigNum
{
private:
    int a[10000]; //可以控制大数的位数
    int len;

public:
    BigNum()
    {
        len = 1;
        memset(a, 0, sizeof(a));
    }                                                //构造函数
    BigNum(const int);                               //将一个int类型的变量转化成大数
    BigNum(const BigNum &);                          //拷贝构造函数
    BigNum &operator=(const BigNum &);               //重载赋值运算符，大数之间进行赋值运算
    friend ostream &operator<<(ostream &, BigNum &); //重载输出运算符

    BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const int &) const;   //重载除法运算符，大数对一个整数进行相除运算

    bool operator>(const BigNum &T) const; //大数和另一个大数的大小比较
};
BigNum::BigNum(const int b) //将一个int类型的变量转化为大数
{
    int c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    while (d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const BigNum &T) : len(T.len) //拷贝构造函数
{
    int i;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = T.a[i];
}
BigNum &BigNum::operator=(const BigNum &n) //重载赋值运算符，大数之间赋值运算
{
    int i;
    len = n.len;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = n.a[i];
    return *this;
}
ostream &operator<<(ostream &out, BigNum &b) //重载输出运算符
{
    int i;
    cout << b.a[b.len - 1];
    for (i = b.len - 2; i >= 0; i--)
    {
        printf("%04d", b.a[i]);
    }
    return out;
}
BigNum BigNum::operator*(const BigNum &T) const //两个大数之间的相乘
{
    BigNum ret;
    int i, j, up;
    int temp, temp1;
    for (i = 0; i < len; i++)
    {
        up = 0;
        for (j = 0; j < T.len; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if (temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if (up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int &b) const //大数对一个整数进行相除运算
{
    BigNum ret;
    int i, down = 0;
    for (i = len - 1; i >= 0; i--)
    {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
bool BigNum::operator>(const BigNum &T) const //大数和另一个大数的大小比较
{
    int ln;
    if (len > T.len)
        return true;
    else if (len == T.len)
    {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if (ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    cin >> n;
    int a, b;
    for (int i = 0; i <= n; i++)
        cin >> a >> b, p[i] = node(a, b);
    sort(p + 1, p + n + 1);
    BigNum ans, pre, temp;
    pre = BigNum(p[0].a);
    ans = BigNum(0);
    for (int i = 1; i <= n; i++)
    {
        temp = pre / p[i].b;
        if (temp > ans)
            ans = temp;
        pre = BigNum(p[i].a) * pre;
    }
    cout << ans;
    //system("pause");
    return 0;
}