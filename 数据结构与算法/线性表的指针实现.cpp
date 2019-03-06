#include <iostream>
using namespace std;
typedef int ElementType;
struct node
{
    ElementType element;
    node *next;
};
typedef node *Position;
typedef node *List;
//由于单向链表的特性 这里只对位置p之后进行增加删除操作
void Insert(ElementType ele, Position p)
{
    Position temp = p->next;
    p->next = new node;
    //如果空间分配成功，在位置p之后增加一个元素
    p->next->element = ele;
    p->next->next = temp;
}
void Delete(Position p)
{
    Position q;
    if (p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        delete q;
    }
    //p->next=null 若为末尾结点 则无法删除其后的一个元素
}
void disp(List l)
{
    Position p = l;
    while (p->next != NULL) //传入参数为首结点 对于其next结点判断是否为空
    {
        cout << p->next->element << " "; //不为空输出元素
        p = p->next;
    }
    cout << endl;
}
Position Locate(ElementType ele, List l)
{
    Position p = l;
    while (p->next != NULL) //遍历
    {
        if (p->next->element == ele)
            //if (p->element == ele)
            //TODO:注意这里两者的区别 返回位置区别
            //p->element返回在此值后一个的位置
            //p->next->element返回在此值前一个结点的位置
            //可能出现异常
            return p;
        else
            p = p->next;
    }
    return NULL;
}
//previous next
//删除所有元素的清空链表
void Delete_All(List l)
{
    while (l->next != NULL)
    {
        Delete(l);
    }
    //destroy delete l
}
void test()
{
    List l = new node;
    l->next = NULL; //make null
    //首结点无存放元素
    Insert(100, l);
    disp(l);
    Insert(25, l); //直接在队首插入元素 高效的插入
    disp(l);
    //Insert(99, Locate(25, l));
    //Delete(Locate(25,l));
    disp(l);
    Delete_All(l);
    disp(l);
}
int main()
{
    test();
    system("pause");
}