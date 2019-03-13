#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 100;
double data[N], aux[N];
int vis[N] , ans = 0;
int AuxDfs(int len)
{
	for(int i = 1; i <= len; i++) if(vis[i] == 0)
	{
		for(int j = 1; j <= len; j++) if(i != j && vis[j] == 0)
		{
			double temp = aux[i];
			vis[j] = 1;
			aux[i] = temp + aux[j];
			if(aux[i] == 24 || AuxDfs(len) == 1)
			{
				return 1;
			}
			aux[i] = temp - aux[j];
			if(aux[i] == 24 || AuxDfs(len) == 1)
			{
		 		return 1;
			}
			aux[i] = temp / aux[j];
			if(aux[i] == 24 || AuxDfs(len) == 1)
			{
				return 1;
			}
			aux[i] = temp * aux[j];
			if(aux[i] == 24 || AuxDfs(len) == 1)
			{
				return 1;
			}
			aux[i] = temp;
			vis[j] = 0;
		}
	}
	return 0;
}

			
void dfs(int index, int len, int Dlen)
{
	if(index == Dlen + 1)
	{
		
		for(int i = 1; i <= index; i++)
		{
			aux[i] = data[i];
		}
		mmset(vis,0);
		ans += AuxDfs(index);
	}
	else 
	{
		for(int i = data[index] + 1; i <= len; i++)
		{
			data[index + 1] = i;
			dfs(index + 1, len, Dlen);
		}
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			data[0] = 0;
			dfs(0,n,i);
		}
		printf("%d\n",ans);
	}
	 return 0;
}
