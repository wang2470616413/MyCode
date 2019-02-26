#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 505, M = 10005;
int W[N],V[N],dp[M];
int n,m;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;;
		scanf("%d %d",&a,&b);
		int m = b - a;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d",&W[i],&V[i]);
		}
		mmset(dp,0x3f3f3f3f);
		dp[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = V[i]; j <= m; j++)
			{
				dp[j] = min(dp[j],dp[j - V[i]] + W[i]);
			}
		}
		if(dp[m] == 0x3f3f3f3f)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
		}
	}
	return 0;
}


