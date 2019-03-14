#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		{
			init(1,n);
			for(int i = 1; i <= m; i++)
			{
				int a,b;
				scanf("%d %d",&a,&b);
				merge(a,b);
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			if(father[i] == i)
			{
				res++;
			}
		}
		printf("%d\n",res);
	}



	return 0;
}
