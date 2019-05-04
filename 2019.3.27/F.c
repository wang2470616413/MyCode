#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 10;
const int M = 15;
int uN,vN;
int g[N][M];
int linker[M][N];
bool used[M];
int num[M];
bool dfs(int u)
{
	for(int v = 0; v < vN; v++)
	{
		if(g[u][v] && !used[v])
		{
			used[v] = true;
			if(linker[v][0] < num[v])	
			{
				linker[v][++linker[v][0]] = u;
				return true;
			}
			for(int i = 1; i <= num[v]; i++)
			{
				if(dfs(linker[v][i]))
				{
					linker[v][i] = u;
					return true;
				}
			}
		}
	}
	return false;
}
int hungary()
{
	int res = 0;
	for(int i = 0; i < vN; i++)
	{
		linker[i][0] = 0;
	}
	for(int u = 0; u < uN;u++)
	{
		mmset(used,false);
		if(dfs(u))res++;
	}
	return res;
}
int main()
{
//	while(~scanf("%d %d",&uN,&vN))
	{
		scanf("%d %d",&uN,&vN);
		for(int i = 0; i < uN; i++)
		{
			for(int j = 0; j < vN; j++)	
			{
				scanf("%d",&g[i][j]);
			}
		}
		for(int i = 0; i < vN; i++)
		{
			scanf("%d",&num[i]);
		}
		int res = hungary();
		if(res < vN)
		{
			printf("NO\n");
		}
		else 
		{
			printf("YES\n");
		}
	}
	return 0;
}

