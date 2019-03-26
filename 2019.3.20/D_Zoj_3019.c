#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 10005;
int n,m; 
int dp[2][N];
int data1[N],data2[N];
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data1[i]);
		}
		for(int j = 1; j <= m; j++)
		{
			scanf("%d",&data2[j]);
		}
		sort(data1 + 1, data1 + 1 + n);
		sort(data2 + 1, data2 + 1 + m); 
		mmset(dp,0);
		for(int i = 1; i <= n; i++)
		{
		//	printf("%d %d %d\n", i,i % 2, (i % 2) ^ 1);
			for(int j = 1; j <= m; j++)
			{
				
	
					if(data1[i] == data2[j])
					{
						dp[i % 2][j] = dp[(i % 2) ^ 1][j-1] + 1;
					}
					else 
					{
						dp[i % 2][j] = max(dp[(i % 2) ^ 1][j],dp[i % 2][j-1]);
					}
				
			}
			for(int j = 0; j <= m; j++)
			{
				dp[(i % 2) ^ 1][j] = 0;
			}
		}
		printf("%d\n",max(dp[0][m],dp[1][m]));
	}
	
	
	return 0;
}

