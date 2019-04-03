#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
int dp[N];
int data[N];
int main()
{
	int T;
	scanf("%d",&T) ;
	int num = 1;
	while(T--)
	{
		mmset(dp,0);
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]) ;
		}
		int res = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++)
		{
			int sum = 0;
			dp[i] = 0x3f3f3f3f;
			for(int j = i; j > 0; j--)
			{
				sum += data[j];
				dp[i] = min(abs(sum),dp[i]);
			}
			res = min(dp[i],res);
		}
		printf("Case %d: %d\n",num++,res);
	}

	return 0;
}

