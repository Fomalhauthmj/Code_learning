//C++
#include<string>
#include<iostream>
#include<memory.h>
using namespace std;//合并排序
//合并两部分有序数组time:O(n)
template<typename T>
void Merge(T  *arry,int start,int p,int end)
{
    int lsize=p-start,rsize=end-p;//两个数组的大小
    T * l=new T[lsize],*r=new T[rsize];//要合并的两个数组
    memcpy(l,arry + start,sizeof(T)*lsize);
    memcpy(r,arry + p,sizeof(T)*rsize);//将要合并的数组复制
    int lnow=0,rnow=0,i;//未合并的数字的位置
    for(i=0;lnow<lsize&&rnow<rsize;i++)
    {
        if(l[lnow]>r[rnow])//取较大的数
        {
            arry[start+i]=l[lnow];
            lnow++;
        }
        else
        {
            arry[start+i]=r[rnow];
            rnow++;
        }
    }
    if(lnow==lsize&&rnow!=rsize)//其中一个数组合并完以后，复制剩下的数据
    {
        memcpy(arry+start+i,r+rnow,sizeof(T)*(rsize-rnow));
    }
    else if(rnow==rsize&&lnow!=lsize)
    {
        memcpy(arry+start+i,l+lnow,sizeof(T)*(lsize-lnow));
    }
    delete l;
    delete r;//清理内存
    //return ;
}//排序函数time:O(nlgn)
template<typename T>
void MergeSort(T *arry,int start,int end)
{
    if(end-start > 1)//当元素个数为1时直接返回
    {
        int p=(start + end)/2;//切割数组
        MergeSort(arry,start,p);
        MergeSort(arry,p,end);//分别排序
        Merge(arry,start,p,end);//合并数组
    }
}
int main()
{
    int arr[10]={7,3,4,7,10,9,1,5,3,7};    
    MergeSort(arr,0,10);//左闭右开
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
