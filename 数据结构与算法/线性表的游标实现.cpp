#include <iostream>
using namespace std;
#define MAX 10
typedef int elementtype;
//多个线性表共用一个存储池
//注意维护空闲池available的作用：空闲元素
struct node
{
    elementtype element;
    int next; //游标
};
node space[MAX]; //存储池
typedef int Position;
typedef int Cursor;
Cursor available;
void init() //初始化  维护available
{
    available = 0; //空闲池头元素为 0
    for (int i = 0; i < MAX - 1; i++)
    {
        space[i].next = i + 1; //连接所有元素
    }
    space[MAX - 1].next = -1; //终止标记
}
//可用空间的分配和回收，插入与删除元素
Cursor get_node() //从空闲池中获取空闲元素
{
    Cursor ans = space[available].next; //available为头结点下标
    if (ans != -1)                      //避免越界 ans=-1 无可用空闲元素
        space[available].next = space[ans].next;
    return ans;
}
void put_node(Cursor x) //回收元素至空闲池首部
{
    space[x].next = space[available].next; //连接空闲池
    space[available].next = x;             //设置为首部元素
}
//在位置p后加入一个值为x的元素
void Insert(Position p, elementtype x)
{
    //从空闲池中取出
    Cursor q = get_node();
    if (q != -1) //有可用元素 q=-1 无可用元素
    {
        space[q].element = x; //赋值
        space[q].next = space[p].next;
        space[p].next = q;
    }
}
//删除位置p后的结点元素
void Delete(Position p)
{
    Position q = space[p].next;
    if (q != -1)
    {
        space[p].next = space[q].next;
        put_node(q);
    }
}
int main()
{
    system("pause");
}