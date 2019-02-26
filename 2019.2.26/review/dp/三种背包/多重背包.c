#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005, M = 1005;
int V[N],W[N],num[N];
int dp[M];
int n,m;
void ZeroPack(int v, int w);
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
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		int j = 1;
		while(j < num[i])
		{
			ZeroPack(j * V[i], j * W[i]);
			num[i] -= j;
			j *= 2;
		}		
		ZeroPack(num[i] * V[i],num[i] * W[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		printf("%d ",dp[i]);
	}
	printf("\n");
	return 0;
}
void ZeroPack(int v, int w)
{
	for(int i = m; i >= v; i--)
	{
		dp[i] = max(dp[i],dp[i - v] + w);
	}
}
