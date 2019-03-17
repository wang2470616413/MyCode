#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 55, M=  105;
int map1[N][N];
int mark[N];
int n,m;
int dis[N];
int main()
{
	while(scanf("%d", &n) && n != 0)	
	{
		mmset(mark,0);
		mmset(map1,0x3f);
		scanf("%d",&m);
		for(int i = 1; i <= m; i++)
		{

			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			map1[a][b] = map1[b][a] = min(c,min(map1[a][b],map1[b][a]));
		}
		for(int i = 1; i <= n; i++)
		{
			dis[i] = map1[1][i];
		}
		int res = 0;
		mark[1] = 1, dis[1] = 0; 
		for(int i = 2; i <= n; i++)
		{
			int min1 = 0x3f3f3f3f,u = -1;
			for(int j = 1; j <= n; j++) if(mark[j] == 0 && min1 > dis[j])
			{
				min1 = dis[j];
				u = j;
			}
			res += min1;
			mark[u] = 1;
			for(int j = 1; j <= n; j++)if(mark[j] == 0 && dis[j] > map1[u][j])
			{
				dis[j] = map1[u][j];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
