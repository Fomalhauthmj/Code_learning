/*
 * File Created: Wednesday, 17th July 2019 9:19:11 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 10:37:00 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
using namespace std;
#define ll long long
const int N = 1E5 + 50;
struct heap_node
{
    ll d;
    int lptr;
};
heap_node heap[N];
int heap_cnt;
//小根堆
struct list_node
{
    int pre, nxt, hptr;
    ll d;
};
list_node list[N];
int list_cnt;
void Up(int p)
{
    while (p > 1)
        if (heap[p].d < heap[p / 2].d)
        {
            swap(heap[p], heap[p / 2]);
            swap(list[heap[p].lptr].hptr, list[heap[p / 2].lptr].hptr);
            p /= 2;
        }
        else
            break;
}
heap_node &Top()
{
    return heap[1];
}
void Down(int p)
{
    int s = p * 2;
    while (s <= heap_cnt)
    {
        if (s < heap_cnt && heap[s].d > heap[s + 1].d)
            s++;
        if (heap[s].d < heap[p].d)
        {
            swap(heap[s], heap[p]);
            swap(list[heap[s].lptr].hptr, list[heap[p].lptr].hptr);
            p = s;
            s = p * 2;
        }
        else
            break;
    }
}
void Remove(int p)
{
    if (p == heap_cnt)
    {
        heap_cnt--;
        return;
    }
    swap(heap[p], heap[heap_cnt]);
    swap(list[heap[p].lptr].hptr, list[heap[heap_cnt].lptr].hptr);
    heap_cnt--;
    Down(p), Up(p);
}
void Delete(int p)
{
    list[list[p].pre].nxt = list[p].nxt;
    list[list[p].nxt].pre = list[p].pre;
}
ll n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll pre, num;
    cin >> n >> k >> pre;
    list_cnt = 0;
    heap_cnt = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> num;
        list[++list_cnt].d = num - pre;
        list[list_cnt].pre = i - 1;
        list[list_cnt].nxt = i + 1;
        list[list_cnt].hptr = ++heap_cnt;
        heap[heap_cnt].lptr = list_cnt;
        heap[heap_cnt].d = num - pre;
        pre = num;
        Up(heap_cnt);
    }
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += Top().d;
        //cout << ans << endl;
        //cout << "cur choose:" << Top().d << endl;
        if (!list[Top().lptr].pre || list[Top().lptr].nxt == n)
        {
            if (!list[Top().lptr].pre)
            {
                Remove(list[list[Top().lptr].nxt].hptr);
                Delete(list[Top().lptr].nxt);
            }
            else
            {
                Remove(list[list[Top().lptr].pre].hptr);
                Delete(list[Top().lptr].pre);
            }
            Delete(Top().lptr);
            Remove(1);
        }
        else
        {
            int pre_list_ptr = Top().lptr;
            Top().d = list[list[Top().lptr].pre].d + list[list[Top().lptr].nxt].d - list[Top().lptr].d;
            list[Top().lptr].d = Top().d;
            Down(1);
            Remove(list[list[pre_list_ptr].pre].hptr);
            Remove(list[list[pre_list_ptr].nxt].hptr);
            Delete(list[pre_list_ptr].pre);
            Delete(list[pre_list_ptr].nxt);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}