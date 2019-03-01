#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 10;
int data[N], data1[N];
int aux[N];
int num[N], mark[N];
int n,m;
int dfs(int p);
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data1[i]);
	}
	mmset(mark,0);
	mmset(aux,0);
	for(int i = 1; i <= n; i++)
	{
		dfs(i);
	}
	sort(aux + 1, aux + 1 + n);
	int sum = 0;
	for(int i = n; i >= n - m; i--)
	{
		sum += aux[i];
	}
	printf("%d\n",sum);
	





	return 0;
}
int dfs(int p)
{
	if(mark[p] == 1)
	{
		return 0;	
	}
	else if(data1[p] == p)
	{
		mark[p] = 1;
		aux[p] += data[p];
		return 0;
	}
	else 
	{
		aux[p] += data[p];
		aux[data1[p]] += aux[p];
		mark[p] = 1;
		dfs(data1[p]);		
		aux[p] = 0;
	}
}
