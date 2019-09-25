#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int dp0[N];
int dp1[N];
int data[N];
/*
10
1 2 -4 3 2 3
*/
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d",&data[i]);
	}
	mmset(dp0,0);
	mmset(dp1,0);
	ll sum0 = 0, sum1 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(data[i] < 0)
		{
			dp0[i] = dp1[i-1] + 1;
			dp1[i] = dp0[i-1];
		}
		else if(data[i] > 0)
		{
			dp0[i] = dp0[i-1];
			dp1[i] = dp1[i-1] + 1;
		}
		sum0 += dp0[i];
		sum1 += dp1[i];
	}
	printf("%lld %lld\n",sum0,sum1);
	
	
	return 0;
}