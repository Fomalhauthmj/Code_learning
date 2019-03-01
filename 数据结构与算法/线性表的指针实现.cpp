#include<iostream>
using namespace std;
typedef int ElementType;
struct node
{
    ElementType element;
    node *next;
};
typedef node *Position;
typedef node *List;
void Insert(ElementType ele,Position p)
{
    Position temp = p->next;
    p->next = new node;
    p->next->element = ele;
    p->next->next = temp;
}
void Delete(Position p)
{
    Position q;
    if(p->next!=NULL)
    {
        q = p->next;
        p->next = q->next;
        delete q;
    }
}
void disp(List l)
{
    Position p = l;
    while(p!=NULL)//初始显示L->next  如果是p->next 最后一个不显示 最后的next==null
    {
        cout << p->element << " ";
        p = p->next;
    }
    cout << endl;
}
Position Locate(ElementType ele,List l)
{
    Position p = l;
    while(p->next!=NULL)
    {
        if(p->next->element==ele)
        //if(p->element==ele)
        //TODO:注意这里两者的区别 插入位置区别
        //p->element在此结点后插入
        //p->next->element在此结点前插入
            return p;
        else
            p = p->next;
    }
    return p;
}
void test()
{
    List l=new node;
    l->next = NULL;//make null
    Insert(100, l);
    disp(l->next);
    Insert(25, Locate(100,l));
    disp(l->next);
    Delete(Locate(25,l));
    disp(l->next);
}
int main()
{
    test();
    system("pause");
}