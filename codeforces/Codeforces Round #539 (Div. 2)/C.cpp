#include <iostream>
using namespace std;
#define N 300030
long long n;
int a[N]; //0-2^20->10^6
int xors[N];
void test() //TLE
{
    long long ans = 0;
    for (int i = 1; i <= n; i++) //left
    {
        //You should consider only pairs where r−l+1 is even number.
        for (int j = i + 1; j <= n; j += 2) //right
        {
            //int mid = (i + j - 1) / 2;
            /*
            al^al+1^...^amid=amid+1^amid+2^...^ar
            a1^a2^...^amid=a1^a2^...^al-1 ^ amid+1^...^ar
            xors[mid]=xors[l-1]^xors[r]^xors[mid]
            */
            //if (xors[mid] == (xors[i - 1] ^ xors[j] ^ xors[mid]))
            if (0 == (xors[i - 1] ^ xors[j]))
            {
                //cout << i << " " << j << endl;
                ans++;
            }
            /*
            else if(xors[mid]==(xors[j]^xors[mid])&&i==1)//i=1
            {
                cout << i << " " << j << endl;
            }
            */
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == 1)
                xors[i] = a[i];
            else
                xors[i] = xors[i - 1] ^ a[i];
        }
        test();
    }
}