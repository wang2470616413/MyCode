#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e5 + 5;
int diff[N];
int n,m;
int lowbit(int x)
{
	return x&(-x);
}
void update(int p ,int c)
{
	while(p <= n)
	{
		diff[p] += c;
		p += lowbit(p);
	}
}
int getSum(int p)
{
	int res = 0;
	while(p >= 1)
	{
		res += diff[p];
		p -= lowbit(p);
	}
	return res;
}
/*
5 5
1 5 4 2 3
1 2 4 2
2 3
1 1 5 -1
1 3 5 7
2 4
*/
int main()
{
	scanf("%d %d",&n,&m);
	int mark = 0,num;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&num);
		update(i,num - mark);
		mark = num;
	}
	int flag,a,b,k;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d",&flag);
		if(flag == 1)
		{
			scanf("%d %d %d",&a,&b,&k);
			update(a,k);
			update(b + 1, -k);
		}
		else if(flag == 2)
		{
			scanf("%d",&a);
			int res = getSum(a);
			printf("%d\n",res);
		}
	}
	return 0;
}