#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
const int M = 10185;
int data[N][N], dp[N][N][M];
int n,m,C;
int sx,sy,ex,ey;
/*
*/
int main()
{
	scanf("%d %d %d",&n,&m,&C);
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	mmset(dp,-0x3f);
	dp[sx][sy][0] = 0;
	for(int k = 1; k <= M; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				dp[i][j][k] = max(max(max(dp[i-1][j][k-1],dp[i+1][j][k-1]),max(dp[i][j-1][k-1],dp[i][j+1][k-1])),dp[i][j][k-1]) + (k % data[i][j] == 0 ? 1 : 0);
			}	
		}
	}
	int res = -1;
	for(int i = 1; i <= M; i++)
	{
		if(dp[ex][ey][i] >= C)
		{
			res = i;
			break;
		}
	}
	printf("%d\n",res);

	return 0;

}
 


