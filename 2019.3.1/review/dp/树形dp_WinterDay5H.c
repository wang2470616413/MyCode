#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
ll res = 0;
vector <int> data[N];
int map1[1010][2];
int mark[N];
int n,m;
void addEdge(int k,int n);
ll dfs(int p);
int main()
{
	scanf("%d %d",&n,&m);
	mmset(mark,0);
	for(int i = 1; i <= n - 1; i++)
	{
		scanf("%d %d",&map1[i][0],&map1[i][1]);
		data[map1[i][0]].push_back(map1[i][1]);
		data[map1[i][1]].push_back(map1[i][0]);
	}
	for(int i = 1; i <= m - 1; i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&c,&b,&d);
		addEdge(i + 1,n);
		data[(a - 1) * n + b].push_back((c - 1) * n + d);
		data[(c - 1) * n + d].push_back((a - 1) * n + b);
	}
	mark[1] = 1;
	dfs(1);
	printf("%lld\n",res % MOD);
	return 0;
}
void addEdge(int k,int n)
{
	for(int i = 1; i <= n - 1; i++)
	{
		data[(k - 1) * n + map1[i][0]].push_back((k - 1) * n + map1[i][1]);
		data[(k - 1) * n + map1[i][1]].push_back((k - 1) * n + map1[i][0]);
	}
}
ll dfs(int p)
{
	ll sum = 1;
	for(int i = 0; i < data[p].size(); i++)if(mark[data[p][i]] == 0) 
	{
		mark[data[p][i]] = 1;
		sum += dfs(data[p][i]);
	}
	res = (res + (sum * (n * m - sum)) % MOD) % MOD;
	return sum;
}
