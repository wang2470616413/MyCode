#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll MOD =  100000007;
int mark[2000005];
int n;
int main()
{
	scanf("%d",&n);
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int b;
		scanf("%d",&b);
		if(mark[b] == 0)
		{
			sum += b;
			sum %= MOD;
			mark[b] = 1;
		}
	}
	printf("%lld\n",sum);



	return 0;
}
