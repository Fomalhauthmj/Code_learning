//vector不适用于稀疏图
#define N 1010
#define M 1010
struct Edge
{
    int next;
    int to;
    int w;
};
Edge edge[M];
int head[N];
int cnt = 0;
void init()
{
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
//逆序遍历
for (int i = head[u]; i != -1; i = edge[i].next)
/*
1->2
2->3
3->4
1->3
4->1
1->5
4->5

edge[0].to = 2;     edge[0].next = -1;      head[1] = 0;

edge[1].to = 3;     edge[1].next = -1;      head[2] = 1;

edge[2].to = 4;     edge[2],next = -1;      head[3] = 2;

edge[3].to = 3;     edge[3].next = 0;       head[1] = 3;

edge[4].to = 1;     edge[4].next = -1;      head[4] = 4;

edge[5].to = 5;     edge[5].next = 3;       head[1] = 5;

edge[6].to = 5;     edge[6].next = 4;       head[4] = 6;
 */
