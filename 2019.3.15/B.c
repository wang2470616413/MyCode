#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll MOD =  100000007;
int n;
int main()
{
	scanf("%d",&n);
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		ll b;
		scanf("%lld",&b);
		sum += b;
		sum %= MOD;
	}
	printf("%lld\n",sum);



	return 0;
}
