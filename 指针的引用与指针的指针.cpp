#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void Disp(node *&n)
{
    if(n)
    {
        Disp(n->left);
        cout<<n->data<<" ";
        Disp(n->right);
    }
}
void Trans_1(node *&n)
{
    *n=*(n->right);
}
void Trans_2(node **n)
{
    **n=*((*n)->right);
}
int main()
{
    node *a = new node;
    a->left =a->right= NULL;
    a->data = 1;
    node *b = new node;
    b->left =b->right= NULL;
    b->data = 2;
    node *c = new node;
    c->left =c->right= NULL;
    c->data = 3;
    node *d = new node;
    d->left =d->right= NULL;
    d->data = 4;

    a->left=b;
    a->right=c;
    c->right=d;
    Disp(a);
    cout<<endl;
    //*c=*c->right;
    //Trans_1(c);
    Trans_2(&c);
    Disp(a);
    cout<<endl;
    system("pause");
}
