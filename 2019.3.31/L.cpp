#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
struct node
{
	int x, y;
	ll w;
	node ()
	{
	};
	node (int px, int py, ll pw) 
	{
		x = px;
		y = py;
		w = pw;
	};
	bool operator < (node two) const 
	{
		return w < two.w;
	}
};
node data[N];
int father[N];
void init(int a, int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	}
}
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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	init(0,n);
	int res = 0;
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);	
		int fx = find(a);
		int fy = find(b);
		if(fx != fy)
		{
			res++;
		}
		merge(a,b);
	}
	for(int i =  1;i <= k; i++)
	{
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		data[i] = node(a,b,c);
	}
	sort(data + 1, data + 1 + k);
	ll sum = 0;
	for(int i = 1; i <= k; i++)
	{
		if(res == n-1)
		{
			break;
		}
		int x = data[i].x;
		int y = data[i].y;
		if(find(x) != find(y))
		{
			res++;
			sum += data[i].w;
		}
		merge(x,y);
	}
	if(res == n-1)
	{
		printf("%lld\n",sum);
	}
	else
	{
		printf("Concubines can't do it.\n");
	}
	
	
	
	return 0;
}
