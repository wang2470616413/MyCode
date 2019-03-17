#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 55, M=  105;
struct node 
{
	int a,b,w;
	node ()
	{

	};
	node (int p_x,int p_y,int p_w)
	{
		a = p_x;
		b = p_y;
		w = p_w;
	}
	bool operator < (const node two) const 
	{
		return w < two.w;
	}
};
node edges[M];
int father[N];
int n,m;
void init(int a,int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	}
}
int find(int x)
{
	return father[x] = x == father[x] ? x : find(father[x]);
}
void merge(int x,int y)
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
	while(scanf("%d",&n) && n != 0)
	{
		init(1,n);
		scanf("%d",&m);
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			edges[i] = node(a,b,c);
		}
		sort(edges + 1, edges + 1 + m);
		int num = 0;
		int res = 0;
		for(int i = 1; i <= m; i++)
		{
			if(num == n - 1)
			{
				break;
			}
			int a = edges[i].a;
			int b = edges[i].b;
			int w = edges[i].w;
			if(find(a) != find(b))
			{
				res += w;
				num++;
			}
			merge(a,b);
		}
		printf("%d\n",res);
	}
	return 0;
}
