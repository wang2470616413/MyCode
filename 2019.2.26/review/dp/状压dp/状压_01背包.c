#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
int dp[1 << N + 5];
int dp1[1 << N + 5];
int W[N], V[N];
int n,m;
void printf1(int num);
int main()
{
	int n,m;
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&V[i],&W[i]);	
	}
	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)if(!(i & (1 << j)))
		{
			int temp = (1 << j) | i;
			dp[temp] = dp[i] + W[j];
			dp1[temp] = dp1[i] + V[j];
		}
	}
	for(int i = 0; i < (1 << n); i++)
	{
		printf1(i);
		printf("\t %d %d\n",dp[i],dp1[i]);
	}

	return 0;
}
void printf1(int num)
{
	if(num == 0)
	{
		printf("0");
	}
	for(int i = 0; (1 << i) <= num; i++)
	{
		if((1 << i) & num)
		{
			printf("1");
		}
		else 
		{
			printf("0");

		}

	}

}
