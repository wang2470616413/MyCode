#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005, M = 1005;
int n,m;
int V[N],W[N],dp[M];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(dp,0);
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
			for(int j = m; j >= V[i]; j--)
			{
				dp[j]= max(dp[j],dp[j - V[i]] + W[i]);
			}
		}
		printf("%d\n",dp[m]);
	}





	return 0;
}

