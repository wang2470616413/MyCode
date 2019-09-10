#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e3;
ll sum[N][N];
int n,m;
int lowbit(int x)
{
	return x & (-x);
}
void update(int x, int y, ll k)
{
	for(int i = x; i <= n; i += lowbit(i))
	{
		for(int j = y; j <= m; j += lowbit(j))
		{
			sum[i][j] += k;
		}
	}
}
ll getSum(int x, int y)
{
	ll res = 0;
	for(int i = x; i >= 1; i -= lowbit(i))
	{
		for(int j = y; j >= 1; j -= lowbit(j))
		{
			res += sum[i][j];
		}
	}
	return res;
}
/*
2 2
1 1 1 3
1 2 2 4
2 1 1 2 2
*/
int main()
{
	mmset(sum,0);
	scanf("%d %d",&n,&m);
	int mark;
	while(~scanf("%d",&mark))
	{
		int x,y,x1,y1,x2,y2;
		ll k;
		if(mark == 1)
		{
			scanf("%d %d %lld",&x,&y,&k);
			update(x,y,k);
		}
		else
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2)	;
			ll res = getSum(x2,y2) - (getSum(x1 - 1,y2) + getSum(x2,y1 - 1) - getSum(x1 -1,y1 - 1)) ;
			printf("%lld\n",res);
		}
	}
	
	return 0;
} 