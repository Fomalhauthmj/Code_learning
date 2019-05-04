#include<iostream>
#include<time.h>
using namespace std;
int partition(int a[],int left,int right)
{
    
    int k=left+rand()%(right-left+1);
    swap(a[k],a[left]);
    int key=a[left];
    int i=left;
    int j=right+1;
    while(1)
    {
        while(a[++i]<key);
        while(a[--j]>key);
        if(i>j) break;
        swap(a[i],a[j]);
    }
    a[left]=a[j];
    a[j]=key;
    return j;
}
void qSort(int a[],int left,int right)
{
    int m;
    if(left>=right) return;
    m=partition(a,left,right);
    qSort(a,left,m-1);
    qSort(a,m+1,right);
}
int qSort(int a[],int left,int right,int k)
{
    int m;
    if(left>=right) return a[left];
    m=partition(a,left,right);
    if(m==k-1) return a[m];
    else if(m<k-1)  qSort(a,m+1,right,k);
    else if(m>k-1)qSort(a,left,m-1,k-m-1);
}//找出第k位元素
int main()
{
    int a[]={1,3,8,-1,2};
    qSort(a,0,4);
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<qSort(a,0,4,1)<<endl;
    int left=0;int right=4;
    system("pause");
    return 0; 
}