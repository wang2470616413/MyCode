#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
int dp[N][1 << N];
int h, w;
void dfs(int j, int si, int state,int nstate);
int main()
{
	while(~scanf("%d %d",&h,&w))
	{
		mmset(dp,0);
		dp[1][0] = 1;
		for(int i = 1; i <= h; i++)
		{
			for(int j = 0; j < (1 << w); j++)if(dp[i][j] > 0)
			{
				dfs(0,i,j,0);
			}
		}
		printf("%d\n",dp[h + 1][0]);

	}
	return 0;
}
void dfs(int j, int si, int state,int nstate)
{	
	if(j == w)
	{
		dp[si + 1][nstate] += dp[si][state];
	}
	else 
	{
		int temp = 1 << j;
		int temp1 = 1 << (j + 1);
		if(!(temp & state))
		{
			dfs(j +1, si,state,temp | nstate);
			if(!(temp1 & state) &&j < w)
			{
				dfs(j + 2,si,state,nstate);
			}
		}
		else 
		{
			dfs(j + 1, si, state,nstate);
		}

	}


}
