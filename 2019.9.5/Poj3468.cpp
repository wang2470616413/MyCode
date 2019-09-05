#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
ll diff[N], aux[N];
int n,m;
int lowbit(int x)
{
	return x & (-x);
}
void update(int p, ll c)
{
	ll temp = p;
	while(p <= n)
	{
		diff[p] += c;
		aux[p] += (temp-1) * c;
		p += lowbit(p);
	}
}
ll getSum(int p)
{
	ll res = 0;
	ll temp = p;
	while(p >= 1)
	{
		res += temp * diff[p];
		res -= aux[p];
		p -= lowbit(p);
	}
	return res;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
*/
int  main()
{
	scanf("%d %d",&n,&m);
	ll mark = 0, num;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&num);
		update(i,num - mark);
		mark = num;
	}
	while(m--)
	{
		char flag;
		ll x,y,z;
		scanf(" %c %d %d",&flag,&x,&y);
		if(flag == 'Q')
		{
			printf("%lld\n",getSum(y) - getSum(x-1));
		}
		else
		{
			scanf("%lld",&z);
			update(x,z);
			update(y + 1,-z);
		}
	}
	return 0;
}