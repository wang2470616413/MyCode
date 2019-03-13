#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int father[N],weight[N];
int n,m;
void init(int a, int b, int c)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
		weight[i] = c;
	}
}
int find(int x)
{
	if(x != father[x])
	{
		int temp = father[x];
		father[x] = find(father[x]);
		weight[x] += weight[temp];
	}
	return father[x];
}
void merge(int x, int y, int w)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
		weight[fx] = w + weight[y] - weight[x];
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		init(0,n + 3,0);
		int res = 0;
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(find(a) == find(++b))
			{
				int temp = weight[a] - weight[b];
				if(temp != c)
				{
					res++;
				}
			}
			else 
			{
				merge(a,b,c);
			}
		}
		printf("%d\n",res);

	}
	return 0;
}
