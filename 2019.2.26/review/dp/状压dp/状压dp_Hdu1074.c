#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
struct node
{
	string str;
	int a,b;
};
int dp[1 << N + 10];
int cost[1 << N  + 10];
node data[N + 5];
int path[N];
int n;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>data[i].str>>data[i].a>>data[i].b;
		}
		mmset(dp,0x3f3f3f3f);
		dp[0] = 0;
		mmset(cost,0);
		for(int i = 0; i < (1 << n); i++)
		{
			for(int j = 0; j < n; j++)
			{
				int temp = 1 << j;
				if((temp & i) == 0)
				{
					int nconst = cost[i] + data[j].b - data[j].a;
					nconst = nconst < 0 ? 0: nconst;
					if(dp[temp| i] > dp[i] + nconst)
					{
						path[j] = 
						dp[temp | i] = dp[i] + nconst;
						cost[temp | i] = cost[i] + data[j].b;
					}
				}
			}
		}
		printf("%d\n",dp[(1 << n) - 1]);

	}





	return 0;
}
