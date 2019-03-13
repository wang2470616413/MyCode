#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105,M = 105;
int V[N],W[N],num[N];
int dp[N];
int n,m;
void ZeroPack(int v, int w);
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(dp,0);
		scanf("%d %d",&m,&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d %d",&V[i],&W[i],&num[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			int k = 1;
			while(k < num[i])
			{
				ZeroPack(k * V[i], k * W[i]);
				num[i] -= k;
				k *= 2;
			}
			ZeroPack(num[i] * V[i], num[i] * W[i]);
		}
		printf("%d\n",dp[m]);
	}
	return 0 ;
}
void ZeroPack(int v, int w)
{
	for(int i = m; i >= v; i--)
	{
		dp[i] = max(dp[i],dp[i - v] + w);
	}
}


