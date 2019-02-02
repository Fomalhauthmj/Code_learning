#include<iostream>
#include<algorithm>
using namespace std;
int a[4];
int b[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int casenum=1;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3])
    {
        if(a[0]+a[1]+a[2]+a[3]==0) break;
        sort(a,a+4);//排序
        if(casenum++!=1) cout<<endl;
        do
        {
            if(a[0]==0) continue;
            for(int i=0;i<4;i++) 
            {
                b[i]=a[i];
            }//将当前结果复制到b
            if(prev_permutation(b,b+4)&&b[0]!=0)//b之前的序列
            {
                if(b[0]==a[0])  cout<<" ";
                else//不同行
                {
                    cout<<endl;
                }
            }
            for(int i=0;i<4;i++)
            {
                cout<<a[i];
            }//输出当前序列
            
        }while(next_permutation(a,a+4));
        cout<<endl; 
    }
}