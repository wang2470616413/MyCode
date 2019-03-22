#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int M = 1e5 + 5;
const int N = 4e3;
int dp[M],V[N],W[N];
int n,m; 
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d",&V[i],&W[i]);
		}
		mmset(dp,0);
		for(int i = 1; i <= n; i++)
		{
			for(int j = m; j >= V[i]; j--)
			{
				dp[j] = max(dp[j],dp[j - V[i]] + W[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
	
	
	
	return 0;
} 
