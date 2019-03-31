#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
bool aux[N];
int index = 1;
int pri[N];
int res[N];
int data1[N];
void init(int n,int& len) 
{
	aux[0] = aux[1] = true;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(!aux[i])
		{
			len++;
			pri[len] = i;
			if(i >= n / i) continue;
			for(int j = i * i; j <= n; j += i)
			{
				aux[j] = true;
			}
		}
	}
}
void dev(int n, int m, int& len)
{
	int temp = sqrt(n);
	for(int i = 1; i <= m; i++)
	{
		if(pri[i] > temp)
		{
			break;
		}
		if(n % pri[i] == 0)
		{
			len++;
		}
		while(n % pri[i] == 0)
		{
			
			res[len] = pri[i];
			n /= pri[i];
		}
	}
	if(n != 1) 
	{
		len++;
		res[len] =  n;
	}
}
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main()
{
	int n,m;
	int len1 = 0;
	init(1e6,len1);
	while(~scanf("%d %d",&n,&m))
	{
		mmset(data1,0);
		int len = 0;
		dev(m,len1,len);
		for(int i = 1; i <= len; i++)
		{
			for(int j = 1; j * res[i] <= n; i++)
			{
				data1[i] = 1;
			}
		}
		ll sum = 0;
		for(ll i = 2; i <= n; i++)
		{
			if(data1[i] == 0)
			{
				sum = (sum % MOD) * (i % MOD) % MOD; 
			}
			
		}
		printf("%lld\n",sum % MOD);
	}
	
	
	
	
	
	return 0;
}
