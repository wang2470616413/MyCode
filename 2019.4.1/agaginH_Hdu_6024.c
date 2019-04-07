#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3005;
struct node
{
	ll x,w;
	node()
	{
	};
	node(ll px, ll pw)
	{
		x = px;
		w = pw;
	};
	bool operator < (const node two) const
	{
		return x < two.x;
	}
};
ll dp[N][2];
node data[N];
int n;
int main()
{
	while(~scanf("%d",&n))	
	{
		mmset(dp,0);
		for(int i = 1; i <= n ; i++)
		{
			scanf("%lld %lld",&data[i].x,&data[i].w);
		}
		sort(data + 1, data + 1 + n);
		dp[1][0] = dp[1][1] = data[1].w;
		for(int i = 2; i <= n; i++)
		{
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + data[i].w;
			ll  temp = data[i].x - data[i-1].x;
			dp[i][1] = 0x3f3f3f3f3f3f3f;
			for(int j = i - 1; j >= 1;j--)
			{
				dp[i][1] = min(dp[i][1],dp[j][0]  + temp);
				temp += (data[j].x - data[j-1].x) * (i - j + 1);
			}
		}
		ll res = min(dp[n][0],dp[n][1]);
		printf("%lld\n",res);
	}

	return 0;
}
