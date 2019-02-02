//TODO:抽屉原理
//应用:从自然数中选取m+1个自然数 则至少有两个数差值为m的倍数
//m的余数为0....m-1 共m个 m+1>m 至少有两个数对m余数重复 则差值为m的倍数
//应用：1~2n中取n+1个正整数 则至少有两个数互质 因为相邻整数比i+1/i互质
//TODO:

//6个人中至少存在3个人相互认识或相互不认识 K6中边用蓝色和红色标记 则必定存在K3的三边颜色相同
// 132个球放入77个盒子 每个盒子至少放入一个球 则定有21个球放在相邻的某几个盒子里
//1<=S1<S2<S3...<S77<=132
//S1+21<S2+21<...S77+21<=153
//上面一共有154个数 范围为1~153 则必存在Sa+21=Sb

//给出n个数 选取若干数 使其和为n的倍数
//TODO:前缀和对n取余  0...n-1 有为0或有一对相等

//递归求全排列的方法
/*
    void test(int *a,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<=r;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(a[i],a[l]);
        test(a,l+1,r);
        swap(a[i],a[l]);//记得换回来 
    }
}
*/
//TODO:next_permutation()
//TODO:求圆排列 则固定第一个 求其余的线排列
/*
LL Lucas(LL a, LL b)
{
    if(a < mod && b < mod)
        return C(a, b);
    return
        C(a % mod, b % mod) * Lucas(a / mod, b / mod);
}
*/
// --------------------- 
// 作者：Elin_24 
// 来源：CSDN 
// 原文：https://blog.csdn.net/ArrowLLL/article/details/53064748 
// 版权声明：本文为博主原创文章，转载请附上博文链接！

//TODO:容斥
//TODO:错排问题

//TODO:母函数 指数型母函数
/*
void func(int n,int *a,int *b,int *ans)//n为种类数 a为各类的val  b为各类的数量 ans[i]存储val值为i的方案数/系数
{
    int *temp;//临时数组更新
    for(int i=0;i<n;i++) ans[a[i]]=1;
    for(int i=0;i<n;i++)//第i种
    {
        for(int j=0;j<b[i];j++)//当前种类个数
        {
            for(int k=0;k<MAX;k++)//当前val值
            {

            }
        }
        for(int j=0;j<MAX;j++)
        {
           //更新
           ans[j]=temp[j];
           temp[j]=0;
        }
    }
}
*/