#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 13;
ll dp[N][1 << N];
int n,m;
int data[N][N];
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
	for(int i = )





	return 0;
}
