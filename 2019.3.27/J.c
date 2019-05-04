#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
char data[N];
ll sum[N];
ll pow1(ll a, ll b)
{
	ll ans = 1;
	ll base = a;
	while(b)
	{
		if(b & 1)
		{
			ans = (ans % MOD) * (base % MOD);
		}
		base = (base % MOD) * (base % MOD);
		b <<= 1;
	}
	return ans;
	
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",data + 1);
	mmset(sum,0);
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1] + (data[i] - '0');
	}
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ll temp = sum[b] - sum[a - 1];
		ll temp1 = b - a + 1 - temp;
		printf("%lld %lld\n",temp,temp1);
		ll sum1 = pow1(2,temp) - 1;
		printf("%lld\n",sum1);
		ll sum2 = (sum1 % MOD) * (pow1(2,temp1 - 1) % MOD);
		ll sum = sum1 + sum2;
		printf("%lld\n",sum);
	}





	return 0;
}
