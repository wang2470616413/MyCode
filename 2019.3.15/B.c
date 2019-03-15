#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll MOD =  100000007;
//int mark[2000005];
int n;
int main()
{
	ll a;
	scanf("%d %lld",&n,&a);
	ll sum = a;
	for(int i = 2; i <= n; i++)
	{
		ll  b;
		scanf("%lld",&b);
		sum += b;
		sum %= MOD;
		a = a ^ b;
	}
	sum += a;
	sum %= MOD;
	printf("%lld\n",sum);



	return 0;
}
