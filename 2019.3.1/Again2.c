#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 10;
int data[N], pre[N], n,m;
int  father[N];
ll aux[N];
ll res = 0;
int find(int x)
{
	return father[x] = father[x] == x ? x : find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	m = m > n ? n : m;
	mmset(aux,0);
	for(int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&pre[i]);
		merge(i,pre[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		find(i);
	}
	for(int i = 1; i <= n; i++)
	{
		aux[father[i]] += data[i];
	}
	sort(aux + 1, aux + 1 + n);
	for(int i = n; i > n - m; i--)
	{
		res += aux[i];
	}
	printf("%lld\n",res);
	return 0;
}
