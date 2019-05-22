#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l, m, rt<<1
#define rson m + 1, r, rt<<1|1
using namespace std;
const int N = 5e4 + 5;
int sum[N << 2], lazy[N << 2], lsum[N << 2], rsum[N << 2];
int n,m;
void pushUp(int l, int r, int rt)
{
	int m = (l + r) >> 1;
	lsum[rt] = lsum[rt << 1];
	rsum[rt] = rsum[rt << 1 | 1];
	lsum[rt] = lsum[rt] == (m - l + 1) ? lsum[rt] + lsum[rt << 1 | 1] : lsum[rt];
	rsum[rt] = rsum[rt] == (r - m) ? rsum[rt] + rsum[rt << 1] : rsum[rt];
	sum[rt] = max(max(sum[rt << 1],sum[rt << 1 |1]),lsum[rt << 1 | 1] + rsum[rt << 1]);
}
void pushDown(int l, int r, int rt)
{
	if(lazy[rt] != -1) 
	{
		int m = (l + r) >> 1;
		lsum[rt << 1] = lazy[rt] == 0 ? 0 : (m - l + 1);
		lsum[rt << 1 | 1] = lazy[rt] == 0 ? 0 : (r - m);
		rsum[rt << 1] = lazy[rt] == 0 ? 0 : (m - l + 1);
		rsum[rt << 1 |1] = lazy[rt] == 0 ? 0 : (r - m);
		sum[rt << 1] = lazy[rt] == 0 ? 0 : (m - l + 1);
		sum[rt << 1 | 1] = lazy[rt] == 0 ? 0 : (r - m);
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		lazy[rt] = -1; 
	}
}
void build(int l, int r, int rt)
{
	if(l == r)
	{
		lsum[rt] = rsum[rt] = 1;
		sum[rt] = 1; 
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		build(lson);
		build(rson);
		pushUp(l,r,rt);
	}
}
void update(int L, int R, int k, int l, int r, int rt)
{
	if(L == 0 || R == 0)
	{
		return;
	}
	if(l >= L && r <= R)
	{
		lsum[rt] = rsum[rt] = sum[rt] = k != 0  ? r - l + 1 : 0;
		lazy[rt] = k;
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		pushDown(l,r,rt);
		if(L <= m)		
		{
			update(L,R,k,lson);
		}
		if(R >= m + 1)
		{
			update(L,R,k,rson);
		}
		pushUp(l,r,rt);
	}
}
int query(int L, int R, int k, int l, int r, int rt)
{
	if(l == r)
	{
		return l;
	}
	else
	{
		int m = (l+ r) >> 1;
		pushDown(l,r,rt);
		if(sum[rt << 1] >= k)
		{
			return query(L,R,k,lson);
		}
		else if(rsum[rt << 1] + lsum[rt << 1 | 1] >= k)
		{
			return m - rsum[rt << 1] + 1;
		}
		else if(sum[rt << 1 | 1] >= k)
		{
			return query(L,R,k,rson);
		}
		else
		{
			return 0;
		}
	}
}
/*
10 6
1 3
1 3
1 3
1 3
2 5 5
1 6
Sample Output
1
4
7
0
5
*/
int main()
{
		scanf("%d %d",&n,&m);
		mmset(lazy,-1);
		build(1,n,1);
		int mark,a,b;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d",&mark);
			if(mark == 1)
			{
				scanf("%d",&a);
				int res = query(1,n,a,1,n,1);
				printf("%d\n",res);
				update(res, res + a - 1, 0, 1, n, 1);

			}
			else
			{
				scanf("%d %d",&a,&b);
				update(a,a + b - 1,1,1,n,1);
			}	
		}
	return 0;
} 