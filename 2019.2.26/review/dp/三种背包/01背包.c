#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
const int M = 1005;
int V[N],W[N];
int dp[M];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&V[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&W[i]);
	}
	mmset(dp,0);
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= V[i]; j--)
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
