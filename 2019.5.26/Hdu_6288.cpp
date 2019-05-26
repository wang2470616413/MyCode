#include<stdio.h>
#include<algorithm>
#include<string.h> 
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll MOD = 1e9 + 7;
ll a1,b1,k1;
ll powd(ll a, ll b)
{
	ll ans = 1;
	while(b != 0)
	{
		if((b & 1) == 1)
		{
			ans = ans * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return ans;
}
ll pow_MOD(ll a, ll b)
{
	ll ans = 1;
	while(b != 0)
	{
		if((b & 1) == 1)
		{
			ans = (ans % MOD) * (a % MOD) % MOD;
		}
		a = (a % MOD) * (a % MOD) % MOD;
		b = b >> 1;
	}
	return ans % MOD;
}
ll count1(ll num)
{
	return ceil(log2(num));
}
ll bind_count(ll a, ll b, ll k)
{
	ll m;
	while(a < b)
	{
		m = (a + b + 1) >> 1;
		ll mk = count1(m);
		ll t0 = powd(m,a1);
		ll t1 = powd(mk,b1);
		ll t0_Mod = pow_MOD(m,a1);
		ll t1_Mod = pow_MOD(mk,b1);
		if(t0 % MOD != t0_Mod || t1 % MOD != t1_Mod || t0_Mod * t1_Mod % MOD != t0 * t1 % MOD)
		{
			b = m - 1;
		}
		else
		 {
		 	if(t0 * t1 <= k)
		 	{
		 		a = m;
			}
			 else
			 {
			 	b = m - 1;
			 }
		 }
	}
	return a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&a1,&b1,&k1);
		ll res = bind_count(0,1e18,k1);
		printf("%lld\n",res);
	}
	
	return 0;
}