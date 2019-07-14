/*
 * File Created: Sunday, 14th July 2019 10:48:37 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 10:49:33 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
using namespace std;
#define ll long long
const int N=1e5+50;
int n;
ll a[N];
ll stack[N],width[N];
int top;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        a[n]=0;
        top=0;
        ll ans=0;
        for(int i=0;i<=n;i++)
        {
            if(a[i]>stack[top])
            {
                stack[++top]=a[i];
                width[top]=1;
            }
            else
            {
                int width_sum=0;
                while(a[i]<stack[top])
                {
                    width_sum+=width[top];
                    ans=max(ans,width_sum*stack[top]);
                    top--;
                }
                stack[++top]=a[i],width[top]=width_sum+1;
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}