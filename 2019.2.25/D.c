#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105, M = 200;
struct node
{
	int k,num;
	node()
	{
		k = N;
		num = 0;
	};
	node(int pk,int pnum)
	{
		k = pk;
		num = pnum;
	}
	bool operator < (const node b) const 
	{
		return num > b.num;
	}
};
node data[N];
int n,m;
int count1(int mark);
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(data[a].k > b)
		{
			data[a].k = b;
		}
		data[a].num++;
	}
	for(int i = 1; i <= n; i++)
	{
		int res = count1(i);
		printf("%d ",res);
	}
	printf("\n");

	return 0;
}

