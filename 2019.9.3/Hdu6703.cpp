#include<stdio.h>
#include<string.h>
#include<set>
#include<iostream>
#include<algorithm>
#define ll long long 
#define mmset(a,b)  memset(a,b,sizeof(a))
#define lson l,m,ls[rt]
#define rson m+1,r,rs[rt]
using namespace std;
const int N = 1e5 + 5;
int ls[N * 30], rs[N * 30],tree[N * 30],root[N];
int data[N], tot = 1;
set <int> s;
void build(int l, int r,int& rt)
{
	rt = tot++;
	tree[rt] = 0;
	if(l == r)
	{
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		build(lson);
		build(rson); 
	}
};
void add(int p, int C, int l, int r, int& rt, int last)
{
	rt = tot++;
	tree[rt] = tree[last] + C;
	ls[rt] = ls[last];
	rs[rt] = rs[last];
	if(l == r)
	{
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		if(p <= m)
		{
			add(p,C,lson,ls[rt]);
		}
		if(p > m)
		{
			add(p,C,rson,rs[rt]);
		}
	};
};
int query(int x, int y, int k, int  l, int r)
{
	if(l == r)
	{
		return l;
	}
	else
	{
		int cnt = tree[ls[y]] - tree[ls[x]];
		int m = (l + r) >> 1;
		int res = -1;
		if(k <= m && cnt > 0)
		{
			res = query(ls[x],ls[y],k,l,m);
		}
		if(res != -1)
		{
			return res;
		}
		if(k <= r && tree[rs[y]] - tree[rs[x]])
		{
			return query(rs[x],rs[y],k,m+1,r);
		}
		else
		{
			return  -1;
		}
	}
}
/*
3
5 9
4 3 1 2 5 
2 1 1
2 2 2
2 6 7
2 1 3
2 6 3
2 0 4
1 5
2 3 7
2 4 3
10 6
1 2 4 6 3 5 9 10 7 8 
2 7 2
1 2
2 0 5
2 11 10
1 3
2 3 2
10 10
9 7 5 3 4 10 6 2 1 8 
1 10
2 8 9
1 12
2 15 15
1 12
2 1 3
1 9
1 12
2 2 2
1 9
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) 
	{
		int n,m;
		tot = 1;
		scanf("%d %d",&n,&m);
		build(1,n,root[0]);
		s.clear();
		s.insert(n+1);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
			add(data[i],1,1,n,root[i], root[i-1]);
		}
		int mark = 0, a,b,c;
		for(int  i = 1; i <= m; i++)		
		{
			scanf("%d",&a);
			if(a == 1)
			{
				scanf("%d",&b);
				b ^= mark;
				s.insert(data[b]);
			}
			else if(a ==  2)
			{
				scanf("%d %d",&b,&c);
				b ^= mark;
				c ^= mark;
				mark = query(root[b],root[n],c,1,n);
				int temp = *(s.lower_bound(c));
				if(mark != -1)
				{
					mark = min(mark,temp);
				}
				else
				{
					mark = temp;
				}
				printf("%d\n",mark);
			}
			
		}
	}
	return 0;
} 