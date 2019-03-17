#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
int map1[N][N];
int mark[N],dis[N];
int n,m;
int main()
{
	while(scanf("%d %d",&n,&m) && n + m != 0)
	{
		mmset(map1,0x3f);
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			map1[a][b] = c;
			map1[b][a] = c;

		}
		mmset(dis,0x3f);
		mmset(mark,0);
		for(int i = 1; i <= n; i++)
		{
			dis[i] = map1[1][i];
		}
		mark[1] = 1,dis[1] = 0;
		for(int i = 1; i < n; i++)
		{
			int min1 = 0x3f3f3f3f, u = -1;
			for(int j = 1; j <= n; j++)if(mark[j] == 0 && min1 > dis[j])
			{
				min1 = dis[j];
				u = j;
			}
			mark[u] = 1;
			dis[u] = min1;
			for(int j = 1; j <= n; j++)if(mark[j] == 0 && dis[j] > dis[u] + map1[u][j])
			{
				dis[j] = dis[u] + map1[u][j];
			}
		}
		printf("%d\n",dis[n]);
	}




}
