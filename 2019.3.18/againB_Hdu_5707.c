#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2005;
char data1[N], data2[N],data3[N];
int dp[N][N];
int main()
{
	while(~scanf("%s",data1 + 1))
	{
		scanf("%s",data2 + 1);
		scanf("%s",data3 + 1);
		int n = strlen(data2 + 1);
		int m = strlen(data3 + 1);
		mmset(dp,0);
		dp[0][0] = 1;
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if(dp[i][j - 1] == 1 && j - 1 >= 0)
				{
					dp[i][j] = data2[j] == data3[i + j] ? 1 : 0;
				}
				if(dp[i-1][j] == 1 && i - 1 >= 0)
				{
					dp[i][j] = data1[i] == data3[i + j] ? 1 : 0;
				}
			}
		}
		if(dp[n][n] == 1 && (m % 2 == 0 && m / n == 2))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}
