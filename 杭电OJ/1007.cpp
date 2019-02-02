#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
struct point
{
	double x;
	double y;
};
point p[N];
vector<point> lp;
vector<point> rp;
double dis(point &a, point &b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double min(double a, double b)
{
	return a < b ? a : b;
}
bool cmpx(point &a, point &b)
{
	return a.x < b.x;
}
bool cmpy(point &a, point &b)
{
	return a.y < b.y;
}
double mindis(int l, int r)
{
	if (l == r)
		return inf;
	if (l + 1 == r)
		return dis(p[l], p[r]);
	//	if( l + 2 == r )
	//		return min ( dis ( p[l] , p[l+1] ) , min ( dis ( p[l+1] , p[r] ) , dis ( p[l] , p[r] ) ) );
	else
	{
		int mid = (l + r) >> 1;
		double d = min(mindis(l, mid), mindis(mid + 1, r));
		lp.clear();
		rp.clear();
		for (int i = l; i <= r; i++)
		{
			if (fabs(p[i].x - p[mid].x) <= d)
			{
				if (p[i].x - p[mid].x < 0)
					lp.push_back(p[i]);
				else
					rp.push_back(p[i]);
			}
		}
		vector<point>::iterator it1;
		vector<point>::iterator it2;
		for (it1 = lp.begin(); it1 != lp.end(); it1++)
		{
			for (it2 = rp.begin(); it2 != rp.end(); it2++)
			{
				d = min(d, dis(*it1, *it2));
			}
		}
		/*
		sort ( p2 , p2+count , cpy );
		for ( int i=0 ; i < count ; i++ )
		{
			for ( int j = i+1; j < count ;j++)
			{
				if ( p2[j].y-p2[i].y>=d)
					break;
				else if(dis (p2[j],p2[i])<d)
					d=dis(p2[j],p2[i]);
			}
		}
		*/
		return d;
	}
}
int main()
{
	int n;
	double ans;
	while (scanf("%d", &n) && n != 0)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		sort(p, p + n, cmpx);
		ans = mindis(0, n);
		printf("%.2f\n", ans / 2);
	}
	return 0;
}
