#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5005;
int data[N][2];
int mark[N];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		scanf("%d %d",&a, &b);
		for(int i = a; i <= b; i++)
		{
			mark[i] ++;
		}
		data[i][0] = a, data[i][1] = b;
	}
	int u1, u2;
	int res1 = N + 10,res2 = N + 10;
	for(int i = 1; i <= m; i++)
	{
		int temp = 0;
		for(int j = data[i][0]; j <= data[i][1];j++)
		{
			if(mark[j] == 1)
			{
				temp++;
			}	
		}
		if(res1 > temp)
		{
			res1 = temp;
			u1 = i;
		}
	}
	for(int i = data[u1][0]; i <= data[u1][1]; i++)
	{
		if(mark[i] > 1)
		mark[i]--; 
	}
	for(int i = 1; i <= m; i++)if(i != u1)
	{
		int temp = 0;
		for(int j = data[i][0]; j <= data[i][1];j++)
		{
			if(mark[j] == 1)
			{
				temp++;
			}	
		}
		if(res2 > temp)
		{
			res2 = temp;
			u2 = i;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(mark[i] >= 1)
		{
			ans++;
		}
	}
	printf("%d\n",ans - res1 - res2);




	return 0;
}
