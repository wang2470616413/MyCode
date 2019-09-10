#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e3 + 5;
ll diff[N][N], aux[N][N],auxi[N][N],auxj[N][N],auxij[N][N];
int n,m;
int lowbit(int x)
{
	return x & (-x);
}
void update(ll x, ll y, ll k)
{
	for(int i = x; i <= n; i += lowbit(i))
	{
		for(int j = y; j <= m; j += lowbit(j))
		{
			diff[i][j] += k;
			auxij[i][j] += (k * x * y);
			auxi[i][j] += (k * x);
			auxj[i][j] += (k * y);
		}
	}
}
ll getSum(ll x, ll y)
{
	ll res = 0;
	ll temp = (x + 1) *  (y + 1);
	for(int i = x; i >= 1; i -= lowbit(i))
	{
		for(int j = y; j >= 1; j -= lowbit(j))
		{
			res += (temp * diff[i][j]) + (auxij[i][j])
			     - ((y + 1) * auxi[i][j]) - ((x + 1) * auxj[i][j]);
			
		}
	}
	return res;
}
void updateArea(int x1, int y1, int x2, int y2, int k) 
{
	update(x1, y1,k);
	update(x2 + 1, y2 + 1,k);
	update(x2 + 1,y1,-k);
	update(x1,y2 + 1,-k);
}

/*
4 4
1 1 1 3 3 2
1 2 2 4 4 1
2 2 2 3 3
*/ 
int main()
{
	scanf("%d %d",&n,&m);
	int mark;
	while(~scanf("%d",&mark))
	{
		int x1, y1, x2,y2;
		ll k;
		if(mark == 1)
		{
			scanf("%d %d %d %d %lld",&x1,&y1,&x2,&y2,&k);
			updateArea(x1,y1,x2,y2,k) ;
		}
		else if(mark == 2)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			ll res = getSum(x2,y2) - (getSum(x1 - 1,y2) + getSum(x2,y1 - 1) - getSum(x1 -1,y1 - 1)) ;
			printf("%lld\n",res);
		}
	}

	return 0;
}