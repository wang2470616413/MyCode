#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 10;
int data[N], pre[N], n,m;
int mark[N], father[N];
int find(int x)
{
	return father[x] == x ? x : find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&pre[i]);
		merge(i,pre[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n",i,father[i]);
	}


	return 0;
}
