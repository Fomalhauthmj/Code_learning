#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define size 1010
struct component
{
    string type;
    string name;
    long long price;
    long long quality;
};
component C[size];
long long n,b;
bool judge(long long mid)
{
    long long temp=0;
    long long minprice;
    for(int i=0;i<n;)
    {
        int pos=-1;minprice=0x3f3f3f3f;
        int j;
        for(j=i;j<n&&C[i].type==C[j].type;j++)
        {
            if(minprice>C[j].price&&C[j].quality>=mid)
            {
                minprice=C[j].price;pos=j;
            }
        }
        if(pos==-1) return false;
        temp+=minprice;
        i=j;//?下一类型配件的第一个
    }
    if(temp>b) return false;
    return true;
}   
int main()
{
    ios::sync_with_stdio(false);
    int t;
    //scanf("%d",&t);
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        //scanf("%d%d",&n,&b);
        long long left=0x3f3f3f3f;
        long long right=-0x3f3f3f3f;
        for(int i=0;i<n;i++)
        {
            cin>>C[i].type>>C[i].name>>C[i].price>>C[i].quality;
            //scanf("%s %s %d %d",&C[i].type,&C[i].name,&C[i].price,&C[i].quality);
            left=min(left,C[i].quality);
            right=max(right,C[i].quality);
        }
        long long mid;
        while(left<=right)  //注意跳出条件
        {
            mid=(left+right)/2;
            if(judge(mid)==true) left=mid+1;
            else right=mid-1;
        }
        cout<<right<<endl;
        //printf("%d\n",left);
    }
}