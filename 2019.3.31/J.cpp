#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7; 
ll data[N];
int main()
{
	data[0] = data[1] = data[2] = 1;
	for(int i = 3; i <= 1e6; i++)
	{
		data[i] = ((data[i - 1] << 1) % MOD + (data[i - 2] >> 1)) % MOD;
	}
	int T;
	scanf("%d",&T) ;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",data[n]);
	}
	
	
	return 0;
} 
