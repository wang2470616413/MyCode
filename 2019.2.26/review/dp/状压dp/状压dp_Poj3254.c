#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 13;
const int MOD = 100000000;
ll dp[N][1 << N];
int n,m;
int data[N][N];
void dfs(int j, int si, int state, int nstate, int flag);
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	mmset(dp,0);
	dp[0][0] = 1;
	for(int i =0; i < m; i++)
	{
		for(int j = 0; j < (1 << n); j++)if(dp[i][j] > 0)
		{
			dfs(0,i,j,0,0);
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		if(dp[m][i] > 0)
		{
			ans = (ans + dp[m][i]) % MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}
void dfs(int j, int si, int state, int nstate, int flag)
{
	if(j == n)
	{
		dp[si+1][nstate] = (dp[si][state] + dp[si + 1][nstate]) % MOD;
	}
	else 
	{
		int temp = 1 << j;
		int temp1 = 1 << (j + 1);
		if(data[j][si + 1] == 1 && flag == 0 && (temp & state) == 0)	
		{
			dfs(j + 1,si,state,nstate | temp,1);
			dfs(j + 1,si,state,nstate,0);	
		}
		else 
		{
			dfs(j+1,si,state,nstate,0);
		}
	}
}
