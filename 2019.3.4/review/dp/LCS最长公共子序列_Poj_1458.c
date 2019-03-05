#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
char data1[N],data2[N];
int dp[N][N];
int n,m;
int main()
{
	mmset(dp,0);
	scanf("%s",data1+1);
	scanf("%s",data2+1);
	n = strlen(data1+1);
	m = strlen(data2+1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + (data1[i] == data2[j] ? 1 : 0);
			dp[i][j] = max(max(dp[i - 1][j],dp[i][j - 1]),dp[i][j]);
		}

	}
	printf("%d\n",dp[n][m]);
	
	return 0;
}
