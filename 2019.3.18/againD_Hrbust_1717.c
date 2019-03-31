#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 4000005;
ll data[N];
int tire[N][2];
int index1 = 0, root = 0;
void insert(ll num, int rt)
{
	rt = root;
	for(int i = 40; i >= 0; i--)
	{
		int temp = (num >> i) & 1;
		if(tire[rt][temp] == 0)
		{
			tire[rt][temp] = ++index1;
		}
		rt = tire[rt][temp];
	}
}
ll query(ll num)
{
	int rt = root;
	ll sum = 0;
	ll k =  (ll)1 << 40;
	for(int i = 40; i >= 0; i--)
	{
		int temp = (num >> i) & 1;
		if(tire[rt][temp ^ 1] != 0)
		{
			rt = tire[rt][temp ^ 1];
			sum += k;
		}
		else 
		{
			rt = tire[rt][temp];
		}
		k >>= 1;
	}
	return sum;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		mmset(tire,0);
		ll sum = 0;
		insert(0,0);
		for(int i = 1; i <= n; i++)
		{
			ll num = 0;
			scanf("%lld",&num);
			sum = sum ^ num;
			insert(sum,0);
			data[i] = num;	
		}
		ll ksum = 0;
		ll res = -1;
		for(int  i = n; i >= 1; i--)
		{
			ksum = ksum ^ data[i];
			ll temp = query(ksum);
			res = max(res,temp);
		}
		printf("%lld\n",res);
	}
	return 0;
}

