#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
int map1[N][N],data[N][N];
int dp[N][N][N];
int n,m,z;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(map1,0);
		scanf("%d %d %d",&n,&m,&z);
		for(int i = 1; i <= m; i++)
		{
			for(int j = 2; j <= n; j++)
			{
				scanf("%d",&map1[i][j]);
			}
		}
		for(int i = 1; i <= m; i++) 
		{
			for(int j = 1; j <= m; j++) 
			{
				scanf("%d",&data[i][j]);
				if(i == j)
				{
					data[i][j] = 0;
				}
			}
		}
		mmset(dp,0x3f);
		dp[z][1][1] = 0; 
		for(int k = z; k >= 0; k--)
		{
			for(int j = 1; j <= n; j++)
			{
				for(int i = 1; i <= m; i++)
				{
					for(int q = 1; q <= m; q++)if(k + data[q][i] <= z)
					{
						 dp[k][i][j] = min(dp[k][i][j],min(dp[k + data[q][i]][q][j],dp[k + data[q][i]][q][j-1] + map1[q][j]));
					}
				}
			}
		}
		int res = 0x3f3f3f3f;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j <= z; j++)
			{
				res = min(res,dp[j][i][n]);
			}
		}
		printf("%d\n",res);
	}
	
	
	
	
	return 0;
}
