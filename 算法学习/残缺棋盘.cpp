// 01   20  33  44
// 11   22  03  40
//
//
#include <iostream>
using namespace std;
#define N 1<<15
int k, xd, yd,cnt=1;
int board[N][N];
void chess(int x, int y, int size, int xd, int yd)
{
    size /= 2;
    if (xd < size + x && yd < size + y)
    {
        chess(x, y,size,xd,yd);
        board[x+size][y+size]=board[x+size][y+size-1]=board[x+size-1][y+size]=cnt;
        cnt++;
        chess(x+size,y,size,x+size,y+size-1);
        chess(x,y+size,size,x+size-1,y+size);
        chess(x+size,y+size,size,x+size,y+size);
    }
    else if (xd >= size + x && yd < size + y)
    {
    }
    else if (xd < x + size && yd >= y + size)
    {
    }
    else if (xd >= x + size && yd >= y + size)
    {
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> k >> xd >> yd;
    int size = pow(2, k);
    chess(0, 0, size, xd, yd);
    system("pause");
    return 0;
}