#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define hash hash1
using namespace std;
const int N = 1e5 + 5;
int ls[N * 30],rs[N * 30], ts[N * 30], root[N];
int tree[N * 30];
int data[N], hash[N];
int n,m,tot;
void build(int l,int r, int& rt)
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
		build(l,m,ls[rt]);
		build(m+1,r,rs[rt]);
	}
	
}
void add(int p, int C, int l, int r, int& rt, int last)
{
	rt = tot++;
	ls[rt] = ls[last];
	rs[rt] = rs[last];
	tree[rt] = tree[last] + C;
	if(l == r)
	{
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		if(p <= m)
		{
			add(p,C,l,m,ls[rt],ls[rt]);
		}
		if(p >= m + 1)
		{
			add(p,C,m + 1, r, rs[rt], rs[rt]);
		}
	}
	
}
int query(int x, int y, int l, int r, int k)
{
	if(l == r)
	{
		return l;
	}
	else
	{
		int m = (l + r) >> 1;
		int cnt = tree[ls[y]] - tree[ls[x]];
		if(k <= cnt)
		{
			return query(ls[x],ls[y],l,m,k);
		}
		else
		{
			return query(rs[x],rs[y],m+1,r,k - cnt);
		}
	}
	

}

/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output
5
6
3
 */
int main()
{
	tot = 1;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		hash[i] = data[i];
	}
	sort(hash + 1, hash + 1 + n);
	int len = unique(hash + 1, hash + 1 + n) -  (hash + 1);
	build(1,len,root[0]);
	for(int i = 1; i <= n; i++)
	{
		int a = lower_bound(hash + 1, hash + 1 + n, data[i]) - hash;
		add(a,1,1,len,root[i],root[i-1]);
	}
	for(int i = 1; i <= m; i++)
	{
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		int res = hash[query(root[a-1],root[b],1,len,k)];
		printf("%d\n",res);
	}
	return 0;
}