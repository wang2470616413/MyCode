#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
using namespace std;
int res = 1;
int aux[100],data[100];
int n;
int n1;
void dfs(int index, int len)
{
	if(index == len)
	{
		int flag = 0;
		for(int i = 1; i <= len - 1 && flag == 0; i++)
		{
			for(int j = i + 1; j <= len && flag == 0; j++)
			{
				if(gcd(data[aux[i]], data[aux[j]]) != 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
		{
			res = max(res,len);
		}
		return ;
	}
	else
	{
		for(int i = aux[index] + 1; i <= n; i++)
		{
			aux[index + 1] = i;
			dfs(index + 1, len);
		}
	}
	
}
/*
2
3
3 4 5
7
7 6 5 4 3 2 1
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		res = n == 0 ? 0 : 1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		sort(data + 1, data + 1 + n);
		n = unique(data + 1, data + 1 + n) - (data + 1);
		for(int i = 2; i <= n; i++)
		{
			dfs(0,i);
		}
		printf("%d\n",res);
	}
	return 0;
}