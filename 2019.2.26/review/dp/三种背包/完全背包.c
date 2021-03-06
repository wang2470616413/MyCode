#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105, M = 1005;
int n,m;
int V[N],W[N];
int dp[M];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&W[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&V[i]);
	}
	mmset(dp,0);
	for(int i = 1; i <= n; i++)
	{
		for(int j = V[i]; j <= m; j++)
		{
			dp[j] = max(dp[j],dp[j - V[i]] + W[i]);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		printf("%d ",dp[i]);
	}
	printf("\n");


	return 0;
}
