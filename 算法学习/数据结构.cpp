//TODO:线段树

//https://www.cnblogs.com/AC-King/p/7789013.html

//TODO:http://acm.hdu.edu.cn/showproblem.php?pid=1166
/*
#include <iostream>
#include <string>
using namespace std;
#define N 50010
int tree[N << 2]; //4xN
int n;
int a[N];
void push_up(int rt) //向上更新
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void build(int left, int right, int rt) //左端点，右端点，根结点
{
    if (left == right)
    {
        tree[rt] = a[left];
        return;
    }

    int mid = (left + right) >> 1;
    build(left, mid, rt << 1);
    build(mid + 1, right, rt << 1 | 1);

    push_up(rt);
}
void update(int left, int right, int rt, int k, int v) //单点更新 第k个结点+v值
{
    if(left==right&&left==k)
    {
        tree[rt]+=v;
        return;
    }
    int mid = (left + right) >> 1;
    if (mid>=k) update(left,mid,rt<<1,k,v);
    else if(mid<k) update(mid+1,right,rt<<1|1,k,v);

    push_up(rt);
}
int query(int start,int end,int left,int right,int rt)//start end 为查询区间左右结点
{
    if(left==start&&right==end)
    {
        return tree[rt];
    }
    int mid=(left+right)>>1;
    int ans=0;
    if(end<=mid) ans+=query(start,end,left,mid,rt<<1);//仅在左区间
    else if(start>mid) ans+=query(start,end,mid+1,right,rt<<1|1);//仅在右区间
    else//跨区间
    {
        ans+=query(start,mid,left,mid,rt<<1);
        ans+=query(mid+1,end,mid+1,right,rt<<1|1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    string str;
    int k, v;
    int start, end;
    int t;
    cin >> t;
    int casenum=1;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, n, 1);
        cout<<"Case "<<casenum++<<":"<<endl;
        while (cin >> str)
        {
            if (str == "Query")
            {
                cin >> start >> end;
                cout<<query(start,end,1,n,1)<<endl;
            }
            else if (str == "Add")
            {
                cin >> k >> v;
                update(1, n, 1, k, v);
            }
            else if (str == "Sub")
            {
                cin >> k >> v;
                update(1, n, 1, k, -v);
            }
            else if (str == "End")
            {
                break;
            }
        }
    }
}
*/
//TODO:http://codeforces.com/problemset/problem/91/B
/*
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
int n;
int a[N];
int tree[N<<2];
int ret[N];
void push_up(int rt) //向上更新
{
    tree[rt] = min(tree[rt << 1],tree[rt << 1 | 1]);
}
void build(int left, int right, int rt) //左端点，右端点，根结点
{
    if (left == right)
    {
        tree[rt] = a[left];
        return;
    }

    int mid = (left + right) >> 1;
    build(left, mid, rt << 1);
    build(mid + 1, right, rt << 1 | 1);

    push_up(rt);
}
void query(int k,int left,int right,int rt)//k 为查询结点
{
    if(left==right&&a[left]<a[k])
    {
        ret[k]=left-k-1;//计算两者中间隔了多少元素
        return;
    }
    int mid=(left+right)>>1;
    //优先向右区间考虑
    if(a[k]>tree[rt<<1|1])
    {
        query(k,mid+1,right,rt<<1|1);
    }
    else if(a[k]>tree[rt<<1])//向左区间考虑
    {
        query(k,left,mid,rt<<1);
    }
    else 
    {
        ret[k]=-1;//无结果
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            query(i,1,n,1);
            if(ret[i]<0) ret[i]=-1;
            if(i!=n) cout<<ret[i]<<" ";
            else cout<<ret[i]<<endl;
        }
    }
}
*/
//TODO:http://codeforces.com/problemset/problem/827/A
//TODO:线段信息为 区间范围内元素是否已经确定

/*
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define N 100010
int n;
string t;
int k;
int ans_len;
char str[20*N];
int chars[80*N];
void push_up(int rt)
{
    chars[rt]=chars[rt<<1]+chars[rt<<1|1];
}
void update(int L,int R,int left,int right,int rt)
{
     if(chars[rt]>=right-left+1) return;
    //cout<<"L:"<<L<<" t:"<<t<<" left:"<<left<<" right"<<right<<endl;
    if(left==right)
    {
        chars[rt]=1;
        str[left]=t[left-L];
        return;
    }
    if(L>right||R<left) return;
    int mid=(left+right)>>1;
    if(mid>=R) update(L,R,left,mid,rt<<1);
    else if(mid<L) update(L,R,mid+1,right,rt<<1|1);
    else
    {
        update(L,R,left,mid,rt<<1);
        update(L,R,mid+1,right,rt<<1|1);
    }
    push_up(rt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pos;
    int endpos;
    while(cin>>n)
    {
        ans_len=0;
        for(int i=1;i<2000010;i++) str[i]='a';
        memset(chars,0,sizeof(chars));
        for(int i=1;i<=n;i++)
        {
            cin>>t>>k;
            for(int j=1;j<=k;j++) 
            {
                cin>>pos;
                endpos=pos+t.length()-1;
                update(pos,endpos,1,2000010,1);//注意不要将t传入参数 TLE
                if(j==k)
                {
                    if(endpos>ans_len) ans_len=endpos;
                }
            }
        }
        //字符串长度=ans_len
        //cout<<ans_len<<endl;
        for(int i=1;i<=ans_len;i++) cout<<str[i];
        cout<<endl;
    }
}
*/

//TODO:http://codeforces.com/problemset/problem/19/D
//以横坐标为区间 区间信息为相同横坐标下最大的纵坐标值 同时保存同横坐标下所有纵坐标值
//同时进行离散化处理 取x值 排序去重
/*
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 200010
int n, m;
struct node
{
    int x, y;
    int type;
};
node ps[N];
int xi[N];
int max_y[N << 2];
set<int> yi[N];
void push_up(int rt)
{
    if(max_y[rt<<1]>max_y[rt<<1|1])
    {
        max_y[rt]=max_y[rt<<1];
    }
    else max_y[rt]=max_y[rt<<1|1];
}
void update(int k,int v,int left,int right,int rt)
{
    if(left==right)
    {
        if(yi[left].size()!=0)  max_y[rt]=*(--yi[left].end()); //注意这里的处理
        else max_y[rt]=0;
        return;
    }
    int mid=(left+right)>>1;
    if(mid<k)
    {
        update(k,v,mid+1,right,rt<<1|1);
    }
    else update(k,v,left,mid,rt<<1);
    push_up(rt);
}
int query(int k,int v,int left,int right,int rt)
{
    if(max_y[rt]<=v||right<k) return -1;
    if(left==right) return left;
    int mid=(left+right)>>1;
    if(mid<k) return query(k,v,mid+1,right,rt<<1|1);
    else
    {
        int temp=query(k,v,left,mid,rt<<1);
        if(temp==-1)
        {
            return query(k,v,mid+1,right,rt<<1|1);
        }
        return temp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "add")
        {
            ps[i].type = 0;
        }
        else if (str == "remove")
        {
            ps[i].type = 1;
        }
        else
        {
            ps[i].type = 2;
        }
        cin >> ps[i].x >> ps[i].y;
        xi[i] = ps[i].x;
    }
    sort(xi, xi + n);
    m = unique(xi, xi + n) - xi;
    int k,v;
    memset(max_y, 0, sizeof(max_y));
    for (int i = 0; i < n; i++)
    {
        k = lower_bound(xi, xi + m, ps[i].x) - xi;
        v=ps[i].y;
        if (ps[i].type == 0) //add
        {
            yi[k].insert(v);
            update(k,v,0, m - 1, 1);
        }
        else if (ps[i].type == 1) //remove
        {
            yi[k].erase(v);
            update(k,v,0, m - 1, 1);
        }
        else //query
        {
            if (k >= m - 1 || k < 0)
            {
                cout << -1 << endl;
                continue;
            }
            int target = query(k + 1,v, 0, m - 1, 1);
            if (target == -1)
            {
                cout << -1 << endl;
                continue;
            }
            else
                cout << xi[target] << " " << *yi[target].upper_bound(v) << endl;
        }
    }
    //system("pause");
}
*/
//
//TODO:区间更新
/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 100010
int tree[N<<2];//存储区间和
int a[N];
int change[N<<2]; //lazy标记
int n;
void push_up(int rt)
{
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void push_down(int rt,int ls,int rs)
{
    change[rt<<1]+=change[rt];
    change[rt<<1|1]+=change[rt];
    tree[rt<<1]+=change[rt]*ls;
    tree[rt<<1|1]+=change[rt]*rs;
    change[rt]=0;
}
void build(int left,int right,int rt)
{
    if(left==right)
    {
        tree[rt]=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(left,mid,rt<<1);
    build(mid+1,right,rt<<1|1);
    push_up(rt);
}
void update(int L,int R,int v,int left,int right,int rt)
{
    if(L<=left&&right<=R)
    {
        tree[rt]+=(right-left+1)*v;
        change[rt]+=v;
        return;
    }
    int mid=(left+right)>>1;
    //if(change[rt]!=0) push_down(rt,mid-left+1,right-mid);
    if(mid<L) update(L,R,v,mid+1,right,rt<<1|1);
    else if(mid>=R) update(L,R,v,left,mid,rt<<1);
    else
    {
        update(L,R,v,left,mid,rt<<1);
        update(L,R,v,mid+1,right,rt<<1|1);
    }
    push_up(rt);
}
int query(int L,int R,int left,int right,int rt)
{
    if(L<=left&&right<=R)
    {
        return tree[rt];
    }
    int mid=(left+right)>>1;
    if(change[rt]!=0) push_down(rt,mid-left+1,right-mid);
    int ans=0;
    if(mid<L) ans=query(L,R,mid+1,right,rt<<1|1);
    else if(mid>=R) ans=query(L,R,left,mid,rt<<1);
    else
    {
        ans=query(L,R,left,mid,rt<<1);
        ans+=query(L,R,mid+1,right,rt<<1|1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A,B,C;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,n,1);
        cout<<"build finish!"<<endl;
        cin>>A>>B>>C;
        update(A,B,C,1,n,1);
        cin>>A>>B;
        cout<<query(A,B,1,n,1)<<endl;
    }
}
*/
//TODO:http://codeforces.com/problemset/problem/52/C
/*
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
#define inf 0x3f3f3f3f3f
int n,m;
long long tree[N<<2];
long long inc[N<<2];
long long a[N];
int op[3];
long long answer;
int split_str(string str)
{
    int pos=str.find(' ',0);
    int cnt=0;
    op[cnt++]=stoi(str.substr(0,pos));
    int temp=str.find(' ',pos+1);
    if(temp!=string::npos)
    {
        op[cnt++]=stoi(str.substr(pos+1,temp));
        op[cnt++]=stoi(str.substr(temp));
    }
    else
    {
        op[cnt++]=stoi(str.substr(pos));
    }
    return cnt;
}
void push_up(int rt)
{
   tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
void push_down(int rt)//TODO:update query 函数都需要下推
{
    inc[rt<<1]+=inc[rt];
    inc[rt<<1|1]+=inc[rt];
    tree[rt<<1]+=inc[rt];
    tree[rt<<1|1]+=inc[rt];
    inc[rt]=0;
}
void build(int left,int right,int rt)
{
    if(left==right)
    {
        tree[rt]=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(left,mid,rt<<1);
    build(mid+1,right,rt<<1|1);
    push_up(rt);
}
void update(int L,int R,int v,int left,int right,int rt)
{
    if(right<L||left>R) return;
    if(left>=L&&right<=R)
    {
        tree[rt]+=v;
        inc[rt]+=v;
        //cout<<"left:"<<left<<" right:"<<right<<" rt:"<<rt<<" tree:"<<tree[rt]<<endl;
        return;
    }
    int mid=(left+right)>>1;
    if(inc[rt]!=0) push_down(rt);
    if(mid<L)
    {
        update(L,R,v,mid+1,right,rt<<1|1);
    }
    else if(mid>=R)
    {
        update(L,R,v,left,mid,rt<<1);
    }
    else
    {
        update(L,R,v,left,mid,rt<<1);
        update(L,R,v,mid+1,right,rt<<1|1);
    }
    push_up(rt);
    //cout<<"left:"<<left<<" right:"<<right<<" rt:"<<rt<<" tree:"<<tree[rt]<<endl;
}
void query(int L,int R,int left,int right,int rt)
{
    if(right<L||left>R) return;
    if(L<=left&&right<=R)
    {
        answer=min(answer,tree[rt]);
        //cout<<"query "<<"left:"<<left<<" right:"<<right<<" rt:"<<rt<<" tree:"<<tree[rt]<<endl;
        return;
    }
    int mid=(left+right)>>1;
    if(inc[rt]!=0) push_down(rt);
    if(mid<L)
    {
        query(L,R,mid+1,right,rt<<1|1);
    }
    else if(mid>=R)
    {
        query(L,R,left,mid,rt<<1);
    }
    else
    {
        query(L,R,mid+1,right,rt<<1|1);
        query(L,R,left,mid,rt<<1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        build(0,n-1,1);
        cin>>m;
        getline(cin,str);
        memset(inc,0,sizeof(inc));
        for(int i=1;i<=m;i++)
        {
            answer=inf;
            getline(cin,str);
            //cout<<"str:"<<str<<endl;
            if(split_str(str)==2)
            {
                //query
                //cout<<op[0]<<" "<<op[1]<<endl;
                if(op[0]>op[1])
                {
                    query(op[0],n-1,0,n-1,1);
                    query(0,op[1],0,n-1,1);
                }
                else
                {
                    query(op[0],op[1],0,n-1,1);
                }
                cout<<answer<<endl;
            }
            else 
            {
                //inc
                //cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<endl;
                if(op[0]>op[1])
                {
                    update(op[0],n-1,op[2],0,n-1,1);
                    update(0,op[1],op[2],0,n-1,1);
                }
                else
                {
                    update(op[0],op[1],op[2],0,n-1,1);
                }
            }
        }
    }
}
*/

//TODO:http://codeforces.com/problemset/problem/138/C
//离线 离散化 
/*
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 100010
struct tree
{
    int a;
    int h;
    double li;
    double ri;
};
struct mr
{
    int b;
    int z;
};
tree trees[N];//树
mr mrs[N];//蘑菇
int n,m,cnt;
double p[N<<4];//点概率
int ps[N*5];
void build(int left,int right,int rt)//区间点概率设置为1
{
    p[rt]=1;
    if(left==right) return;
    int mid=(left+right)>>1;
    build(left,mid,rt<<1);
    build(mid+1,right,rt<<1|1);
}
void update(int L,int R,double val,int left,int right,int rt)
{
    if(right<L||left>R) return;
    if(left>=L&&right<=R)
    {
        p[rt]*=val;
        return;
    }
    int mid=(left+right)>>1;
    if(mid>=R) update(L,R,val,left,mid,rt<<1);
    else if(mid<L) update(L,R,val,mid+1,right,rt<<1|1);
    else
    {
        update(L,R,val,left,mid,rt<<1);
        update(L,R,val,mid+1,right,rt<<1|1);
    }
}
double query(int pos,int left,int right,int rt)
{
    if(left==right)
    {
        return p[rt];
    }
    int mid=(left+right)>>1;
    if(pos<=mid)
    {
        return p[rt]*query(pos,left,mid,rt<<1);
    }
    else return p[rt]*query(pos,mid+1,right,rt<<1|1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pa,pb;
    while(cin>>n>>m)
    {
        cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>trees[i].a>>trees[i].h>>pa>>pb;//注意这里pa pb是整数类型的读入 而不是浮点数 900+ms->300+ms
            trees[i].li=1-pa/100.0;//不向左倒
            trees[i].ri=1-pb/100.0;//不向右倒
            ps[cnt++]=trees[i].a-1;
            ps[cnt++]=trees[i].a+1;
            ps[cnt++]=trees[i].a+trees[i].h;
            ps[cnt++]=trees[i].a-trees[i].h;
            //可能位置加入坐标集
        }
        for(int i=0;i<m;i++)
        {
            cin>>mrs[i].b>>mrs[i].z;
            ps[cnt++]=mrs[i].b;
        }
        sort(ps,ps+cnt);//离散化
        cnt=unique(ps,ps+cnt)-ps;
        build(0,cnt,1);
        int lp1,lp2,rp1,rp2;
        for(int i=0;i<n;i++)
        {
            lp1=lower_bound(ps,ps+cnt,trees[i].a-trees[i].h)-ps;
            lp2=lower_bound(ps,ps+cnt,trees[i].a-1)-ps;
            rp1=lower_bound(ps,ps+cnt,trees[i].a+1)-ps;
            rp2=lower_bound(ps,ps+cnt,trees[i].a+trees[i].h)-ps;
            update(lp1,lp2,trees[i].li,0,cnt-1,1);//左区间更新
            update(rp1,rp2,trees[i].ri,0,cnt-1,1);//右区间更新
        }
        double ans=0;
        int k;
        for(int i=0;i<m;i++)
        {
            //单点查询 返回点概率值
            k=lower_bound(ps,ps+cnt,mrs[i].b)-ps;
            ans+=query(k,0,cnt-1,1)*mrs[i].z;
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}
*/

//TODO:http://codeforces.com/problemset/problem/527/C
/*
#include<iostream>
using namespace std;
#define N 200020
int w,h,n;
struct node
{
    //对于每个区间  00010 1描述为切割点
    int max,l_max,r_max;//最大连续0 左连续0 右连续0 
    int len;//节点长度
};
node trs_1[N<<2];//宽度
node trs_2[N<<2];//高度
void push_up(node *trs,int rt)
{
    trs[rt].max=max(max(trs[rt<<1].max,trs[rt<<1|1].max)
                    ,trs[rt<<1].r_max+trs[rt<<1|1].l_max);//左子区间 右子区间  左子区间右端+右子区间左端
    if(trs[rt<<1].max==trs[rt<<1].len)  //000+010
    {
        trs[rt].l_max=trs[rt<<1].len+trs[rt<<1|1].l_max;
    }
    else    trs[rt].l_max=trs[rt<<1].l_max;  //010+?
    if(trs[rt<<1|1].max==trs[rt<<1|1].len)// 010+000
    {
        trs[rt].r_max=trs[rt<<1|1].len+trs[rt<<1].r_max;
    }
    else trs[rt].r_max=trs[rt<<1|1].r_max;   //?+010
    trs[rt].len=trs[rt<<1].len+trs[rt<<1|1].len;
}
void build(node *trs,int left,int right,int rt)
{
    if(left==right)
    {
        trs[rt].l_max=trs[rt].r_max=trs[rt].max=trs[rt].len=1;
        return;
    }
    int mid=(left+right)>>1;
    build(trs,left,mid,rt<<1);
    build(trs,mid+1,right,rt<<1|1);
    push_up(trs,rt);
}
void update(node *trs,int pos,int left,int right,int rt)//切割点
{
    if(left==right)
    {
        trs[rt].max=trs[rt].l_max=trs[rt].r_max=0;//连续0 设为0
        return;
    }
    int mid=(left+right)>>1;
    if(pos>mid) update(trs,pos,mid+1,right,rt<<1|1);
    else update(trs,pos,left,mid,rt<<1);
    push_up(trs,rt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    int pos;
    while(cin>>w>>h>>n)
    {
        build(trs_1,1,w-1,1);//建立宽度线段树
        build(trs_2,1,h-1,1);//建立高度线段树
        for(int i=0;i<n;i++)
        {
            cin>>ch>>pos;
            if(ch=='H')//水平切割
            {
                update(trs_2,pos,1,h-1,1);
            }
            else//垂直切割
            {
                update(trs_1,pos,1,w-1,1);
            }
            //cout<<"cur max w:"<<trs_1[1].max+1<<endl;
            //cout<<"cur max h:"<<trs_2[1].max+1<<endl;
            long long ans=(long long)(trs_1[1].max+1)*(trs_2[1].max+1);//注意long long 强制转换
            cout<<ans<<endl;
        }
    }
}
*/