#include <iostream>
using namespace std;
#define MAX_LENGTH 100
//数组实现
typedef int Position;
typedef int ElementType;
struct List
{
    ElementType elements[MAX_LENGTH];
    Position len;
    //start with 0-index 数组结构的特点是位置为整型
};
void disp(List &l)
{
    for (Position i = 0; i < l.len; i++)
    {
        cout << l.elements[i] << " ";
    }
    cout << endl;
}
void Insert(Position p, List &l, ElementType ele)
{
    if (l.len >= MAX_LENGTH || p < 0 || p > l.len)
        return;
    for (Position i = l.len - 1; i >= p; i--)
        l.elements[i + 1] = l.elements[i];
    l.elements[p] = ele;
    l.len++;
}
void Delete(Position p, List &l)
{
    if (p < 0 || p >= l.len || l.len < 1)
        return;
    for (Position i = p; i < l.len; i++)
        l.elements[i] = l.elements[i + 1];
    l.len--;
}
void test()
{
    List t;
    t.len = 0;
    Insert(0, t, 99);
    disp(t);
    Insert(0, t, -1);
    disp(t);
    Insert(1, t, 233);
    Insert(3, t, 100);
    disp(t);
    Delete(0, t);
    disp(t);
    Delete(1, t);
    disp(t);
}

int main()
{
    test();
    system("pause");
}