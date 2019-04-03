#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 100005; 
struct node
{
	ll c,d;
	node()
	{
		
	}
	node (ll pc, ll pd)
	{
		c = pc;
		d = pd;
	}
	bool operator < (const node two) const 
	{
		return d < two.d;
	}
};
node data[N];
ll sum[N];
int main()
{
	int T;
	scanf("%d",&T);
	int num = 1;
	while(T--)
	{
		mmset(sum,0);
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld %lld",&data[i].c,&data[i].d); 
			
		}
		sort(data + 1, data + 1 + n);
		ll res = 0;
		for(int i = 1; i <= n; i++)
		{
			sum[i] = sum[i-1] + data[i].c;
			if(sum[i] > data[i].d)
			{
				res = max(res,sum[i] - data[i].d);
			}
		}
		printf("Case %d: %lld\n",num++,res);
		
	}
	
	
	return 0;
}

