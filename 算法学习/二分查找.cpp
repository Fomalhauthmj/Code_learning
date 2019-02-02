#include<iostream>
#include<algorithm>
using namespace std;
int a[]={1,2,3,5,5,5,7,8,9};
// int search(int key)
// {
//     int low=0;
//     int high=8;
//     int mid;    
//     while(low<=high)
//     {
//         mid=(low+high)/2;
//         if(a[mid]==key) return mid;
//         else if(a[mid]<key)
//         {
//             low=mid+1;
//         }
//         else if(a[mid]>key)
//         {
//             high=mid-1;
//         }
//     }
//     return -1;
// }
int search(int key,int low,int high)
{
    int mid=(low+high)>>1;
    if(a[mid]==key) return mid;
    else if(a[mid]<key)
    {
        return search(key,mid+1,high);
    }
    else if(a[mid]>key)
    {
        return search(key,low,mid-1);
    }
}
int main()
{
    int key;
    while(cin>>key)
    {
        //cout<<search(key,0,8)<<endl;;
        //binary_search()
        //cout<<*lower_bound(a,a+9,key)<<endl;
        //cout<<*upper_bound(a,a+9,key)<<endl;
        cout<<*(equal_range(a,a+9,key).first)<<" "<<*(equal_range(a,a+9,key).second)<<endl;
    }
}