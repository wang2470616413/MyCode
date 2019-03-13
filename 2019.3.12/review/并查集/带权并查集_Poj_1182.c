#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e5 + 5;
int father[N],weight[N];
int n,m;
void init(int a,int b,int c)
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
		weight[x] += weight[temp] + 3;
		weight[x] %= 3;
	}
	return father[x];
}
void merge(int x,int y,int w)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
		weight[fx] = w + weight[y] - weight[x]  + 3;
		weight[fx] %= 3;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int res = 0;
	init(1,n,0);
	for(int i = 1; i <= m; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&c,&a,&b);
		if(a <= n && b <= n)
		{
			int fa = find(a);
			int fb = find(b);
			if(fa == fb)
			{
				int dis = (weight[a] - weight[b] + 3) % 3;
				if(c == 1)
				{
					if(dis != 0)
					{
						res++;
					}
				}
				else 
				{
					if(dis != 2)
					{
						res++;
					}
				}
			}
			else 
			{
				if(c == 1)
				{
					merge(a,b,0);
				}
				else 
				{
					merge(a,b,2);
				}
			}

		}
		else 
		{
			res++;
		}

	}
	printf("%d\n",res);







	return 0;
}
