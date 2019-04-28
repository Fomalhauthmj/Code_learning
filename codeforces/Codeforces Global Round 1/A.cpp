#include<iostream>
using namespace std;
#define N 100010
int b, k;
//对于偶数进制而言 只判断最后一位的奇偶即可
//对于奇数进制而言 判断奇数的个数
int bit[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>b>>k)
    {
        int count = 0;
        for (int i = 0; i < k;i++)
        {
            cin >> bit[i];
            if(bit[i]&1)
                count++;
        }
        if(b&1)
        {
            if(count&1)
                cout << "odd" << endl;
            else
                cout << "even" << endl;
        }
        else
        {
            if(bit[k-1]&1)
                cout << "odd" << endl;
            else
                cout << "even" << endl;
        }
        
    }
}