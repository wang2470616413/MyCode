#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define  mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int off = 210000;
const int N = 4300;
const int MOD = 1e8 + 7;
int n,data[310];
int dp[2][430000];
int main()
{
	mmset(dp,0);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	dp[0][0 + off] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 420000; j++)
		{
			if(j == 666 + off)	
			{
				continue;
			}
			dp[i % 2][j] = (dp[i % 2 ^ 1][(j - off) * -1 + off] % MOD);
			dp[i % 2][j] += (dp[i % 2 ^ 1][(j - off) - data[i] + off] % MOD);
			dp[i % 2][j] %= MOD;
		}
	}
	printf("%d\n",dp[n % 2][-666 + off]);
	return 0;
}
