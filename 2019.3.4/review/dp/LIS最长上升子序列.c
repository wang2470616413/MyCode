#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
int data[N + 5];
int dp[N + 5];
int path[N];
int n;
void printfPath(int p);
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}	
	dp[1] = 1;
	mmset(path,0);
	for(int i = 2;i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(data[i] > data[j])
			{
				if(dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					path[i] = j;
				}
			}
		}
	}
	int res = 0;
	int u;
	for(int i = 1; i <= n; i++)
	{
		if(res < dp[i])
		{
			res = dp[i];
			u = i;
		}
	}
	printf("%d\n",res);
	printfPath(path[u]);
	printf("%d ",data[u]);	
	printf("\n");


	return 0;
}

void printfPath(int p)
{
	if(p == 0)
	{
		return ;
	}
	else 
	{
		printfPath(path[p]);
		printf("%d ",data[p]);
	}
}
