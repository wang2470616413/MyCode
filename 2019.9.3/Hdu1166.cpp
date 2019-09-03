#include<stdio.h> 
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m + 1, r, rt<<1|1
const int N = 5e4 + 5;
int sum[N << 2], data[N];
int lowbit(int x)
{
	return x & (-x);
}
void update(int c, int p, int n)
{
	while(p <= n)
	{
		sum[p] += c;
		p += lowbit(p);
	}
};
int getSum(int p)
{
	int res  = 0;
	while(p >= 1)
	{
		res += sum[p];
		p -= lowbit(p);
	}
	return res;
}
int main()
{
	int num = 1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		mmset(sum,0);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
			update(data[i],i,n);
		}
		char opea[105];
		int a,b;
		printf("Case %d:\n",num++);
		while(scanf("%s",opea+1))
		{
			if(opea[1] == 'E')
			{
				break;
			}
			else
			{
				scanf("%d %d",&a,&b);
				if(opea[1] == 'A')
				{
					update(b,a,n);
				}
				else if(opea[1] == 'S')
				{
					update(-b,a,n);
				}
				else
				{
					int res = getSum(b) - getSum(a-1);
					printf("%d\n",res);
				}
			}
		}
	}
	return 0;
}