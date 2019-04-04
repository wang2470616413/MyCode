#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3005;
int dp[N][2], data[N][2];
int n;
int main()
{
	while(~scanf("%d",&n))	
	{
		mmset(dp,0);
		for(int i = 1; i <= n ; i++)
		{
			scanf("%d %d",&data[i][0],&data[i][1]);
		}
		for(int i = 1; i <= n; i++)
		{
			dp[i][1] = 8
		}
	}






	return 0;
}
